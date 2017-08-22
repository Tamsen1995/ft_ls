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

/*
** prints dir paths for the recursion module
** as the paths have to be shown before listing the
** dirs contents
*/

void			print_dir_path_recur(t_stack *file, char *flags)
{
	DIR *dir;

	dir = NULL;
	ft_putendl("");
	ft_putendl("");
	ft_putstr(file->path);
	ft_putendl(":");
	if (flags[f_list] && path_no_access(file) == FALSE)
		print_total_blocks(file->path, flags);
	if (path_no_access(file) == TRUE || !(dir = opendir(file->path)))
		perm_denied(file);
	if (dir)
		closedir(dir);
}
