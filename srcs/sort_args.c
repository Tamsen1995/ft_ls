#include "../includes/ft_ls.h"


// ONLY FOR TESTING PURPOSES
void		print_twod_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putendl(arr[i]);
		i++;
	}
	ft_putendl("");
}/////////////////////////


// This function takes in the path of a file
// and determines whether it's a directory or not
t_filetype		get_type_from_path(char *path)
{
	struct stat buf;
	mode_t type;

	path = make_dir_path(path);
	lstat(path, &buf);
	type = buf.st_mode;
	if (S_ISDIR(type))
		return (DIRECTORY);
	return (INVALID);
}

// this function takes in a 2d array to check if it is already
// fully sorted
// returns true if so
t_bool			sorted(char **array)
{
	int i;
	int k;
	t_filetype type_i;
	t_filetype type_k;

	// if the second array isn't a directory but a regular file
	// then it needs to be sorted
	i = 0;
	k = 1;
	while (array[k] && array[i])
	{
		type_i = get_type_from_path(array[i]);
		type_k = get_type_from_path(array[k]);
		if (ft_strcmp(array[i] , array[k]) > 0 &&\
			((type_i == INVALID && type_k == INVALID) ||\
			(type_i == DIRECTORY && type_k == DIRECTORY)))
			return (FALSE);
		if (type_k == INVALID && type_i == DIRECTORY)
			return (FALSE);
		i++;
		k++;
	}
	return (TRUE);
}

// this function takes in two elements
// and checks to see if the two args have to be switched
// directory paths are sorted by ascii
// files are also sorted by ascii but always come before the dir paths
t_bool		cmp_args(char *arg_one, char *arg_two)
{
	t_filetype type_one;
	t_filetype type_two;

	type_one = get_type_from_path(arg_one);
	type_two = get_type_from_path(arg_two);
	if (ft_strcmp(arg_one, arg_two) > 0)
		return (TRUE);
	if (type_two == INVALID && type_one == DIRECTORY)
		return (TRUE);
	return (FALSE);
}

// This function simply takes in the 2d array of arguments
// and the two indexes of the elements to swap
// and then swaps the two
char		**swap_arr(char **av_tmp, int arg_one, int arg_two)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strdup(av_tmp[arg_one]);
	av_tmp[arg_one] = ft_strdup(av_tmp[arg_two]);
	av_tmp[arg_two] = ft_strdup(tmp);
	return (av_tmp);
}

// TODO finish this function
// modify the sorted() and cmp_args() functions
// so that they will also consider normal files
// normal files always have to come before directories
char 		**sort_args(char **av_tmp)
{
 	int i;
	int k;

	i = 0;
	k = 1;
	while (sorted(av_tmp) == FALSE)
	{
		i = 0;
		k = 1;
		while (av_tmp[k] != NULL)
		{
			if (cmp_args(av_tmp[i], av_tmp[k]))
				av_tmp = swap_arr(av_tmp, i, k);
			i++;
			k++;
		}
	}
	return (av_tmp);
}