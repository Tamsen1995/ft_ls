/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:51:30 by tbui              #+#    #+#             */
/*   Updated: 2016/05/06 15:51:41 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*unsigned_itoa(unsigned int n)
{
	char			*str;
	unsigned int	save;
	unsigned int	i;

	save = n;
	i = 1;
	while (n /= 10)
		i++;
	str = ft_strnew(i);
	str[i--] = '\0';
	str[i--] = 1 * (save % 10) + 48;
	while (save /= 10)
		str[i--] = 1 * (save % 10) + 48;
	return (str);
}

void		unsigned_nbr_case(t_list **lst, unsigned int nbr)
{
	char *aff;
	char *ziffer;

	aff = ft_strnew(1000);
	ziffer = unsigned_itoa(nbr);
	if ((*lst)->minus == TRUE)
		(*lst)->result = nbr_justify(lst, aff, ziffer);
	if ((*lst)->minus == FALSE)
		(*lst)->result = nbr_normal(lst, aff, ziffer);
	free(ziffer);
	ziffer = NULL;
	ft_putstr(aff);
	free(aff);
	aff = NULL;
	return ;
}
