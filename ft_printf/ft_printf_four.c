/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:58:47 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 21:58:49 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_flags(const char *str, t_list **lst, int i)
{
	int skip;

	skip = 0;
	if (str[i] == '#')
	{
		(*lst)->hashtag = TRUE;
		i++;
		skip++;
	}
	if (str[i] == '0')
	{
		(*lst)->zero = TRUE;
		i++;
		skip++;
	}
	if (str[i] == '-')
	{
		(*lst)->minus = TRUE;
		i++;
		skip++;
	}
	return (skip);
}

int			check_flags2(const char *str, t_list **lst, int i)
{
	int skip;

	skip = 0;
	while (str[i] == ' ')
	{
		(*lst)->space = TRUE;
		i++;
		skip++;
	}
	while (str[i] == '+')
	{
		(*lst)->plus = TRUE;
		i++;
		skip++;
	}
	return (skip);
}

void		check_width_two(const char *str, int *j, int *skip, int *i)
{
	while (ft_isdigit(str[(*j)]))
		(*j)++;
	if (str[(*j)] == '*')
	{
		(*skip) = (*skip) + ((*j) - (*i));
		(*i) = (*j);
	}
}

int			ft_write_list(t_list **lst)
{
	(*lst)->hashtag = FALSE;
	(*lst)->zero = FALSE;
	(*lst)->minus = FALSE;
	(*lst)->space = FALSE;
	(*lst)->plus = FALSE;
	(*lst)->ell = FALSE;
	(*lst)->ll = FALSE;
	(*lst)->h = FALSE;
	(*lst)->hh = FALSE;
	(*lst)->j = FALSE;
	(*lst)->z = FALSE;
	(*lst)->itsazero = FALSE;
	(*lst)->validtype = FALSE;
	(*lst)->precisionthere = FALSE;
	(*lst)->precision = 0;
	(*lst)->width = 0;
	(*lst)->type = ' ';
	(*lst)->result = 0;
	return (0);
}
