#include "../includes/ft_ls.h"
// this function will iterate through the arguments array again
// and see which files are valid regular files which ought to be sent to the output.
void		print_valid_fls(char **av_tmp, int ac) 
{
	int 		i;
	DIR			*dir;
	struct stat buf;
	char 		*path;

	i = 1;
	path = NULL;
	while (i < ac && av_tmp[i])
	{
		path = ft_strjoin("./", av_tmp[i]);
		if (!(dir = opendir(av_tmp[i])) && lstat(path, &buf) == 0)
			ft_putendl(av_tmp[i]);
		i++;
		free(path);
	}
	if (dir)
		closedir(dir);
}

// This function will go through the entire stack recursively BACKWARDS
void		free_list(t_stack *list)
{
	t_stack *tmp;

	tmp = NULL;
	if (!list)
		error_msg("Error in the freeing of the list");
	tmp = list;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			free_list(tmp->subdir);
		free(tmp->path);
		free(tmp->filename);
		free(tmp->fields->links);
		free(tmp->fields->size);
		free(tmp->fields->date);
		free(tmp->fields);
		free(tmp);
	}
	free(list);
	return ;
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
		if (dir)
			closedir(dir);
	}
}

int			main(int ac, char **av)
{
	char 		flags[NB_FLAGS];
	int			i;
	t_stack		*files;
	char 		*dir_path;
	char		 **av_tmp;

	av++;
	ac--;
	av_tmp = copy_args(ac, av);
	i = parse_flags(ac, av_tmp, flags);
	av_tmp = check_args_for_dirs(av_tmp, i, ac);
	av_tmp = sort_args(av_tmp);
	i = 0;
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strdup(av_tmp[i]);
		files = alloc_list(dir_path, flags);
		print_dir_name(dir_path, av_tmp);
		output_module(files, flags);
		free_list(files);
		i++;
	}
	// if it's still null at this point then
	// the programm will just assume that no directories have been found
	if (dir_path == NULL)
	{
		files = alloc_list(".", flags);
		output_module(files, flags);
		free_list(files);
	}
	free(av_tmp);
	return (0);
}

// TODO
/// Fix the copy args memory leak