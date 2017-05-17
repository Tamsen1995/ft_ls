#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	//t_stack		*new;

	i = parse_flags(ac, av, flags);
	files = alloc_list("."); // TODO add the blocksize for files in a directory (only the ones you show) an show as total
	output_module(files, flags);
	return (0);
}


