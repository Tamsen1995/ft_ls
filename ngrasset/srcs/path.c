/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:52:44 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 16:52:45 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*join_path(char *s1, char *s2)
{
	char	*step1;
	char	*step2;

	if (!s2)
		return (ft_strdup(s1));
	if (s1[ft_strlen(s1) - 1] == '/')
		return (ft_strjoin(s1, s2));
	step1 = ft_strjoin(s1, "/");
	step2 = ft_strjoin(step1, s2);
	free(step1);
	return (step2);
}
