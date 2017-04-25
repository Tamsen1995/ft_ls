/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ordered.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:40:02 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:45:22 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		stack_push_ordered(t_stack **head, t_stack *new, char *flags)
{
	t_stack		*prev;
	t_stack		*cur;

	if (!*head)
	{
		*head = new;
		return ;
	}
	cur = *head;
	if (sort_stack(cur, new, flags) > 0)
	{
		new->next = cur;
		*head = new;
		return ;
	}
	while (cur && sort_stack(cur, new, flags) <= 0)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
}

int			sort_stack(t_stack *s1, t_stack *s2, char *flags)
{
	if (s1->type == INVALID && s2->type != INVALID)
		return (-1);
	if (s1->type != INVALID && s2->type == INVALID)
		return (1);
	if (flags[f_time] && s1->type != INVALID && s2->type != INVALID &&
			s1->stats.st_mtimespec.tv_sec != s2->stats.st_mtimespec.tv_sec)
	{
		if (flags[f_rev])
		{
			return (s1->stats.st_mtimespec.tv_sec
				- s2->stats.st_mtimespec.tv_sec);
		}
		return (s2->stats.st_mtimespec.tv_sec - s1->stats.st_mtimespec.tv_sec);
	}
	if (flags[f_rev] && s1->type != INVALID && s2->type != INVALID)
		return (ft_strcmp(s2->filename, s1->filename));
	return (ft_strcmp(s1->filename, s2->filename));
}
