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

int			stack_sorting(t_stack *s1, t_stack *s2)
{
	if (s1->type == INVALID && s2->type != INVALID)
		return (-1);
	if (s1->type != INVALID && s2->type == INVALID)
		return (1);

	// INVALIDness overrides everything
	// rev overrides everything in the sense that it cooperates with the given conditions
	

	
	return (ft_strcmp(s1->filename, s2->filename));

}

// I need to do the sorting here 
void		ft_list_push_back(t_stack **begin_list, struct dirent *ent, char *path)
{
	t_stack *cur;
	t_stack *prev;
	t_stack *new;

	new = ft_lstnew(ent, path);
	cur = *begin_list;
	prev = NULL;
	if (!cur)
	{
		cur = ft_lstnew(ent, path);
		return ;
	}
	while (cur && stack_sorting(cur, new) <= 0)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
}
