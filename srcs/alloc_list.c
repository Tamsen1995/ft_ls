/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 20:58:30 by tbui              #+#    #+#             */
/*   Updated: 2017/08/21 21:51:24 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** This function receives a name and allocates
** everything in the the current directory into
** a nice stack. it then returns this stack
** in the case of it being only a file path we
** check to see if it's valid and reutrn a list with
** the file's info
*/

t_stack			*register_fls_in_dir(char *name, char *flags)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;

	fls = NULL;
	ent = NULL;
	if (!(dir = opendir(name)))
		return (fls);
	if (!(ent = readdir(dir)))
		error_msg("Err: readdir (register_fls_in_dir)");
	if (!(fls = ft_lstnew(ent, name, flags)))
		error_msg("Err: lstnew (register_fls_in_dir)");
	while (flags[f_nosort] == 0 && (ent = readdir(dir)))
	{
		if (ft_strncmp(ent->d_name, ".", 1) != 0 || flags[f_hidden])
			ft_list_push_back(&fls, ent, name, flags);
	}
	while (flags[f_nosort] == 1 && (ent = readdir(dir)))
	{
		if (ft_strncmp(ent->d_name, ".", 1) != 0 || flags[f_hidden])
			ft_lstadd(&fls, ent, name, flags);
	}
	closedir(dir);
	return (fls);
}

/*
** This function simply checks if the current entry's name
** is neither the current directory nor the previous one
*/

T_BOOL			not_curr_and_prev(t_stack *entry)
{
	if (ft_strcmp(entry->filename, ".") != 0 && \
		ft_strcmp(entry->filename, "..") != 0)
		return (TRUE);
	return (FALSE);
}

/*
** This function takes in a dir_path and checks too see if it starts with "/"
** If this is the case it will not concatenate the "./"
** onto the beginning of the path, as a folder which starts with "/"
** Is not a folder in the current directory
*/

char			*make_dir_path(char *dir_path)
{
	if (ft_strncmp("/", dir_path, 1) != 0 && \
	ft_strncmp("./", dir_path, 2) != 0)
		dir_path = ft_strjoin("./", dir_path);
	return (dir_path);
}

/*
** This function recursively allocates
** the entire current directory as well as its subdirectories
*/

t_stack			*handle_dirs(char *dir_path, char *flags)
{
	t_stack *fls;
	t_stack *tmp;

	fls = NULL;
	if (!(fls = register_fls_in_dir(dir_path, flags)))
		return (fls);
	tmp = fls;
	print_dir(tmp, flags);
	while (tmp)
	{
		if (tmp->next)
			tmp->next->prev = tmp;
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY  \
		&& flags[f_recur] == 1)
		{
			print_dir_path_recur(tmp, flags);
			tmp->subdir = handle_dirs(tmp->path, flags);
		}
		tmp = tmp->next;
	}
	return (fls);
}

/*
** This function redirects to either the handle directory function,
** or the singel input function
*/

t_stack			*alloc_list(char *dir_path, char *flags)
{
	t_stack			*fls;
	t_stack			*tmp;
	DIR				*test;

	tmp = NULL;
	if (!(test = opendir(dir_path)))
		fls = handle_single_fl(make_dir_path(dir_path), flags);
	else
	{
		if (flags[f_list])
			print_total_blocks(dir_path, flags);
		fls = handle_dirs(dir_path, flags);
		closedir(test);
	}
	return (fls);
}
