/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:53:18 by tbui              #+#    #+#             */
/*   Updated: 2016/05/06 18:53:26 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		count_wide_chars(t_list **lst, wchar_t *string, int *length)
{
	int					i;
	size_t				total_bytes;
	int					add;
	unsigned long		precision;

	precision = (unsigned long)(*lst)->precision;
	i = 0;
	add = 0;
	total_bytes = 0;
	while (i < *length)
	{
		if (string[i] <= 0x7F)
			add = 1;
		else
			count_wide_charss(string, i, &add);
		if ((*lst)->precisionthere == TRUE && (total_bytes + add) > precision)
			break ;
		total_bytes += add;
		i++;
	}
	*length = i;
	return (total_bytes);
}

void		count_wide_charss(wchar_t *string, int i, int *add)
{
	if (string[i] <= 0x7FF)
		(*add) = 2;
	else if (string[i] <= 0xFFFF)
		(*add) = 3;
	else if (string[i] <= 0x10FFFF)
		(*add) = 4;
}

size_t		ft_strlen_wide(const wchar_t *original)
{
	const wchar_t	*end;

	end = original;
	while (*end != L'\0')
		end++;
	return (end - original);
}

int			wide_char_ss(wchar_t *string, t_list **lst, int *k, int len)
{
	int i;
	int totoct;

	i = 0;
	totoct = count_wide_chars(lst, string, &len);
	if ((*lst)->minus == FALSE && (*lst)->width > totoct)
	{
		if ((*lst)->zero == FALSE)
			(*k) = (*k) + put_spaces((*lst)->width - totoct);
		if ((*lst)->zero == TRUE)
			(*k) = (*k) + put_zeros((*lst)->width - totoct);
		(*lst)->result = (*lst)->result + (*k);
	}
	while (i < len)
	{
		print_wint(string[i], lst);
		i++;
	}
	return (totoct);
}

void		wide_char_s(wchar_t *string, t_list **lst)
{
	int totoct;
	int len;
	int k;

	k = 0;
	if (string == NULL)
	{
		(*lst)->result = (*lst)->result + 6;
		ft_putstr("(null)");
		return ;
	}
	len = ft_strlen_wide(string);
	totoct = wide_char_ss(string, lst, &k, len);
	if ((*lst)->minus == TRUE && (*lst)->width > totoct)
	{
		if ((*lst)->zero == FALSE)
			k = k + put_spaces((*lst)->width - totoct);
		while ((*lst)->zero == TRUE)
			k = k + put_zeros((*lst)->width - totoct);
		(*lst)->result = (*lst)->result + k;
	}
	return ;
}
