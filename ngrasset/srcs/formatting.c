/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 13:08:14 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 16:58:00 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	find_padding(t_stack *head, size_t *padding)
{
	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	padding[3] = 0;
	padding[4] = 0;
	while (head)
	{
		if (ft_strlen(head->fields->links) > padding[0])
			padding[0] = ft_strlen(head->fields->links);
		if (ft_strlen(head->fields->owner) > padding[1])
			padding[1] = ft_strlen(head->fields->owner);
		if (ft_strlen(head->fields->group) > padding[2])
			padding[2] = ft_strlen(head->fields->group);
		if (ft_strlen(head->fields->major) > padding[3])
			padding[3] = ft_strlen(head->fields->major);
		if (ft_strlen(head->fields->size) > padding[4])
			padding[4] = ft_strlen(head->fields->size);
		head = head->next;
	}
	padding[0]++;
	padding[1]++;
	padding[2]++;
	if (padding[3])
		padding[3]++;
}

int		find_total_size(t_stack *head)
{
	int		total;

	total = 0;
	while (head)
	{
		total += (int)head->stats.st_blocks;
		head = head->next;
	}
	return (total);
}

void	put_field(char *str)
{
	if (str)
		ft_putstr(str);
	ft_putchar(' ');
}

void	put_field_padding(char *str, size_t size, int right)
{
	size_t	p;

	if (str)
	{
		if (right == 1)
			ft_putstr(str);
		p = size - ft_strlen(str);
		while (p > 0)
		{
			ft_putchar(' ');
			p--;
		}
		if (right != 1)
			ft_putstr(str);
	}
	if (right == 2)
		ft_putchar(',');
	ft_putchar(' ');
}

void	put_name(t_stack *elem)
{
	char	buffer[256];
	ssize_t	ret;

	if (elem->type == SYM_LINK)
	{
		ret = readlink(elem->path, buffer, 256);
		if (ret == -1)
		{
			log_invalid_elem(elem);
			return ;
		}
		buffer[ret] = '\0';
		ft_putstr(elem->filename);
		ft_putstr(" -> ");
		ft_putendl(buffer);
		return ;
	}
	ft_putendl(elem->filename);
}
