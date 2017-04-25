/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:51:25 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 18:00:08 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	if (!(fraiche = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!(s))
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		fraiche[i] = s[start];
		start++;
		i++;
	}
	fraiche[i] = '\0';
	if (i < len)
		return (NULL);
	else
		return (fraiche);
}
