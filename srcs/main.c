#include "../includes/ft_ls.h"

char 	**copy_args(int ac, char **av)
{
	char **av_tmp;
	int i;

	i = 0;
	av_tmp = NULL;
	if (!(av_tmp = (char **)malloc(sizeof(char *) * ac)))
		exit (-1);
	while (i != ac)
	{
		av_tmp[i] = ft_strdup(av[i]);
//		ft_putendl(av_tmp[i]); //TESTING
		i++;
	}
	return (av_tmp);
}

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	char *dir_path;
	char **av_tmp;


	dir_path = NULL;
	files = NULL;
	// TODO code function which will check the validity of an input if there is one, meaning it will check if it is even a directory or not
	// first initiate number of flags
	av_tmp = copy_args(ac, av);
	i = parse_flags(ac, av_tmp, flags);
	// then with that the loop will iterate through the rest of the args which are a list of directories
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strdup(av_tmp[i]);
		files = alloc_list(dir_path);
		output_module(files, flags);
		free(dir_path);
		free(files);
		i++;
	}
	if (dir_path == NULL) // if it's still null at this point then the programm will just assume that no directories have been found
	{
		files = alloc_list(".");
		output_module(files, flags);
	}
	return (0);
}


