/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:56:50 by tbui              #+#    #+#             */
/*   Updated: 2017/07/17 16:56:51 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_bool			is_hidden_file(t_stack *file)
{
	if (!file || !file->filename || !file->filename[0])
		error_msg("Error in (is_hidden_file)");
	if (file->filename[0] == '.')
		return (TRUE);
	return (FALSE);
}

void			print_list(t_stack *file)
{
	ft_putstr(file->fields->mode);
	ft_putstr("\t");
	ft_putstr(file->fields->links);
	ft_putstr("\t");
	ft_putstr(file->fields->owner);
	ft_putstr("\t");
	ft_putstr(file->fields->group);
	ft_putstr("\t");
	ft_putstr(file->fields->size);
	ft_putstr("\t");
	ft_putstr(file->fields->date);
	ft_putstr("\t");
}

void			print_flags(t_stack *file, char *flags)
{
	t_stack *tmp;

	tmp = NULL;
	if (!file)
		error_msg("A file is missing in (print_flags)");
	tmp = file;
	if (flags[f_list])
		print_list(tmp);
}

void			print_dir(t_stack *files, char *flags)
{
	t_stack *tmp;

	tmp = files;
	while (tmp)
	{
		if (!is_hidden_file(tmp))
		{
			print_flags(tmp, flags);
			ft_putendl_col(tmp);
		}
		if (is_hidden_file(tmp) && flags[f_hidden])
		{
			print_flags(tmp, flags);
			ft_putendl_col(tmp);
		}
		tmp = tmp->next;
	}
}

void			print_total_blocks(t_stack *file, char *flags)
{
	t_stack			*tmp;
	long long int	total_blk_size;

	total_blk_size = 0;
	tmp = file->subdir;
	if (!flags[f_recur])
		tmp = file;
	while (tmp)
	{
		if (!is_hidden_file(tmp) || flags[f_hidden])
			total_blk_size = total_blk_size + tmp->fields->st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr((int)total_blk_size);
	ft_putendl("");
}

void			print_dir_path_recur(t_stack *file, char *flags)
{
	ft_putendl("");
	ft_putendl("");
	ft_putstr(file->path);
	ft_putendl(":");
	if (flags[f_list])
		print_total_blocks(file, flags);
}

void			out_entire_stack(t_stack *stack, char *flags)
{
	t_stack *tmp;

	tmp = NULL;
	tmp = stack;
	print_dir(tmp, flags);
	while (tmp)
	{
		while (is_hidden_file(tmp) && !flags[f_hidden])
			tmp = tmp->next;
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			print_dir_path_recur(tmp, flags);
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			out_entire_stack(tmp->subdir, flags);
		tmp = tmp->next;
	}
}

void			output_module(t_stack *files, char *flags)
{
	if (!files)
		return ;
	if (flags[f_recur])
		out_entire_stack(files, flags);
	else
	{
		if (flags[f_list] && files->type == DIRECTORY)
			print_total_blocks(files, flags);
		print_dir(files, flags);
	}
}
