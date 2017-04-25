/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:45:06 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 21:45:08 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_manage2(const char *str, int *i, t_list *lst, int *j)
{
	int n;
	int fuggit;

	n = ft_manage3(str, i, lst, j);
	fuggit = 10;
	while (fuggit > 0)
	{
		n = check_flags(str, &lst, *i);
		(*i) += n;
		j = j + n;
		n = check_flags2(str, &lst, *i);
		(*i) += n;
		j = j + n;
		fuggit--;
	}
	n = check_type(str, *i, &lst);
	(*i) += n;
	j = j + n;
	return ;
}

int			ft_manage3(const char *str, int *i, t_list *lst, int *j)
{
	int n;
	int fuggit;

	fuggit = 10;
	while (fuggit > 0)
	{
		n = check_alph(str, &lst, *i);
		(*i) += n;
		j = j + n;
		n = check_alph2(str, &lst, *i);
		(*i) += n;
		j = j + n;
		n = check_alph3(str, &lst, *i);
		(*i) += n;
		j = j + n;
		fuggit--;
	}
	return (n);
}

void		ft_ugly_manage(t_list *lst, int *added, const char *str, int *i)
{
	if ((*lst).minus == FALSE && (*lst).zero == TRUE)
	{
		while ((*added) < (*lst).width - 1)
		{
			ft_putchar('0');
			(*added)++;
		}
	}
	if ((*lst).minus == TRUE)
	{
		ft_putchar(str[*i]);
		(*i)++;
		(*lst).result++;
		while ((*added) < (*lst).width - 1)
		{
			ft_putchar(' ');
			(*added)++;
		}
	}
	(*lst).result += (*added);
}

int			ft_cut_it(t_list *lst, const char *str, int *i, int *added)
{
	if ((*lst).validtype == FALSE)
	{
		ft_manage5(lst, added);
		ft_ugly_manage(lst, added, str, i);
		return (0);
	}
	return (1);
}

void		add_skip(int *i, int n, int *j)
{
	(*i) += n;
	(*j) = (*j) + n;
}
