/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:19:16 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/25 19:39:54 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_color(const char *str, const char *color)
{
	if (ft_strcmp(color, "red") == 0)
		ft_putstr(FT_C_RED);
	if (ft_strcmp(color, "blue") == 0)
		ft_putstr(FT_C_BLUE);
	if (ft_strcmp(color, "green") == 0)
		ft_putstr(FT_C_GREEN);
	if (ft_strcmp(color, "yellow") == 0)
		ft_putstr(FT_C_YELLOW);
	if (ft_strcmp(color, "magenta") == 0)
		ft_putstr(FT_C_MAGENTA);
	if (ft_strcmp(color, "cyan") == 0)
		ft_putstr(FT_C_CYAN);
	if (ft_strcmp(color, "white") == 0)
		ft_putstr(FT_C_WHITE);
	ft_putstr(str);
	ft_putstr(FT_C_RESET);
}
