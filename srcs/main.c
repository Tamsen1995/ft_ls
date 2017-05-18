#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	char *dir_path;

	dir_path = NULL;
	files = NULL;
	// TODO code function which will check the validity of an input if there is one, meaning it will check if it is even a directory or not
	// TODO handle the intake of directories as arguments
	// first initiate number of flags
	i = parse_flags(ac, av, flags);
	// then with that the loop will iterate through the rest of the args which are a list of directories
	// if however there are none then 
	while (i < ac)
	{
		dir_path = av[i];
		files = alloc_list(dir_path);
		output_module(files, flags);
		files = NULL;
		i++;
	}
	if (dir_path == NULL) // if it's still null at this point then the programm will just assume that no directories have been 
		files = alloc_list(".");
	output_module(files, flags);
	return (0);
}


