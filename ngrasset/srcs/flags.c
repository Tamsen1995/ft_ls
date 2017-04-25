/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:52:16 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:28:53 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	log_flags(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-", 2);
	ft_putstr_fd(VALID_FLAGS, 2);
	ft_putendl_fd("] [file ...]", 2);
	exit(0);
}

void	init_flags(char *flags)
{
	int		i;

	i = NB_FLAGS;
	while (--i >= 0)
		flags[i] = 0;
}

int		parse_flags(int ac, char **av, char *flags)
{
	int		i;
	int		j;

	init_flags(flags);
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1])
	{
		j = 0;
		if (av[i][1] == '-' && !av[i][2])
			return (i + 1);
		while (av[i][++j])
			*(flags + flag_index(av[i][j])) = 1;
		i++;
	}
	return (i);
}

int		flag_index(char c)
{
	int		i;

	i = 0;
	while (VALID_FLAGS[i])
	{
		if (VALID_FLAGS[i] == c)
			return (i);
		i++;
	}
	log_flags(c);
	return (0);
}
