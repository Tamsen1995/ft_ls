/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:56:23 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 17:56:38 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	error_msg(char *message)
{
	if (!message)
	{
		ft_putendl("This is an unknown error.");
		exit(-1);
	}
	ft_putendl(message);
	exit(-1);
}
