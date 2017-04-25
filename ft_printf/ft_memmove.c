/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:10:42 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:31:57 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	char			tmp[n];
	char			*destptr;
	const	char	*srcptr;

	i = 0;
	destptr = (char *)str1;
	srcptr = (const char *)str2;
	while (i < n)
	{
		tmp[i] = srcptr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		destptr[i] = tmp[i];
		i++;
	}
	return (str1);
}
