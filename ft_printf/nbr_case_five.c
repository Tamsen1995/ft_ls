/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_case_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:00:39 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 19:00:42 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_added(t_list **lst, int len)
{
	int added;

	added = 0;
	if ((*lst)->width > (*lst)->precision || (*lst)->width > len)
	{
		if ((*lst)->itsazero && (*lst)->precisionthere && \
		(*lst)->precision == 0 && (*lst)->width > 0)
			(*lst)->width++;
		if ((*lst)->precision > len)
			added = (*lst)->width - (*lst)->precision;
		else if ((*lst)->precision < len)
			added = (*lst)->width - len;
	}
	return (added);
}

int			nbr_normal(t_list **lst, char *aff, char *nbr)
{
	int		added;
	int		i;
	int		j;
	int		len;

	nbr_normal0(&len, &i, &j, nbr);
	added = get_added(lst, len);
	added += nbr_normal2(lst, nbr, aff, &i);
	if (nbr[0] == '-' && (*lst)->zero == TRUE)
		nbr_normal3_two(aff, &i, &j, &len);
	nbr_normal4(lst, aff, &i, &added);
	nbr_normal5(lst, &added, nbr, len);
	nbr_normal6(&added, &i, aff);
	if (nbr[0] == '-' && (*lst)->zero == FALSE)
		nbr_normal3_two(aff, &i, &j, &len);
	added += nbr_normal12(lst, nbr, aff, &i);
	nbr_normal7(lst, &added, &len);
	nbr_normal8(aff, &i, &added);
	if ((*lst)->type != 'o' && (*lst)->type != 'O' &&\
		nbr_normal9(lst, aff, &i) == 0)
		nbr_normal10(nbr, aff, &i, &j);
	else if (nbr_normal13(lst, aff, nbr, &i) == 1)
		return (i);
	return (ft_strlen(aff));
}

void		ft_nbr_case_unsigned(t_list **lst, unsigned long long nbr)
{
	char		aff[100];
	char		*ziffer;

	ziffer = ft_itoa_unsigned(nbr);
	if ((*lst)->minus == TRUE)
		(*lst)->result = nbr_justify(lst, aff, ziffer);
	if ((*lst)->minus == FALSE)
		(*lst)->result = nbr_normal(lst, aff, ziffer);
	ft_putstr(aff);
	free(ziffer);
	ziffer = NULL;
	return ;
}

void		ft_nbr_case(t_list **lst, int nbr)
{
	char		*aff;
	char		*ziffer;

	aff = ft_strnew(1000);
	ziffer = ft_itoa(nbr);
	if ((*lst)->minus == TRUE)
		(*lst)->result = nbr_justify(lst, aff, ziffer);
	if ((*lst)->minus == FALSE)
		(*lst)->result = nbr_normal(lst, aff, ziffer);
	ft_putstr(aff);
	free(aff);
	free(ziffer);
	ziffer = NULL;
	aff = NULL;
	return ;
}
