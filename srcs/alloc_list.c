#include "../includes/ft_ls.h"

char			*make_path_dir(char *name, char *cathis)
{
	char *nw_path;
	size_t l; //length for new path

	l = ft_strlen(name) + ft_strlen(cathis);
	l = l + 1;
	nw_path = NULL;
	if (!(nw_path = (char *)malloc(sizeof(char) * l)))
		return (NULL);
	nw_path = ft_strcpy(nw_path, name);
	nw_path = ft_strcat(nw_path, "/");
	nw_path = ft_strcat(nw_path, cathis);
	return (nw_path);
}

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
		return (NULL);
	if (!(ent = readdir(dir)))
		return (NULL);
	if (!(fls = ft_lstnew(ent, name)))
		return (NULL);

	while ((ent = readdir(dir)))
			ft_list_push_back(&fls, ent, name);
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


// This function acts an extractor of information
// It extracts all the necessary information from a file by redirecting to subfunctions which will be respoinsible
// for extracting the specific information
t_stack			*get_file_info(t_stack *file)
{

	return (file);

}

// This function recursively allocates the entirety of the directory as well as its subdirectories
t_stack			*alloc_list(char *dir_path)
{
	t_stack			*fls;
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion


	tmp = NULL;
	fls = NULL;
	if (!(fls = register_fls_in_dir(dir_path))) // zapping the entire entry list into a stack chain
		return (NULL);
	tmp = fls;
	while (tmp)
	{

		// implement a function HERE which will extract information out of the file INTO the stack element
		tmp = get_file_info(tmp);
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DT_DIR)
		{
			tmp->path = make_path_dir(dir_path, tmp->filename); //putting the directory path into the stack element
			tmp->subdir = alloc_list(tmp->path); // recursively calling the function again with the newly made path in the stack elem
		}
		tmp = tmp->next; 
	}
	return (fls); // returnning null for now, just testing
}