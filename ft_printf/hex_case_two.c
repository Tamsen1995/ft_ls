/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_case_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 08:07:46 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 08:07:48 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hex_case_free(char *hex, char *aff)
{
	free(hex);
	free(aff);
	hex = NULL;
	aff = NULL;
}

char		*ft_puthex_no0x(char *hex, int i)
{
	char *tmp;
	char *ret;

	ret = ft_strnew(100);
	tmp = ret;
	while (i >= 0)
	{
		*tmp = hex[i];
		tmp++;
		i--;
	}
	*tmp = '\0';
	return (ret);
}

void		conv_hex_x_put(unsigned int quotient, char *hex, int *i)
{
	unsigned int tmp;

	while (quotient > 0)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 87;
		hex[(*i)++] = tmp;
		quotient = quotient / 16;
	}
}

void		conv_hex_x_two(unsigned int nbr, char *hex, \
	int *i, unsigned int quotient)
{
	if (nbr == 0)
	{
		hex[(*i)] = '0';
		(*i)++;
	}
	conv_hex_x_put(quotient, hex, i);
}

char		*conv_hex_x(t_list **lst, unsigned int nbr)
{
	char			*hex;
	char			*ret;
	int				i;
	unsigned int	quotient;

	hex = ft_strnew(1100);
	i = 0;
	quotient = nbr;
	conv_hex_x_two(nbr, hex, &i, quotient);
	if ((*lst)->hashtag == TRUE && nbr != 0 && (*lst)->zero == FALSE)
		ret = ft_puthex(lst, hex, i - 1);
	else if ((*lst)->hashtag == TRUE && nbr != 0 && (*lst)->minus == TRUE)
	{
		(*lst)->zero = FALSE;
		ret = ft_puthex(lst, hex, i - 1);
	}
	else if ((*lst)->hashtag == TRUE && (*lst)->zero == TRUE)
		ret = ft_puthex_no0x(hex, i - 1);
	else
		ret = ft_puthex_no0x(hex, i - 1);
	free(hex);
	hex = NULL;
	return (ret);
}
