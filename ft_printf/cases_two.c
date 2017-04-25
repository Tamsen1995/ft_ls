/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:00:34 by tbui              #+#    #+#             */
/*   Updated: 2016/05/16 16:00:37 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_determine2(t_list **lst, va_list *ap)
{
	unsigned long long	alongone;

	ft_determine3(lst, ap);
	ft_determine4(lst, ap);
	if ((*lst)->type == 'X')
	{
		if ((*lst)->ll || (*lst)->ell || (*lst)->j || (*lst)->z)
		{
			alongone = (unsigned long long)va_arg(*ap, unsigned long long);
			ft_cap_hex_case_ll(lst, alongone);
		}
		else
		{
			ft_determine5(lst, ap);
		}
	}
	ft_determine6(lst, ap);
	return ;
}

void		ft_determine5(t_list **lst, va_list *ap)
{
	unsigned int		hex;

	hex = (unsigned int)va_arg(*ap, unsigned int);
	if (hex == 0)
		(*lst)->itsazero = TRUE;
	if ((*lst)->hh == TRUE)
	{
		if (hex > 255)
			hex = hex - 256;
	}
	ft_cap_hex_case(lst, hex);
}

void		ft_determine3(t_list **lst, va_list *ap)
{
	wchar_t wint;
	wchar_t *str;

	if ((*lst)->type == 'S')
	{
		str = va_arg(*ap, wchar_t*);
		wide_char_s(str, lst);
		return ;
	}
	if ((*lst)->type == 'C')
	{
		wint = (wint_t)va_arg(*ap, wchar_t);
		print_wchar(wint, lst);
		return ;
	}
	if ((*lst)->type == '%')
	{
		ft_perc_case(lst);
		return ;
	}
}

void		ft_determine4(t_list **lst, va_list *ap)
{
	unsigned long long	alongone;
	unsigned int		hex;

	if ((*lst)->type == 'x')
	{
		if ((*lst)->ell == TRUE || (*lst)->ll == TRUE || \
		(*lst)->j == TRUE || (*lst)->z == TRUE)
		{
			alongone = va_arg(*ap, unsigned long long);
			ft_hex_long_case(lst, alongone);
			return ;
		}
		else
		{
			hex = (unsigned int)va_arg(*ap, unsigned int);
			if (hex == 0)
				(*lst)->itsazero = TRUE;
			if ((*lst)->hh == TRUE)
			{
				if (hex > 255)
					hex = hex - 256;
			}
			ft_hex_case(lst, hex);
		}
	}
}

void		ft_determine6(t_list **lst, va_list *ap)
{
	char				c;
	wchar_t				widechar;

	if ((*lst)->type == 'c')
	{
		if ((*lst)->ell == TRUE)
		{
			widechar = (wchar_t)va_arg(*ap, wchar_t);
			print_wchar(widechar, lst);
			return ;
		}
		c = va_arg(*ap, int);
		ft_char_case(lst, c);
	}
}
