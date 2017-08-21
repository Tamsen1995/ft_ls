/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:21:21 by tbui              #+#    #+#             */
/*   Updated: 2017/08/17 23:52:28 by tbui             ###   ########.fr       */
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

/*
** prints the total blocks for the current directory
** insetad of the subdirectory's
*/

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

/*
** This function takes in the path of a directory
** and then iterates over all its contents,
** adding the the block sizes from the
** respective buffers in the process
*/

void			print_total_blocks(t_stack *dir_elem)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*file_path;
	struct stat 	fstat;
	long long int	total_blk_size;

	total_blk_size = 0;
	if (!(dir = opendir(dir_elem->path)))
		error_msg("Could not open directory (print_total_blocks)");
	while ((ent = readdir(dir)))
	{
		file_path = make_path_dir(dir_elem->path, ent->d_name);
		lstat(file_path, &fstat);
		total_blk_size = total_blk_size + fstat.st_blocks;
	}
	ft_putstr("total ");
	ft_putnbr((int)total_blk_size);
	ft_putendl("");
	closedir(dir);
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
