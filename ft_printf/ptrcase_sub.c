/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrcase_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 02:54:05 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 02:54:09 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		hex_show_norm(t_list **lst, char *str, int *len)
{
	if ((*lst)->minus == TRUE)
		ft_putstr(str);
	if ((*lst)->zero == TRUE && (*lst)->precisionthere == FALSE \
		&& (*lst)->width > (*len) && (*lst)->type == 'p')
		ft_putstr("0x");
}

int			conv_ert_hex_put(unsigned long long quotient, char *hex, int i)
{
	unsigned long long		tmp;

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
	hex[i] = '\0';
	return (i);
}

void		ft_puthex_two(t_list **lst, char *tmp, int i, char *hex)
{
	while (i >= 0 && (*lst)->itsazero == FALSE)
	{
		*tmp = hex[i];
		tmp++;
		i--;
	}
	if ((*lst)->itsazero == TRUE)
	{
		*tmp = '0';
		tmp++;
	}
	if ((*lst)->precisionthere == TRUE && (*lst)->precision == 0)
		tmp--;
	*tmp = '\0';
}

char		*ft_puthex_zero(t_list **lst, char *tmp)
{
	if ((*lst)->zero == FALSE ||\
		((*lst)->type == 'p' && (*lst)->itsazero == FALSE))
	{
		*tmp = '0';
		tmp++;
	}
	if ((*lst)->type == 'X')
	{
		*tmp = 'X';
		tmp++;
	}
	if (((*lst)->zero == FALSE && (*lst)->type != 'X')\
		|| ((*lst)->type == 'p' && (*lst)->itsazero == FALSE))
	{
		*tmp = 'x';
		tmp++;
	}
	return (tmp);
}
