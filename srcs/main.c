/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:05:47 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 17:50:42 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			print_valid_fls(char **av_tmp, int ac)
{
	int			i;
	DIR			*dir;
	struct stat buf;
	char		*path;

	i = 1;
	path = NULL;
	while (i < ac && av_tmp[i])
	{
		path = ft_strjoin("./", av_tmp[i]);
		if (!(dir = opendir(av_tmp[i])) && lstat(path, &buf) == 0)
			ft_putendl(av_tmp[i]);
		i++;
		free(path);
	}
	if (dir)
		closedir(dir);
}

void			free_list_elem(t_stack *tmp)
{
	free(tmp->path);
	free(tmp->filename);
	free(tmp->fields->links);
	free(tmp->fields->size);
	free(tmp->fields->date);
	free(tmp->fields);
	free(tmp);
}

void			print_dir_name(char *dir_path, char **av_tmp)
{
	DIR		*dir;
	int		i;

	i = 0;
	if (av_tmp)
	{
		while (av_tmp[i])
			i++;
		if ((dir = opendir(dir_path)) && i > 1)
		{
			ft_putendl("");
			ft_putstr(dir_path);
			ft_putendl(":");
		}
		if (dir)
			closedir(dir);
	}
}

/*
** This is the part of the ls which
** takes over when several directories
** are put as input
*/

char			*ls_loop(int ac, char **av_tmp, char *flags)
{
	int			i;
	t_stack		*files;
	char		*dir_path;

	i = 0;
	dir_path = NULL;
	files = NULL;
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strdup(av_tmp[i]);
		files = alloc_list(dir_path, flags);
		print_dir_name(dir_path, av_tmp);
		output_module(files, flags);
		free(av_tmp[i]);
		free_list(files);
		free(dir_path);
		i++;
	}
	return (dir_path);
}

/*
** in the main function the flags are initiated
** and the flow is directed either to the module which
** handles several directories, or
** the part which takes care of only the base dir
*/

int				main(int ac, char **av)
{
	char		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	char		*dir_path;
	char		**av_tmp;

	av++;
	ac--;
	av_tmp = copy_args(ac, av);
	i = parse_flags(ac, av_tmp, flags);
	av_tmp = check_args_for_dirs(av_tmp, i, ac);
	av_tmp = sort_args(av_tmp);
	dir_path = ls_loop(ac, av_tmp, flags);
	if (dir_path == NULL)
	{
		files = alloc_list(".", flags);
		output_module(files, flags);
		free_list(files);
	}
	free(av_tmp);
	return (0);
}
