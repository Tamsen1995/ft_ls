/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_case_six.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:00:48 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 19:00:49 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			nbr_justify_norm1(char *aff, char *nbr, int *temp, int *i)
{
	int len;

	aff[0] = '-';
	(*temp) = ft_atoi(nbr);
	(*temp) = (*temp) * -1;
	len = ft_strlen(nbr);
	(*i)++;
	return (len);
}

int			nbr_justify_norm2(char *nbr, char *aff, int *i, int *j)
{
	int len;

	while (nbr[(*j)] != '\0')
		aff[(*i)++] = nbr[(*j)++];
	aff[(*i)] = '\0';
	len = ft_strlen(aff);
	return (len);
}

void		nbr_justify_norm3(t_list **lst, int len, int *added)
{
	if (len < (*lst)->width)
		(*added) = (*lst)->width - len;
}
