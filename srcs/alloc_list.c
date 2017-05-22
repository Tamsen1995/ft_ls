#include "../includes/ft_ls.h"

// This function receives a name and allocates everything in the the current directory into 
// a nice stack. it then returns this stack
t_stack  *register_fls_in_dir(char *name)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;
	// struct stat *file_info_buffer;

	fls = NULL;
	if (!(dir = opendir(name)))
		exit (-1);
	if (!(ent = readdir(dir)))
	{
		exit (-1);
	}
	if (!(fls = ft_lstnew(ent, name)))
		exit (-1);
	while ((ent = readdir(dir)))
			ft_list_push_back(&fls, ent, name); // TODO here is where I should implement the sorting of my stack
	return (fls);
}

// This function simply check if the current entry's name 
// is neither the current directory nor the previous one
t_bool		not_curr_and_prev(t_stack *entry)
{
	if (ft_strcmp(entry->filename, ".") != 0 && ft_strcmp(entry->filename, "..") != 0)
		return (TRUE);
	return (FALSE);
}

// This function recursively allocates the entirety of the directory as well as its subdirectories
t_stack			*alloc_list(char *dir_path)
{
	t_stack			*fls;
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion


	tmp = NULL;
	if (!(fls = register_fls_in_dir(dir_path))) // zapping the entire entry list into a stack chain
		exit (-1);
	tmp = fls;



	//TESTING~!
	while (tmp)
	{		

		tmp->fields = get_file_info(tmp); // extracting all the info
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			tmp->subdir = alloc_list(tmp->path); // recursively calling the function again with the newly made path in the stack elem
		tmp = tmp->next;
	}
	return (fls); // returnning null for now, just testing
}