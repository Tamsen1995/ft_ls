#include "../includes/ft_ls.h"


// all this function does is iterate through the list and then
// returns the file sought after
t_stack			*extr_sought_fl(t_stack *fls, char *fl_path)
{


}


// this function handles the case of a single file path being put in as the main input
t_stack			*handle_single_fl(char *fl_path, char *flags)
{
	struct stat buf;
	t_stack *fls;

	fls = NULL;
	fl_path = ft_strjoin("./", fl_path);
	// check to make sure this file path is valid and existent
	if (lstat(fl_path, &buf) < 0)
		error_msg("This is not an actual file! (handle_single_fl)");
	// somehow make it so once fls is returned it points to a printable list element
		// containing the file
	
	// allocating the whole list. Then return only the sought for
	// which is the file of the given file path (fl_path)
	fls = alloc_list(".", flags);
	fls = extr_sought_fl(fls, fl_path);
	return (fls);

}






// This function receives a name and allocates everything in the the current directory into 
// a nice stack. it then returns this stack
// in the case of it being only a file path we check to see if it's valid and reutrn a list with
// the file's info
t_stack			*register_fls_in_dir(char *name, char *flags)
{
	DIR				*dir;
	t_stack			*fls;
	struct dirent	*ent;

	fls = NULL;
	ent = NULL;

	// in the case of the name not actually being a given directory path, but maybe still a valid file path 
	if (!(dir = opendir(name)))
		return (handle_single_fl(name, flags));
	else if ((dir = opendir(name))) // this is the normal case with a normal directory
	{
		if (!(ent = readdir(dir)))
			error_msg("There was a problem with the reading of an entry in the directory ! (register_fls_in_dir)");
	}



	if (!(fls = ft_lstnew(ent, name, flags)))
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
		if (tmp->next)
			tmp->next->prev = tmp;
		tmp->fields = get_file_info(tmp); // extracting all the info
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			tmp->subdir = alloc_list(tmp->path, flags); // recursively calling the function again with the newly made path in the stack elem
		tmp = tmp->next;
	}
	return (fls);
	 // returnning null for now, just testing
}