/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:57:03 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 17:57:06 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			free_list(t_stack *list, char *flags)
{
	t_stack *tmp;

	tmp = NULL;
	if (!list)
		error_msg("Error in the freeing of the list");
	tmp = list;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY \
		&& directory_no_access(tmp) == FALSE \
		&& flags[f_recur] == 1)
			free_list(tmp->subdir, flags);
		free_list_elem(tmp);
	}
	free(list);
	return ;
}
