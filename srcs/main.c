#include "../includes/ft_ls.h"

char 	**copy_args(int ac, char **av)
{
	char **av_tmp;
	int i;

	i = 0;
	av_tmp = NULL;
	if (!(av_tmp = (char **)malloc(sizeof(char *) * ac)))
		error_msg("Error in the copying of arguments ! (copy_args)");
	while (i != ac)
	{
		av_tmp[i] = ft_strdup(av[i]);
//		ft_putendl(av_tmp[i]); //TESTING
		i++;
	}
	return (av_tmp);
}

// very ugly
// is solely used in the case directories are put in as parameters
void print_dir_name(char *dir_path)
{
		////////////
		ft_putendl("");
		ft_putstr(dir_path);
		ft_putendl(":");
		//////////
}


// a function which cuts out all the nondirectories in the args and also throw an error message for the invalid inputs
char		**check_args_for_dirs(char **av_tmp, int i, int ac)
{
	DIR				*dir;
	char **dir_arr;
	int k;

	dir_arr = NULL;
	dir = NULL;
	k = 0;
	if (!(dir_arr = (char **)malloc(sizeof(char *) * ac)))
		error_msg("Directory could not be opened ! (check_args_for_dir)");
	while (i < ac && av_tmp[i])
	{
		if (!(dir = opendir(av_tmp[i])))
		{
			ft_putstr("No such file or directory:\t");
			ft_putendl(av_tmp[i]);
		}
		else
		{
			dir_arr[k] = ft_strdup(av_tmp[i]);
			k++;
		}
		i++;
	}
	dir_arr[k] = NULL;
	return (dir_arr);
}


// TODO Get the l in the beginning of the permissions for linked files
// TODO figure out why the non recursive long listing format doesn't show the right amount of total blocks

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	char 		*dir_path;
	char		 **av_tmp;


	dir_path = NULL;
	files = NULL;
	av_tmp = copy_args(ac, av);
	i = parse_flags(ac, av_tmp, flags);

	av_tmp = check_args_for_dirs(av_tmp, i, ac);
	i = 0;
	// this loop is used in the case 
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strdup(av_tmp[i]);
		files = alloc_list(dir_path, flags);
		print_dir_name(dir_path); 
		output_module(files, flags);
		free(dir_path);
		free(files);
		i++;
	}
	if (dir_path == NULL) // if it's still null at this point then the programm will just assume that no directories have been found
	{
		files = alloc_list(".", flags);
		output_module(files, flags);
	}
	return (0);
}


