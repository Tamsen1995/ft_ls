/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 17:13:46 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:14:34 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	log_invalid_elem(t_stack *elem)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(elem->filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(elem->err_msg, 2);
}

void	log_opendir(char *file, char *err)
{
	char	*clean;

	clean = ft_strrchr(file, '/');
	ft_putstr_fd("ft_ls: ", 2);
	if (clean)
		ft_putstr_fd(clean + 1, 2);
	else
		ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}

void	log_folder(char *path)
{
	ft_putstr(path);
	ft_putendl(":");
}

void	log_total_size(t_stack *head)
{
	int		total;

	total = find_total_size(head);
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}
