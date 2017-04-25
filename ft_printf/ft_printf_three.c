/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:45:16 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 21:45:18 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_manage4(t_list *lst, const char *str, int *i, int *j)
{
	int fuggit;
	int n;

	fuggit = 100;
	while (fuggit > 0)
	{
		n = check_flags(str, &lst, *i);
		(*i) += n;
		(*j) = (*j) + n;
		n = check_flags2(str, &lst, *i);
		(*i) += n;
		(*j) = (*j) + n;
		fuggit--;
	}
}

void			ft_manage5(t_list *lst, int *added)
{
	if ((*lst).minus == FALSE && (*lst).zero == FALSE)
	{
		while ((*added) < (*lst).width - 1)
		{
			ft_putchar(' ');
			(*added)++;
		}
	}
}
