/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:49:32 by tbui              #+#    #+#             */
/*   Updated: 2016/05/16 17:49:34 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_determine_two(t_list **lst, va_list *ap)
{
	char *str;

	if ((*lst)->type == 's')
	{
		if ((*lst)->ell == TRUE)
		{
			wide_char_s(va_arg(*ap, wchar_t*), lst);
			return ;
		}
		str = (char *)va_arg(*ap, char *);
		if (!str && (*lst)->precisionthere == FALSE)
		{
			ft_putstr("(null)");
			(*lst)->result = 6;
			return ;
		}
		else if (!str && (*lst)->precisionthere == TRUE)
			str = "0";
		ft_str_case(lst, str);
	}
}

void					ft_determine_three(t_list **lst, va_list *ap)
{
	int nbr;

	nbr = (int)va_arg(*ap, int);
	if (nbr > 32767)
		nbr = nbr * (-1);
	else if (nbr < -32768)
		nbr = 32767;
	ft_nbr_case(lst, nbr);
}

void					ft_determine_four(int *support, int *nbr)
{
	int i;

	i = 0;
	(*support) = ((*nbr) + (-128 + 1)) / -128;
	while (i < (*support))
	{
		(*nbr) = (*nbr) + 128;
		i++;
	}
}

void					ft_determine_five(t_list **lst, int *support, int *nbr)
{
	int i;

	i = 0;
	(*support) = ((*nbr) + (128 - 1)) / 128;
	if ((*nbr) == 128 && (*lst)->ell == TRUE)
		return ;
	else if ((*nbr) == 128)
		(*support)++;
	while (i < (*support))
	{
		(*nbr) = (*nbr) - 128;
		i++;
	}
}

void					ft_determine_six(t_list **lst, va_list *ap)
{
	signed long long longone;

	longone = (signed long long)va_arg(*ap, signed long long);
	if (longone > 9223372036854775807)
		longone = longone * (-1);
	ft_nbr_case_ll(lst, longone);
}
