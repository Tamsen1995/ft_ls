/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_case_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:00:32 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 19:00:34 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			nbr_normal13(t_list **lst, char *aff, char *nbr, int *i)
{
	int j;

	j = 0;
	if (nbr[0] == '-' && (*lst)->zero == TRUE)
		j++;
	if (nbr[0] == '-' && (*lst)->zero == FALSE)
		j++;
	if ((*lst)->type == 'o' || (*lst)->type == 'O')
	{
		if ((*lst)->precisionthere == TRUE &&\
		(*lst)->itsazero == TRUE && (*lst)->hashtag == FALSE)
		{
			aff[(*i)] = '\0';
			return (1);
		}
		while (nbr[j] != '\0')
			aff[(*i)++] = nbr[j++];
		aff[(*i)] = '\0';
	}
	return (0);
}

void		nbr_normal0(int *len, int *i, int *j, char *nbr)
{
	(*len) = ft_strlen(nbr);
	(*i) = 0;
	(*j) = 0;
}

void		ft_nbr_case_ll(t_list **lst, signed long long nbr)
{
	char		aff[100];
	char		*ziffer;

	ziffer = ft_itoa_ll(nbr);
	if ((*lst)->minus == TRUE)
		(*lst)->result = nbr_justify(lst, aff, ziffer);
	if ((*lst)->minus == FALSE)
		(*lst)->result = nbr_normal(lst, aff, ziffer);
	free(ziffer);
	ziffer = NULL;
	ft_putstr(aff);
	return ;
}
