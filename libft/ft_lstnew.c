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

t_filetype		get_file_type(struct dirent *ent)
{
	if (ent->d_type == DT_REG)
		return (REG);
	if (ent->d_type == DT_BLK)
		return (BLOCK);
	if (ent->d_type == DT_CHR)
		return (CHAR_SP);
	if (ent->d_type == DT_DIR)
		return (DIRECTORY);
	if (ent->d_type == DT_LNK)
		return (SYMLINK);
	if (ent->d_type == DT_SOCK)
		return (SOCK_LINK);
	if (ent->d_type == DT_FIFO)
		return (FIFO);
	return (REG);
}

// This function takes in an entry in the directory stream and the path of the directory
// itself and then returns a stack elem which contains all its necessary information
t_stack		*ft_lstnew(struct dirent *ent, char *path)
{
	t_stack	*alist;
	struct stat fstat;
	char *nw_path;

	if (!(alist = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);

	// put the file name into the list
	alist->filename = ft_strdup(ent->d_name);	
	alist->path = NULL;
	alist->next = NULL;
	alist->fields = NULL;
	alist->type = INVALID;
	alist->type = get_file_type(ent);


	return (alist);
}
