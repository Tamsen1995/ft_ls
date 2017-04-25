/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:52:11 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 16:52:12 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_filetype	find_file_type(mode_t mode)
{
	if (S_ISBLK(mode))
		return (BLOCK);
	if (S_ISCHR(mode))
		return (CHAR_SP);
	if (S_ISDIR(mode))
		return (DIRECTORY);
	if (S_ISLNK(mode))
		return (SYM_LINK);
	if (S_ISSOCK(mode))
		return (SOCK_LINK);
	if (S_ISFIFO(mode))
		return (FIFO);
	return (REG);
}

char		filetype_to_char(t_filetype t)
{
	if (t == BLOCK)
		return ('b');
	if (t == CHAR_SP)
		return ('c');
	if (t == DIRECTORY)
		return ('d');
	if (t == SYM_LINK)
		return ('l');
	if (t == SOCK_LINK)
		return ('s');
	if (t == FIFO)
		return ('p');
	return ('-');
}
