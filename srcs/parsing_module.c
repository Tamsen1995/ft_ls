/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:35:13 by tbui              #+#    #+#             */
/*   Updated: 2017/07/17 16:35:15 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		log_flags(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-", 2);
	ft_putstr_fd(VALID_FLAGS, 2);
	ft_putendl_fd("] [file ...]", 2);
	exit(0);
}

void		init_flags(char *flags)
{
	int		i;

	i = 0;
	while (i++ <= NB_FLAGS)
		flags[i] = 0;
}

int			flag_index(char c)
{
	int i;

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


/*
** Certain flags turn other flags
** on and/or cancel other flags 
** (Ex. the f flags turns on the a flag 
** and turns off any other sorting flag)
** This function checks for the occurences
*/
void check_flag_overlaps(char *flags)
{
	if (flags[f_nosort] == 1)
	{
		flags[f_hidden] = 1;
		flags[f_time] = 0;
		flags[f_rev] = 0;
	}
}

int			parse_flags(int ac, char **av, char *flags)
{
	int		i;
	int		j;

	init_flags(flags);
	i = 0;
	while (i < ac && av[i][0] == '-' && av[i][1])
	{
		j = 0;
		if (av[i][1] == '-' && !av[i][2])
			return (i + 1);
		while (av[i][++j])
			*(flags + flag_index(av[i][j])) = 1;
		free(av[i]);
		i++;
	}
	check_flag_overlaps(flags);
	return (i);
}
