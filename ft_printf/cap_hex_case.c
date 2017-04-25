/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap_hex_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 22:29:43 by tbui              #+#    #+#             */
/*   Updated: 2016/05/08 22:29:54 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_ert_put(unsigned int nbr, char *hex, int i)
{
	unsigned int	quotient;
	unsigned int	tmp;

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

char	*conv_hex_x_cap(t_list **lst, unsigned int nbr)
{
	char			hex[100];
	char			*ret;
	int				i;

	i = 0;
	if (nbr == 0)
	{
		hex[i] = '0';
		i++;
	}
	i = conv_ert_put(nbr, hex, i);
	if ((*lst)->hashtag == TRUE && (*lst)->itsazero == FALSE)
		ret = ft_puthex(lst, hex, i - 1);
	else
		ret = ft_puthex_no0x(hex, i - 1);
	return (ret);
}

void	ft_cap_hex_case(t_list **lst, unsigned int dec)
{
	char	*aff;
	char	*hex;
	int		len;
	int		added;

	added = 0;
	hex = conv_hex_x_cap(lst, dec);
	len = (int)ft_strlen(hex);
	if ((*lst)->precision > len)
		len = (*lst)->precision;
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
	ft_hex_case_free(hex, aff);
}
