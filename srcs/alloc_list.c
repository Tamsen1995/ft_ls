#include "../includes/ft_ls.h"

// This function receives a name and allocates everything in the the current directory into 
// a nice stack. it then returns this stack
t_stack  *register_fls_in_dir(char *name, char *flags)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;

	fls = NULL;
	if (!(dir = opendir(name)))
		error_msg("A Directory could not be opened ! (register_fls_in_dir)");
	if (!(ent = readdir(dir)))
		error_msg("There was a problem with the reading of an entry in the directory ! (register_fls_in_dir)");
	if (!(fls = ft_lstnew(ent, name)))
		error_msg("The first file of a dir could not be allocated ! (register_fls_in_dir)");
	while ((ent = readdir(dir)))
			ft_list_push_back(&fls, ent, name, flags); // TODO here is where I should implement the sorting of my stack
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
t_stack			*alloc_list(char *dir_path, char *flags)
{
	t_stack			*fls;
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion


	tmp = NULL;
	if (!(fls = register_fls_in_dir(dir_path, flags))) // zapping the entire entry list into a stack chain
		error_msg("There was an error in the registering of a file ! (alloc_list)");
	tmp = fls;
	while (tmp)
	{		

		tmp->fields = get_file_info(tmp); // extracting all the info
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			tmp->subdir = alloc_list(tmp->path, flags); // recursively calling the function again with the newly made path in the stack elem
		tmp = tmp->next;
	}
	return (fls); // returnning null for now, just testing
}