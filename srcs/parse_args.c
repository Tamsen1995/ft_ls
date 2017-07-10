#include "../includes/ft_ls.h"

char 	**copy_args(int ac, char **av)
{
	char **av_tmp;
	char **tmp;
	int i;

	i = 0;
	av_tmp = NULL;
	tmp = NULL;
	if (!(av_tmp = (char **)malloc(sizeof(char *) * ac)))
		error_msg("Error in the copying of arguments ! (copy_args)");
	tmp = av_tmp;
	while (i < ac)
	{
		(*tmp) = ft_strdup(av[i]);
		tmp++;
		i++;
	}
	return (av_tmp);
}

// This function takes in a path and checks to see if
// the path belongs to a valid folder into which one can enter
t_bool		is_valid_folder(char *path)
{
	struct stat buf; 

	if (lstat(ft_strjoin("./", path), &buf) == 0 || ft_strncmp("/", path, 1) == 0)
		return (TRUE);
	return (FALSE);
}
// This functions simply returns true 
// if all flags are absent
t_bool      flags_absent(char *flags)
{
    int i;

    i = 0;
    while (i < NB_FLAGS)
    {
        if (flags[i] == 1)
            return (FALSE);
        i++;
    }
    return (TRUE);
}


t_bool		inv_fls_present(char **av_tmp, int i, int ac)
{

	// this flags indicates if there are any 
	// invalid files in the array or not
	t_bool		flag;
	struct stat buf;
	DIR			*dir;

	flag = FALSE;
	dir = NULL;
	while (i < ac && av_tmp[i])
	{
		// this checks if the current argument is an invalid or nonexistent directory name
		if (!(dir = opendir(av_tmp[i])) && lstat(ft_strjoin("./", av_tmp[i]), &buf) < 0)
		{
			ft_putstr("No such file or directory:\t");
			ft_putendl(av_tmp[i]);
			flag = TRUE;
		}
		i++;
	}
	return (flag);
}


// a function which cuts out all the nondirectories in the args and also throw an error message for the invalid inputs
char		**check_args_for_dirs(char **av_tmp, int i, int ac)
{
	char		**dir_arr;
	int 		k;
	int			j;

	dir_arr = NULL;
	k = 0;
	j = 0;
	if (!(dir_arr = (char **)malloc(sizeof(char *) * ac)))
		error_msg("ERROR: (check_args_for_dir)");
	while (i < ac && av_tmp[i])
	{
		if (is_valid_folder(av_tmp[i]))
		{
			dir_arr[k] = ft_strdup(av_tmp[i]);
			k++;
		}
		i++;
		j++;
	}
	i = i - j;
	if (inv_fls_present(av_tmp, i, ac) && k <= 0) //&& flags_absent(flags)) // TESING // TODO solve this
		exit(-1);
	// this prints every file which isn't a directory
	// print_valid_fls(av_tmp, ac); 
	dir_arr[k] = NULL;
	free(av_tmp);
	return (dir_arr);
}
