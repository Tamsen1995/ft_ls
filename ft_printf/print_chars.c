/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 03:51:01 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 03:51:03 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_wchar(wint_t wint, t_list **lst)
{
	int size;

	if (wint < 0)
		return (0);
	else if (wint <= 0x7F)
		size = 1;
	else if (wint <= 0x7FF)
		size = 2;
	else if (wint <= 0xFFFF)
		size = 3;
	else if (wint <= 0x10FFFF)
		size = 4;
	else
		return (0);
	print_wint(wint, lst);
	if ((*lst)->type == 'C')
		(*lst)->result = size;
	if ((*lst)->type == 'c' && (*lst)->ell == TRUE)
		(*lst)->result = size;
	return (0);
}

void		print_wint(wint_t wint, t_list **lst)
{
	char str[4];

	if (wint <= 0x7F)
		print_chars(&wint, 1, lst);
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		print_chars(str, 2, lst);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		print_chars(str, 3, lst);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
		print_chars(str, 4, lst);
	}
}

void		print_chars(void *memory, int size, t_list **lst)
{
	write(1, memory, size);
	(*lst)->result = (*lst)->result + size;
	return ;
}

int			put_spaces(int amount)
{
	int i;

	i = 0;
	while (i < amount)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			put_zeros(int amount)
{
	int i;

	i = 0;
	while (i < amount)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}
