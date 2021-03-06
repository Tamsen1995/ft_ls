/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:05:18 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 19:07:05 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** This function pushes a list element to the end of the list
** Without sorting it
** is only used if the f flag has been activated
*/

void		ft_lstadd(t_stack **begin_list, \
struct dirent *ent, char *path, char *flags)
{
	t_stack *tmp;
	t_stack *new;

	tmp = NULL;
	new = ft_lstnew(ent, path, flags);
	if (!*begin_list)
	{
		*begin_list = ft_lstnew(ent, path, flags);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
