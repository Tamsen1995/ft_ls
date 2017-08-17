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

/*
** prints out the permission error message in
** case a directory could not be accessed 
*/

void			perm_denied(t_stack *file)
{
	ft_putstr("ls: ");
	ft_putstr(file->filename);
	ft_putstr(" ");
	ft_putstr(strerror(errno));
	ft_putendl("");

}

void			print_dir_path_recur(t_stack *file, char *flags)
{
	ft_putendl("");
	ft_putendl("");
	ft_putstr(file->path);
	ft_putendl(":");
	if (flags[f_list] && path_no_access(file) == FALSE) // TODO implement the permission denied thingy
		print_total_blocks(file, flags);
	if (path_no_access(file) == TRUE)
		perm_denied(file);
}

/*
** out_entire_stack outputs the entire stack of elements
** recursively. 
*/

void			out_entire_stack(t_stack *stack, char *flags)
{
	t_stack *tmp;

	tmp = NULL;
	tmp = stack;
	print_dir(tmp, flags);
	while (tmp)
	{
		while (tmp->next && is_hidden_file(tmp) && !flags[f_hidden])
			tmp = tmp->next;
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			print_dir_path_recur(tmp, flags);
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY &&\
		directory_no_access(tmp) == FALSE)
			out_entire_stack(tmp->subdir, flags);
		tmp = tmp->next;
	}
}

void			print_total_blocks_cur(t_stack *file, char *flags)
{
	t_stack			*tmp;
	long long int	total_blk_size;

	total_blk_size = 0;
	tmp = file;
	while (tmp)
	{
		if ((!is_hidden_file(tmp) || flags[f_hidden]) && tmp->fields)
			total_blk_size = total_blk_size + tmp->fields->st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr((int)total_blk_size);
	ft_putendl("");
}

void			output_module(t_stack *files, char *flags)
{
	if (!files)
		return ;
	if (flags[f_recur])
	{
		if (flags[f_list])
			print_total_blocks_cur(files, flags);
		out_entire_stack(files, flags);
	}
	else
	{
		if (flags[f_list] && files->type == DIRECTORY)
			print_total_blocks(files, flags);
		print_dir(files, flags);
	}
}
