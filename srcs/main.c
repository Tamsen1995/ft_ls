#include "ft_ls.h"


int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	int t; //TESTING
	//t_stack		*files;
	//t_stack		*directories;
	//t_stack		*new;

	i = parse_flags(ac, av, flags);



	//TESTING
	t = 0;
	while (t < NB_FLAGS)
	{

		printf("%d\n", flags[t]);
		t++;
	}
	printf("\n\n");
	/////TESTING

	return (0);
}
// TODO find weird bug which I can start tracing in the assess_output function


