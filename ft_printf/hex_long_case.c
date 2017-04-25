/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_long_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 05:44:43 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 05:44:45 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_hex_x_long_put(unsigned long long quotient, char *hex, int i)
{
	unsigned long long	tmp;

	while (quotient > 0)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 87;
		hex[i++] = tmp;
		quotient = quotient / 16;
	}
	return (i);
}

char		*conv_hex_x_long(t_list **lst, unsigned long long nbr)
{
	char				hex[100];
	char				*ret;
	int					i;
	unsigned long long	quotient;

	i = 0;
	quotient = nbr;
	if (nbr == 0)
	{
		hex[i] = '0';
		i++;
	}
	i = conv_hex_x_long_put(quotient, hex, i);
	if ((*lst)->hashtag == TRUE)
		ret = ft_puthex(lst, hex, i - 1);
	else
		ret = ft_puthex_no0x(hex, i - 1);
	return (ret);
}

void		ft_hex_long_case(t_list **lst, unsigned long long alongone)
{
	char	*aff;
	char	*hex;
	int		len;
	int		added;

	added = 0;
	hex = conv_hex_x_long(lst, alongone);
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
	free(aff);
	aff = NULL;
}
