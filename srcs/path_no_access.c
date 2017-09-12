/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_no_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 23:40:10 by tbui              #+#    #+#             */
/*   Updated: 2017/08/17 23:41:27 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

T_BOOL		path_no_access(t_stack *alist)
{
	struct stat buf;

	if (lstat(ft_strjoin(alist->path, "/."), \
	&(buf)) < 0 && errno == EACCES)
		return (TRUE);
	return (FALSE);
}
