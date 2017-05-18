#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	//t_stack		*new;

	// TODO code function which will check the validity of an input if there is one, meaning it will check if it is even a directory or not
	// TODO handle the intake of directories as arguments

	// if (ac <)


	i = parse_flags(ac, av, flags);
	files = alloc_list("."); // TODO add the blocksize for files in a directory (only the ones you show) an show as total
	output_module(files, flags);
	return (0);
}


