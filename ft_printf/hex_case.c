/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 07:59:33 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 07:59:35 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hex_normal_two(t_list **lst, char *aff, int *i, int *added)
{
	if ((*lst)->hashtag == TRUE && (*lst)->zero == TRUE)
	{
		aff[(*i)++] = '0';
		aff[(*i)++] = 'x';
	}
	while ((*i) < (*added) && (*lst)->zero == TRUE && \
	(*lst)->precision < (*lst)->width)
		aff[(*i)++] = '0';
}

void		ft_hex_normal_fill(char *aff, char *hex, int *i, int *j)
{
	while (hex[(*j)] != '\0')
	{
		aff[(*i)] = hex[(*j)];
		(*i)++;
		(*j)++;
	}
	aff[(*i)] = '\0';
}

void		ft_hex_normal(t_list **lst, char *hex, char *aff, int added)
{
	int j;
	int i;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(hex);
	while (i < added && (*lst)->zero == FALSE && \
	(*lst)->precision < (*lst)->width)
		aff[i++] = ' ';
	ft_hex_normal_two(lst, aff, &i, &added);
	if ((*lst)->precision >= len)
		added = added + ((*lst)->precision - len);
	while ((*lst)->precision > len && i < added)
		aff[i++] = '0';
	if ((*lst)->itsazero == TRUE && \
	(*lst)->precisionthere == TRUE && (*lst)->precision <= 0)
	{
		(*lst)->result = i;
		return ;
	}
	ft_hex_normal_fill(aff, hex, &i, &j);
	(*lst)->result = i;
}

void		ft_hex_justify(t_list **lst, char *hex, char *aff, int added)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (hex[i] != '\0')
	{
		aff[i] = hex[i];
		i++;
	}
	while (j < added)
	{
		aff[i] = ' ';
		i++;
		j++;
	}
	aff[i] = '\0';
	(*lst)->result = i;
}

void		ft_hex_case(t_list **lst, unsigned int dex)
{
	char	*aff;
	char	*hex;
	int		len;
	int		added;

	added = 0;
	hex = conv_hex_x(lst, dex);
	len = (int)ft_strlen(hex);
	if ((*lst)->precision > len)
		len = (*lst)->precision;
	if ((*lst)->width >= len)
	{
		if ((*lst)->itsazero == TRUE)
			(*lst)->width++;
		added = (*lst)->width - len;
		aff = ft_strnew((*lst)->width);
	}
	else
		aff = ft_strnew(len);
	if ((*lst)->minus == FALSE)
		ft_hex_normal(lst, hex, aff, added);
	if ((*lst)->minus == TRUE)
		ft_hex_justify(lst, hex, aff, added);
	ft_putstr(aff);
	ft_hex_case_free(hex, aff);
}
