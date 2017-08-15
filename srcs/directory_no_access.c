/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_no_access.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:23:09 by tbui              #+#    #+#             */
/*   Updated: 2017/08/15 21:23:10 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Checks to see if the file is a directory and
** the access permissions for the current user
** are restricted
*/

t_bool			directory_no_access(t_stack *elem)
{
	DIR			*dir;
	t_stack		*tmp;

	tmp = NULL;
	dir = NULL;
	tmp = elem;
	if (!(dir = opendir(tmp->path)) && tmp->type == DIRECTORY)
		return (TRUE);
	if (dir)
		closedir(dir);
	return (FALSE);
}
