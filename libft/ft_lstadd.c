/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:01:39 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 22:01:57 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_list_push_back(t_stack **begin_list, struct dirent *ent, char *path)
{
	t_stack *list;

	list = *begin_list;
	if (!list)
		list = ft_lstnew(ent, path);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(ent, path);
	}
}
