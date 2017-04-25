/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 23:00:12 by tbui              #+#    #+#             */
/*   Updated: 2016/05/08 23:00:14 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_case_norm(t_list **lst, char *aff, int i, char c)
{
	int added;

	added = (*lst)->width - 1;
	if ((*lst)->minus == FALSE)
	{
		while (i < added && (*lst)->zero == FALSE)
			aff[i++] = ' ';
		while (i < added && (*lst)->zero == TRUE)
			aff[i++] = '0';
		aff[i++] = c;
		aff[i] = '\0';
	}
	(*lst)->result = i;
	if (c == 0 && (*lst)->minus == TRUE)
	{
		ft_putchar(0);
		ft_putstr(aff);
	}
	else if (c == 0 && (*lst)->minus == FALSE)
	{
		ft_putstr(aff);
		ft_putchar(0);
	}
	else
		ft_putstr(aff);
}

void	ft_char_case(t_list **lst, char c)
{
	char	*aff;
	int		added;
	int		i;
	int		j;

	j = 0;
	i = 0;
	added = (*lst)->width - 1;
	if ((*lst)->width > 1)
		aff = ft_strnew((*lst)->width);
	else
		aff = ft_strnew(1);
	if ((*lst)->minus == TRUE)
	{
		aff[i++] = c;
		while (j < added)
		{
			aff[i++] = ' ';
			j++;
		}
	}
	ft_char_case_norm(lst, aff, i, c);
	free(aff);
	aff = NULL;
}
