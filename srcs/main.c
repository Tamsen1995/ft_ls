#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	//t_stack		*directories;
	//t_stack		*new;


	i = parse_flags(ac, av, flags);

	files = alloc_list("."); // TODO treat allocation







	return (0);
}


