/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 03:53:26 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 03:53:30 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_ll(signed long long n)
{
	char				*str;
	signed long long	save;
	signed long long	neg;
	int					i;

	save = n;
	neg = (n < 0 ? -1 : 1);
	i = 1 + (n < 0);
	while (n /= 10)
		i++;
	str = ft_strnew(i);
	str[i--] = '\0';
	str[i--] = neg * (save % 10) + 48;
	while (save /= 10)
		str[i--] = neg * (save % 10) + 48;
	if (neg < 0)
		str[i] = '-';
	return (str);
}

char		*ft_itoa_unsigned(unsigned long long n)
{
	char					*str;
	unsigned long long		save;
	int						neg;
	int						i;

	save = n;
	neg = 1;
	i = 1;
	while (n /= 10)
		i++;
	str = ft_strnew(i);
	str[i--] = '\0';
	str[i--] = neg * (save % 10) + 48;
	while (save /= 10)
		str[i--] = neg * (save % 10) + 48;
	if (neg < 0)
		str[i] = '-';
	return (str);
}

int			nbr_justify_two(t_list **lst, char *aff, int *added, char *nbr)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(nbr);
	if (aff[0] == '-')
		i++;
	if ((*lst)->plus == TRUE && aff[0] != '-')
		aff[i++] = '+';
	if ((*lst)->precision > len)
		(*added) = (*lst)->precision - len;
	while ((*added) > 0)
	{
		aff[i++] = '0';
		(*added)--;
	}
	return (i);
}

int			nbr_justify(t_list **lst, char *aff, char *nbr)
{
	int added;
	int i;
	int len;
	int temp;
	int j;

	len = ft_strlen(nbr);
	j = 0;
	i = 0;
	added = 0;
	if (nbr[0] == '-')
	{
		len = nbr_justify_norm1(aff, nbr, &temp, &i);
		nbr = ft_itoa(temp);
	}
	i = nbr_justify_two(lst, aff, &added, nbr);
	len = nbr_justify_norm2(nbr, aff, &i, &j);
	nbr_justify_norm3(lst, len, &added);
	while (added > 0)
	{
		aff[i++] = ' ';
		added--;
	}
	aff[i] = '\0';
	return (i);
}
