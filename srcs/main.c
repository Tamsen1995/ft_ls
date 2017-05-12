#include "../includes/ft_ls.h"


// This function receives a name and allocates everything in the the current directory into 
// a nice stack. it then returns this stack
t_stack  *register_fls_in_dir(char *name)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;
	//struct stat *file_info_buffer;

	fls = NULL;
	if (!(dir = opendir(name)))
		return (NULL);
	if (!(ent = readdir(dir)))
		return (NULL);
	if (!(fls = ft_lstnew(ent, name)))
		return (NULL);

	while ((ent = readdir(dir)))
			ft_list_push_back(&fls, ent, name);
	return (fls);
}

// This function recursively allocates the entirety of the directory as well as its subdirectories
t_stack			*alloc_list(char *name)
{
	t_stack			*fls;

	// zapping the entire entry list into a stack chain
	fls = register_fls_in_dir(name);
	return (NULL); // returnning null for now, just testing
}

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	int t;
	t_stack		*files;
	//t_stack		*directories;
	//t_stack		*new;


	i = parse_flags(ac, av, flags);

	files = alloc_list("."); // TODO treat allocation


	//TESTING
	t = 0;

	printf("\n\n\n");
	printf("This is an array of integers indicating which flags are intitialized\n");
	while (t < NB_FLAGS)
	{
		printf("%d\n", flags[t]);
		t++;
	}
	printf("\n\n");
	/////TESTING

	return (0);
}


