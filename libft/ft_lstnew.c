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
	alist->type = ent->d_type;
	alist->path = NULL;
	alist->next = NULL;
	alist->fields = NULL;
	return (alist);
}
