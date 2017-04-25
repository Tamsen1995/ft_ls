/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:44:11 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/27 15:32:21 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**start;
	char		**tab;
	char		*copy;
	int			count_words;

	count_words = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!tab)
		return (NULL);
	start = tab;
	copy = ft_strdup(s);
	if (!copy)
		return (NULL);
	ft_search_and_replace(copy, c, '\0');
	while (count_words-- > 0)
	{
		while (*copy == '\0')
			copy++;
		*tab = ft_strsub(copy, 0, ft_strlen(copy));
		while (*copy != '\0')
			copy++;
		tab++;
	}
	*tab = 0;
	return (start);
}
