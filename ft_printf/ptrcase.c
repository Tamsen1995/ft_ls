/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrcase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 02:06:13 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 02:06:16 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_puthex(t_list **lst, char *hex, int i)
{
	char		*tmp;
	char		*ret;
	int			j;
	int			len;

	ret = ft_strnew(100);
	tmp = ret;
	j = 0;
	len = ft_strlen(hex);
	tmp = ft_puthex_zero(lst, tmp);
	while ((*lst)->precision > len && j < ((*lst)->precision - len))
	{
		*tmp = '0';
		j++;
		tmp++;
	}
	ft_puthex_two(lst, tmp, i, hex);
	return (ret);
}

char		*conv_hex(t_list **lst, unsigned long long ptr)
{
	char				*hex;
	char				*ret;
	int					i;
	unsigned long long	quotient;

	hex = ft_strnew(1200);
	if (ptr == 0)
		(*lst)->itsazero = TRUE;
	i = 0;
	quotient = ptr;
	if (ptr == 0)
	{
		hex[i] = '0';
		i++;
	}
	i = conv_ert_hex_put(quotient, hex, i);
	ret = ft_puthex(lst, hex, i - 1);
	free(hex);
	hex = NULL;
	return (ret);
}

int			hex_show(t_list **lst, char *str, int width)
{
	int		len;
	int		spaces;
	int		i;

	i = 0;
	spaces = 0;
	len = ft_strlen(str);
	hex_show_norm(lst, str, &len);
	if (len < width)
	{
		spaces = width - len;
		if ((*lst)->zero == TRUE && (*lst)->width > len)
			spaces = spaces - 2;
		if (i < spaces && (*lst)->zero == FALSE)
			i = put_spaces(spaces);
		if (i < spaces && (*lst)->zero == TRUE)
			i = put_zeros(spaces);
	}
	if ((*lst)->minus == FALSE)
		ft_putstr(str);
	if ((*lst)->zero == TRUE && (*lst)->type == 'p' \
		&& (*lst)->precisionthere == FALSE && (*lst)->width > len)
		return (len + spaces + 2);
	return (len + spaces);
}

void		ft_ptr_case(t_list **lst, unsigned long long ptr)
{
	int			width;
	char		*str;

	width = (*lst)->width;
	str = conv_hex(lst, ptr);
	(*lst)->result = hex_show(lst, str, width);
	free(str);
	str = NULL;
	return ;
}
