/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:28:25 by tbui              #+#    #+#             */
/*   Updated: 2017/07/17 16:28:29 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_filetype		get_type_from_path(char *path)
{
	struct stat		buf;
	mode_t			type;

	path = make_dir_path(path);
	lstat(path, &buf);
	type = buf.st_mode;
	free(path);
	if (S_ISDIR(type))
		return (DIRECTORY);
	return (INVALID);
}

/*
** creates a list element for the arguments
** along with all the relevant information
** receives the name of the directory and
** makes its path internally in order to get all the stats
*/

t_args			*ft_new_arg(char *name)
{
	t_args		*argu;

	argu = NULL;
	if (!(argu = (t_args *)malloc(sizeof(t_args) * 1)))
		error_msg("Malloc fail in (ft_new_arg)");
	argu->name = ft_strdup(name);
	argu->path = ft_strdup(make_dir_path(argu->name));
	argu->type = get_type_from_path(argu->path);
	argu->next = NULL;
	argu->prev = NULL;
	lstat(argu->path, &(argu->stats));
	return (argu);
}

/*
** allocates and makes an array with sorted
** arguments to be returned
*/

char			**make_sorted_arr(t_args *tmp, int arr_size)
{
	int		i;
	char	**sorted;

	i = 0;
	sorted = ft_alloc_twod_arr(arr_size);
	while (tmp)
	{
		sorted[i] = ft_strdup(tmp->name);
		tmp = tmp->next;
		i++;
	}
	sorted[i] = NULL;
	return (sorted);
}

/*
** sorts the arguments with
** the help of linked lists
*/

char			**sort_args(char **av_tmp, char *flags)
{
	int			i;
	t_args		*begin;
	t_args		*tmp;
	char		**sorted;

	i = 0;
	sorted = NULL;
	tmp = NULL;
	if (!av_tmp[i])
		return (av_tmp);
	begin = ft_new_arg(av_tmp[i]);
	i = 1;
	while (av_tmp[i])
	{
		ft_args_push_back(&begin, av_tmp[i], flags);
		i++;
	}
	tmp = begin;
	sorted = make_sorted_arr(tmp, i);
	return (sorted);
}
