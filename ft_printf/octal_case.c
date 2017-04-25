/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 07:22:42 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 07:22:44 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_octal(unsigned long long quotient, int *i)
{
	char					*octalreversed;
	unsigned long long		support;

	octalreversed = ft_strnew(1000);
	while (quotient > 0)
	{
		support = quotient % 8;
		octalreversed[(*i)++] = support + 48;
		quotient = quotient / 8;
	}
	octalreversed[(*i)] = '\0';
	return (octalreversed);
}

void		octal_nbr_case(t_list **lst, unsigned long long nbr)
{
	unsigned long long		quotient;
	char					*octal;
	int						i;
	int						j;
	char					*octalreversed;

	i = 0;
	j = 0;
	octal = ft_strnew(1200);
	quotient = nbr;
	octalreversed = get_octal(quotient, &i);
	i--;
	if ((*lst)->hashtag == TRUE && (*lst)->itsazero == FALSE)
		octal[j++] = '0';
	while (i != -1)
		octal[j++] = octalreversed[i--];
	if (nbr == 0)
		octal[j++] = '0';
	octal[j] = '\0';
	free(octalreversed);
	octalreversed = NULL;
	octal_nbr_choose(lst, octal);
	free(octal);
	octal = NULL;
}

void		octal_nbr_choose(t_list **lst, char *octal)
{
	char *aff;

	aff = ft_strnew(1000);
	if ((*lst)->precision > 1000)
		aff = ft_strnew((*lst)->precision + 100);
	if ((*lst)->width > 1000)
		aff = ft_strnew((*lst)->width + 100);
	if ((*lst)->minus == TRUE)
		(*lst)->result = nbr_justify(lst, aff, octal);
	if ((*lst)->minus == FALSE)
		(*lst)->result = nbr_normal(lst, aff, octal);
	ft_putstr(aff);
	free(aff);
	aff = NULL;
}
