#include "../includes/ft_ls.h"

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
	int i;

	i = 0; // I changed this so it would iterate by addition instead of subtraction
	while (i++ <= NB_FLAGS)
		flags[i] = 0;
}


// this function checks for the validity of the flag as well as returning the index of the 
// flag to change in the given flag array
int 		flag_index(char c)
{
	int 	i;

	i = 0;
	while (VALID_FLAGS[i])
	{
		if (VALID_FLAGS[i] == c)
			return (i);
		i++;
	}
	// log flags 
	log_flags(c);
	return (0);
}


void	free_args_copy()
{

}




int		parse_flags(int ac, char **av, char *flags)
{

	int i;
	int j;
	
	init_flags(flags);
	i = 1;
	// iterate through all the given args (2D array)
	while (i < ac && av[i][0] == '-' && av[i][1])
	{
		j = 0;
		if (av[i][1] == '-' && !av[i][2])
			return (i + 1);
		while (av[i][++j])
			*(flags + flag_index(av[i][j])) = 1;
		i++;
	}
	//free_args_copy(ac, av_tmp);

	return (i);
}