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


// I need to do the sorting here 
void	ft_list_push_back(t_stack **begin_list, struct dirent *ent, char *path)
{
	t_stack *cur;
	t_stack *prev;

	prev = NULL;
	cur = *begin_list;
	if (!cur)
	{
		cur = ft_lstnew(ent, path);
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = ft_lstnew(ent, path);
}
