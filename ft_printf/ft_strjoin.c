/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:08:02 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 18:09:19 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*concptr;
	char	*conc;
	int		mem;

	if (!s1 || !s2)
		return (NULL);
	mem = my_strlen(s1) + my_strlen(s2);
	if (!(char *)malloc(sizeof(char) * mem))
		return (NULL);
	conc = (char *)malloc(sizeof(char) * mem);
	concptr = conc;
	while (*s1 != '\0')
	{
		*conc = *s1;
		conc++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*conc = *s2;
		conc++;
		s2++;
	}
	*conc = '\0';
	return (concptr);
}
