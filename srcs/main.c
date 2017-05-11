#include "ft_ls.h"


int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	//t_stack		*files;
	//t_stack		*directories;
	//t_stack		*new;

	i = parse_flags(ac, av, flags);

	printf("%s", flags);


	return (0);
}
// TODO find weird bug which I can start tracing in the assess_output function


