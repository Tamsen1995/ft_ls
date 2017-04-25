/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_case_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:00:08 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 19:00:11 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			nbr_normal2(t_list **lst, char *nbr, char *aff, int *i)
{
	int added;

	added = 0;
	if ((*lst)->plus == TRUE && nbr[0] != '-' && (*lst)->zero == TRUE)
	{
		aff[(*i)++] = '+';
		added--;
	}
	if ((*lst)->space && nbr[0] != '-' && !(*lst)->plus && (*lst)->type != 'o')
	{
		aff[(*i)++] = ' ';
		added--;
	}
	return (added);
}

void		nbr_normal3_two(char *aff, int *i, int *j, int *len)
{
	aff[(*i)++] = '-';
	(*j)++;
	(*len) = (*len) - 1;
}

void		nbr_normal4(t_list **lst, char *aff, int *i, int *added)
{
	if ((*lst)->precision <= 0)
	{
		while (*added > 0 && (*lst)->zero == TRUE && (*lst)->hashtag == FALSE)
		{
			aff[(*i)++] = '0';
			(*added)--;
		}
	}
}

void		nbr_normal5(t_list **lst, int *added, char *nbr, int len)
{
	if ((*lst)->plus == TRUE && nbr[0] != '-')
		(*added)--;
	if (nbr[0] == '-' && (*lst)->precisionthere == TRUE &&\
	(*lst)->precision > len)
		(*added)--;
}

void		nbr_normal6(int *added, int *i, char *aff)
{
	while ((*added) > 0)
	{
		aff[(*i)++] = ' ';
		(*added)--;
	}
}
