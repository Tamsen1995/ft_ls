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
		i++;
	}
	return (av_tmp);
}

void print_dir_name(char *dir_path)
{
		ft_putendl("");
		ft_putstr(dir_path);
		ft_putendl(":");
}

// this function will iterate through the arguments array again
// and see which files are valid regular files which ought to be sent to the output.
void		print_valid_fls(char **av_tmp, int ac) 
{
	int i;
	DIR			*dir;
	struct stat buf;

	i = 1;
	while (i < ac && av_tmp[i])
	{
		if (!(dir = opendir(av_tmp[i])) && lstat(ft_strjoin("./", av_tmp[i]), &buf) == 0)
			ft_putendl(av_tmp[i]);
		i++;
	}
}

// a function which cuts out all the nondirectories in the args and also throw an error message for the invalid inputs
char		**check_args_for_dirs(char **av_tmp, int i, int ac)
{
	DIR			*dir;
	char		**dir_arr;
	int 		k;
	struct stat buf; 

	dir_arr = NULL;
	dir = NULL;
	k = 0;
	if (!(dir_arr = (char **)malloc(sizeof(char *) * ac)))
		error_msg("Directory could not be opened ! (check_args_for_dir)");
	while (i < ac && av_tmp[i])
	{
		// this checks if the current argument is an invalid or nonexistent directory name
		if (!(dir = opendir(av_tmp[i])) && lstat(ft_strjoin("./", av_tmp[i]), &buf) < 0)
		{
			ft_putstr("No such file or directory:\t");
			ft_putendl(av_tmp[i]);
		}
		else if (lstat(ft_strjoin("./", av_tmp[i]), &buf) == 0)
		{
			dir_arr[k] = ft_strdup(av_tmp[i]);
			k++;
		}
		i++;
	}
	// this prints every file which isn't a directory
	// print_valid_fls(av_tmp, ac); 
	dir_arr[k] = NULL;
	return (dir_arr);
}

// frees all the attributes of the list structure
void		free_list_attr(t_stack *list)
{
	ft_strdel(&list->path);
	ft_strdel(&list->filename);
	ft_strdel(&list->fields->links);
	ft_strdel(&list->fields->size);
	ft_strdel(&list->fields->date);
}

// This function will go through the entire stack recursively BACKWARDS
void		free_list(t_stack *list)
{
	// go to the end of the list
	// in order to go backwards again
	if (!list)
		return ;
	while (list->next) 
		list = list->next;
	// iterating through the whole thing backwards
	while (list)
	{		
		if (not_curr_and_prev(list) == TRUE && list->type == DIRECTORY)
			free_list(list->subdir);
		free_list_attr(list);
		free(list);
		list = list->prev;
	}
}

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	char 		*dir_path;
	char		 **av_tmp;

	av_tmp = copy_args(ac, av);
	i = parse_flags(ac, av_tmp, flags);
	av_tmp = check_args_for_dirs(av_tmp, i, ac);
	i = 0;
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strdup(av_tmp[i]);
		files = alloc_list(dir_path, flags);
		print_dir_name(dir_path); 
		output_module(files, flags);
		free_list(files);
		i++;
	}
	if (dir_path == NULL) // if it's still null at this point then the programm will just assume that no directories have been found
	{
		files = alloc_list(".", flags);
		output_module(files, flags);
	}
	free_list(files);
	return (0);
}

// TODO
// make sure only the files info is printed with the respective flags in case a file is put as an input 
	// In order to do this you need to send the file as a directory path into the normal flow. 
	// Once it is in there you need to check if it's a directory or a regular file.
	// In the case of it being a regular file we redirect it towards a flow in which file paths are taken care of instead of directory paths


// make sure not to print the folder name in the case of the being a single input (with flags)
