/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:34:51 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 22:34:53 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_check_width_three(const char *str, t_list **lst,\
int *star, int *i)
{
	if ((*star) == 0 && str[(*i) + 1] != '.')
		(*star) = ft_atoi(str + (*i) + 1);
	else if ((*star) < 0)
	{
		(*star) = (*star) * (-1);
		(*lst)->minus = TRUE;
	}
}

void			ft_check_width_four(t_list **lst, const char *str, int *i)
{
	if ((*lst)->width == 0)
		(*lst)->width = ft_atoi(str + (*i));
}

void			ft_check_width_five(int *skip, int *i)
{
	(*skip)++;
	(*i)++;
}

void			ft_check_width_six(const char *str, t_list **lst, \
int *i, int *skip)
{
	(*i)++;
	(*lst)->width = ft_atoi(str + (*i));
	(*skip)++;
}

int				check_width(va_list *ap, const char *str, int i, t_list **lst)
{
	int skip;
	int star;
	int j;

	skip = 0;
	j = i;
	check_width_two(str, &j, &skip, &i);
	if (str[i] == '*')
	{
		if (ft_isdigit(str[i + 1]) == 1)
		{
			ft_check_width_six(str, lst, &i, &skip);
			star = va_arg(*ap, int);
		}
		else
		{
			star = va_arg(*ap, int);
			ft_check_width_three(str, lst, &star, &i);
			(*lst)->width = star;
		}
	}
	ft_check_width_four(lst, str, &i);
	while (ft_isdigit(str[i]) || str[i] == '*')
		ft_check_width_five(&skip, &i);
	return (skip);
}
