/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:57:09 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/12 18:24:07 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*mem_concat(char *dst, char *src)
{
	char	*res;

	if (!dst)
	{
		dst = ft_strdup(src);
		return (dst);
	}
	res = ft_strnew(ft_strlen(dst) + ft_strlen(src) + 1);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, dst);
	res = ft_strcat(res, src);
	free(dst);
	dst = res;
	return (res);
}

int		get_overf(char **line, t_overflow *overf)
{
	char	*raw_data;
	char	*endl;

	raw_data = NULL;
	raw_data = ft_strdup(overf->overflow);
	if (!raw_data)
		return (-1);
	endl = ft_strchr(raw_data, '\n');
	if (endl)
	{
		*endl = '\0';
		*line = raw_data;
		raw_data = ft_strcpy(overf->overflow, endl + 1);
		if (!raw_data)
			overf->set = 0;
		else
			overf->set = 1;
		return (1);
	}
	*line = raw_data;
	return (0);
}

int		get_next_buffer(char **line, t_overflow *overf, int fd, char buffer[])
{
	int		ret;
	char	*endl;

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		*line = mem_concat(*line, buffer);
		if (!*line)
			return (-1);
		endl = ft_strchr(*line, '\n');
		if (endl)
		{
			*endl = '\0';
			ft_strcpy(overf->overflow, endl + 1);
			if (ft_strlen(overf->overflow) != 0)
				overf->set = 1;
			else
				overf->set = 0;
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_overflow	overf[MAX_FD];
	char				buffer[BUFF_SIZE + 1];
	int					ret;

	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	*line = NULL;
	if (overf[fd].set)
	{
		ret = get_overf(line, &overf[fd]);
		if (ret != 0)
			return (ret);
	}
	ret = get_next_buffer(line, &overf[fd], fd, buffer);
	return (ret);
}
