/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 07:16:59 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 07:17:01 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_perc_justify(int added, t_list **lst, char *aff)
{
	int i;

	i = 0;
	aff[0] = '%';
	ft_putchar(aff[0]);
	while (i < added)
		aff[i++] = ' ';
	aff[i++] = '\0';
	(*lst)->result = i;
	return ;
}

void		ft_perc_case_two(t_list **lst, int *added, char *aff)
{
	int i;

	i = 0;
	if ((*lst)->minus == FALSE)
	{
		while (i < (*added) && (*lst)->zero == FALSE)
			aff[i++] = ' ';
		while (i < (*added) && (*lst)->zero == TRUE)
			aff[i++] = '0';
		aff[i++] = '%';
		aff[i] = '\0';
		(*lst)->result = i;
	}
}

void		ft_perc_case(t_list **lst)
{
	int		i;
	int		added;
	char	*aff;

	i = 0;
	added = 0;
	if ((*lst)->width >= 1)
	{
		added = (*lst)->width - 1;
		aff = ft_strnew((*lst)->width);
	}
	else
		aff = ft_strnew(1);
	ft_perc_case_two(lst, &added, aff);
	if ((*lst)->minus == TRUE)
		ft_perc_justify(added, lst, aff);
	ft_putstr(aff);
	free(aff);
	aff = NULL;
	return ;
}
