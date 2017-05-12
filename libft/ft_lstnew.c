/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:07:58 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 21:33:51 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// this function creates a path out of the directory name and the file name for the
// stat function
char		*make_path_fl(char *dir, char *file)
{

	

	ft_putendl(dir);
	ft_putendl(file);


	return (NULL); // returning null for now
}


// This function takes in an entry in the directory stream and the path of the directory
// itself and then returns a stack elem which contains all its necessary information
t_stack		*ft_lstnew(struct dirent *ent, char *path)
{
	t_stack	*alist;
	struct stat fstat;
	char *nw_path;


	// TODO  implement a function concatenates a path together into the nw_path
//	nw_path = make_path_fl(path, ent->d_name);
//	if (stat(nw_path, &fstat) < 0)
//		return (NULL);
	if (!(alist = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);



	// put the file name into the list

	alist->filename = ft_strdup(ent->d_name);

/*	alist->next = NULL;
	alist->prev = NULL;
	alist->mtime = fstat.st_mtime;
	alist->st_mode = fstat.st_mode;
	alist->st_nlink = fstat.st_nlink;
	alist->st_uid = fstat.st_uid;
	alist->st_gid = fstat.st_gid;
	alist->st_size = fstat.st_size;
	alist->st_ino = fstat.st_ino;
	alist->st_blocks = fstat.st_blocks;
	alist->ent = ent;
	alist->file_name = ft_memalloc(ft_strlen(ent->d_name) + 1);
	ft_strcpy(alist->file_name, ent->d_name);




	if (alist->ent->d_type == DT_DIR)
	{
		alist->dir_path = ft_memalloc(ft_strlen(nw_path) + 1);
		ft_strcpy(alist->dir_path, nw_path);
	}

	free(nw_path);

	*/
	return (alist);
}
