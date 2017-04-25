/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap_hex_case_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 22:46:24 by tbui              #+#    #+#             */
/*   Updated: 2016/05/08 22:46:27 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_ert_put_ll(unsigned long long nbr, char *hex, int i)
{
	unsigned long long	quotient;
	unsigned long long	tmp;

	quotient = nbr;
	while (quotient > 0)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 55;
		hex[i++] = tmp;
		quotient = quotient / 16;
	}
	return (i);
}

char	*conv_hex_x_cap_ll(t_list **lst, unsigned long long nbr)
{
	char					*hex;
	char					*ret;
	int						i;

	hex = ft_strnew(4200);
	i = 0;
	if (nbr == 0)
	{
		hex[i] = '0';
		i++;
	}
	i = conv_ert_put_ll(nbr, hex, i);
	if ((*lst)->hashtag == TRUE)
		ret = ft_puthex(lst, hex, i - 1);
	else
		ret = ft_puthex_no0x(hex, i - 1);
	free(hex);
	hex = NULL;
	return (ret);
}

void	ft_cap_hex_case_ll(t_list **lst, unsigned long long dec)
{
	char	*aff;
	char	*hex;
	int		len;
	int		added;

	added = 0;
	hex = conv_hex_x_cap_ll(lst, dec);
	len = (int)ft_strlen(hex);
	if ((*lst)->width >= len)
	{
		added = (*lst)->width - len;
		aff = ft_strnew((*lst)->width);
	}
	else
		aff = ft_strnew(len);
	if ((*lst)->minus == FALSE)
		ft_hex_normal(lst, hex, aff, added);
	if ((*lst)->minus == TRUE)
		ft_hex_justify(lst, hex, aff, added);
	ft_putstr(aff);
	free(hex);
	free(aff);
	aff = NULL;
	hex = NULL;
}
