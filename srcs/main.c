#include "../includes/ft_ls.h"


// This function recursively allocates the entirety of the directory as well as its subdirectories
t_stack			*alloc_list(char *name)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;

	fls = NULL;
	if (!(dir = opendir(name)))
		return (NULL);
	if (!(ent = readdir(dir)))
		return (NULL);
	if (!(fls = ft_lstnew(ent, name)))
		return (NULL);
	


	return (NULL); // returnning null for now, just testing
}

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	int t; //TESTING
	t_stack		*files;
	//t_stack		*directories;
	//t_stack		*new;


	i = parse_flags(ac, av, flags);

	files = alloc_list("."); // TODO treat allocation


	// TODO print out stack attributes here for testing




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


