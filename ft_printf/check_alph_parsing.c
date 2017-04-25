/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alph_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:01:22 by tbui              #+#    #+#             */
/*   Updated: 2016/05/11 22:01:23 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_alph(const char *str, t_list **lst, int i)
{
	int skip;

	skip = 0;
	if (str[i] == 'j')
	{
		(*lst)->j = TRUE;
		i++;
		skip++;
	}
	if (str[i] == 'z')
	{
		(*lst)->z = TRUE;
		i++;
		skip++;
	}
	return (skip);
}

int		check_alph2(const char *str, t_list **lst, int i)
{
	int skip;

	skip = 0;
	if (str[i] == 'l')
	{
		(*lst)->ell = TRUE;
		i++;
		skip++;
		if (str[i] == 'l')
		{
			(*lst)->ll = TRUE;
			(*lst)->ell = FALSE;
			i++;
			skip++;
		}
	}
	return (skip);
}

int		check_alph3(const char *str, t_list **lst, int i)
{
	int skip;

	skip = 0;
	if (str[i] == 'h')
	{
		i++;
		skip++;
		(*lst)->h = TRUE;
		if (str[i] == 'h')
		{
			(*lst)->h = FALSE;
			(*lst)->hh = TRUE;
			i++;
			skip++;
		}
	}
	return (skip);
}
