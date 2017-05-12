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
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion


	tmp = NULL;
	fls = NULL;
	// zapping the entire entry list into a stack chain
	if (!(fls = register_fls_in_dir(name)))
		return (NULL);


	// TODO figure out what exactly I need in order to allocate
	// and entire directory. I suspect it may be the entire path
	// if so I will have to figure out where exactly the saving of the path will take place.

	/*

	// TODO recursively allocate every single element 
	// in all  subdirectories and their subdirectories and so on
	tmp = fls;
	while (tmp)
	{
		if (not_curr_and_prev(tmp) && tmp->type == DIR)
			tmp->subdir = alloc_list(ent->filename);
		tmp = tmp->next; 
	}
	
	*/

	return (fls); // returnning null for now, just testing
}

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	//t_stack		*directories;
	//t_stack		*new;


	i = parse_flags(ac, av, flags);

	files = alloc_list("."); // TODO treat allocation


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

	return (0);
}


