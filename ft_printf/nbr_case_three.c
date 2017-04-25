/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_case_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:00:19 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 19:00:21 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		nbr_normal7(t_list **lst, int *added, int *len)
{
	if ((*lst)->precision > (*len))
		(*added) = (*lst)->precision - (*len);
}

void		nbr_normal8(char *aff, int *i, int *added)
{
	while ((*added) > 0)
	{
		aff[(*i)++] = '0';
		(*added)--;
	}
}

int			nbr_normal9(t_list **lst, char *aff, int *i)
{
	int flag;

	flag = 0;
	if ((*lst)->precisionthere == TRUE && (*lst)->itsazero == TRUE && \
	(*lst)->zero == FALSE && (*lst)->type != 'o' && (*lst)->type != 'O')
	{
		if ((*lst)->precision > 0)
			aff[(*i)++] = '0';
		aff[(*i)] = '\0';
		flag = 1;
	}
	return (flag);
}

void		nbr_normal10(char *nbr, char *aff, int *i, int *j)
{
	while (nbr[(*j)] != '\0')
		aff[(*i)++] = nbr[(*j)++];
	aff[(*i)] = '\0';
}

int			nbr_normal12(t_list **lst, char *nbr, char *aff, int *i)
{
	int added;

	added = 0;
	if ((*lst)->plus == TRUE && nbr[0] != '-' && (*lst)->zero == FALSE && \
	(*lst)->type != 'o' && (*lst)->type != 'O')
	{
		aff[(*i)++] = '+';
		added--;
	}
	return (added);
}
