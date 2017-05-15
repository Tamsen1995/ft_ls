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

	out_entire_stack(files); // TESTING

/*

	////////////////////////////////////////////////////////TESTING
	t_stack *tmp;

	tmp = files;
	while (tmp)
	{
		ft_putendl(tmp->filename);
		tmp = tmp->next;
	}
	int t;
	t = 0;
	printf("\n\n\n");
	printf("This is an array of integers indicating which flags are intitialized\n");
	while (t < NB_FLAGS)
	{
		printf("%d\n", flags[t]);
		t++;
	}
	printf("\n\n");
	//////////////////////////////////////////////////////////////TESTING

*/

	return (0);
}


