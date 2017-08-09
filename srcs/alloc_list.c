/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 20:58:30 by tbui              #+#    #+#             */
/*   Updated: 2017/06/17 20:58:37 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// This function receives a name and allocates everything in the the current directory into 
// a nice stack. it then returns this stack
// in the case of it being only a file path we check to see if it's valid and reutrn a list with
// the file's info
t_stack			*register_fls_in_dir(char *name, char *flags)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;

	fls = NULL;
	ent = NULL;

	if (!(dir = opendir(name)))
		error_msg("Could not open directory (register_fls_in_dir)");
	if (!(ent = readdir(dir)))
			error_msg("There was a problem with the reading of an entry in the directory ! (register_fls_in_dir)");
	if (!(fls = ft_lstnew(ent, name, flags)))
		error_msg("The first file of a dir could not be allocated ! (register_fls_in_dir)");
	while (flags[f_nosort] == 0 && (ent = readdir(dir)))
		ft_list_push_back(&fls, ent, name, flags);
	while (flags[f_nosort] == 1 && (ent = readdir(dir)))
		ft_lstadd(&fls, ent, name, flags);
	closedir(dir);
	return (fls);
}

/*
** This function simply check if the current entry's name 
** is neither the current directory nor the previous one
*/
t_bool		not_curr_and_prev(t_stack *entry)
{
	if (ft_strcmp(entry->filename, ".") != 0 && ft_strcmp(entry->filename, "..") != 0)
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
	if (ft_strncmp("/", dir_path, 1) != 0)
		dir_path = ft_strjoin("./", dir_path);
	return (dir_path);
}


t_stack 	*handle_dirs(char *dir_path, char *flags)
{
	t_stack *fls;
	t_stack *tmp;

	fls = NULL;
	tmp = NULL;
	if (!(fls = register_fls_in_dir(dir_path, flags))) // zapping the entire entry list into a stack chain
		error_msg("There was an error in the registering of a file ! (alloc_list)");
	tmp = fls;
	while (tmp)
	{
		if (tmp->next)
			tmp->next->prev = tmp;
		tmp->fields = get_file_info(tmp); // extracting all the info
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			tmp->subdir = handle_dirs(tmp->path, flags); // recursively calling the function again with the newly made path in the stack elem
		tmp = tmp->next;
	}
	return (fls);
}



// This function recursively allocates the entirety of the directory as well as its subdirectories
t_stack			*alloc_list(char *dir_path, char *flags)
{
	t_stack			*fls;
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion
	DIR				*test; // A test directory file to see if I can actually open the dir_path

	tmp = NULL;
	// here I deal with the single file input case
	if (!(test = opendir(dir_path)))
		fls = handle_single_fl(make_dir_path(dir_path), flags);
	else
		fls = handle_dirs(dir_path, flags);
	closedir(test);
	return (fls);
}
