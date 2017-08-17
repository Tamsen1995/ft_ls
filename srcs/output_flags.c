/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:21:21 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 18:21:23 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

T_BOOL			is_hidden_file(t_stack *file)
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
		if ((!is_hidden_file(tmp) || flags[f_hidden]) && tmp->fields)
			total_blk_size = total_blk_size + tmp->fields->st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr((int)total_blk_size);
	ft_putendl("");
}

void			print_flags(t_stack *file, char *flags)
{
	t_stack *tmp;

	tmp = NULL;
	if (!file)
		error_msg("A file is missing in (print_flags)");
	tmp = file;
	if (flags[f_list] && tmp->fields)
		print_list(tmp);
}
