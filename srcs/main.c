#include "../includes/ft_ls.h"


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


// checks if the dir_path actually belongs to a directory
// if so it prints it
// used in the case of feeding files or directories into the input
void print_dir_name(char *dir_path, char **av_tmp)
{
	DIR		*dir;
	int		i;

	i = 0;
	if (av_tmp)
	{
		while (av_tmp[i])
			i++;
		if ((dir = opendir(dir_path)) && i > 1)
		{
			ft_putendl("");
			ft_putstr(dir_path);
			ft_putendl(":");
		}
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
	av_tmp = sort_args(av_tmp); // TESTING

	i = 0;
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strdup(av_tmp[i]);
		files = alloc_list(dir_path, flags);
		print_dir_name(dir_path, av_tmp);
		output_module(files, flags);
		i++;
	}
	// if it's still null at this point then
	// the programm will just assume that no directories have been found
	if (dir_path == NULL)// && ac < 2)
	{
		files = alloc_list(".", flags);
		output_module(files, flags);
	}
	free_list(files);
	return (0);
}

// TODO
// Fix the sorting of the arguments
// The arguments aren't being properly sorted as of now.
