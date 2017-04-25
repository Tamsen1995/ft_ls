/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 03:29:49 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 03:29:51 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_str_case2(char *str, char *aff, int added, t_list **lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = ft_str_case2_two(lst, str, aff, i);
	while (j < added)
	{
		aff[i] = ' ';
		i++;
		j++;
	}
	aff[i] = '\0';
	return (i);
}

int			ft_str_case2_two(t_list **lst, char *str, char *aff, int i)
{
	if ((*lst)->precisionthere == TRUE)
	{
		while (str[i] != '\0' && i < (*lst)->precision)
		{
			aff[i] = str[i];
			i++;
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			aff[i] = str[i];
			i++;
		}
	}
	return (i);
}

int			ft_str_case3(char *str, char *aff, int added, t_list **lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < added && (*lst)->zero == FALSE)
		aff[i++] = ' ';
	while (i < added && (*lst)->zero == TRUE)
		aff[i++] = '0';
	if ((*lst)->precisionthere == TRUE)
	{
		while (str[j] != '\0' && j < (*lst)->precision)
			aff[i++] = str[j++];
	}
	else
	{
		while (str[j] != '\0' && str != NULL)
			aff[i++] = str[j++];
	}
	aff[i] = '\0';
	return (i);
}

void		ft_str_case_two(t_list **lst, int added, char *str, char *aff)
{
	int len;

	len = ft_strlen(str);
	if ((*lst)->precision < len && (*lst)->width > len \
		&& (*lst)->precisionthere == TRUE)
		added = added + (len - (*lst)->precision);
	if ((*lst)->minus == TRUE)
		(*lst)->result = ft_str_case2(str, aff, added, lst);
	if ((*lst)->minus == FALSE)
		(*lst)->result = ft_str_case3(str, aff, added, lst);
	ft_putstr(aff);
	free(aff);
	aff = NULL;
}

void		ft_str_case(t_list **lst, char *str)
{
	char		*aff;
	int			added;
	int			len;

	len = ft_strlen(str);
	added = 0;
	if ((*lst)->precision < 0)
	{
		(*lst)->precision = len;
	}
	if ((*lst)->width >= len)
	{
		added = (*lst)->width - len;
		aff = ft_strnew((*lst)->width);
	}
	else if ((*lst)->width >= (*lst)->precision)
	{
		added = (*lst)->width - (*lst)->precision;
		aff = ft_strnew((*lst)->width);
	}
	else
		aff = ft_strnew(len);
	ft_str_case_two(lst, added, str, aff);
	return ;
}
