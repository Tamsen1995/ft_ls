#include "../includes/ft_ls.h"


// all this function does is iterate through the list and then
// returns the file sought after
// which should be the single file input
t_stack			*extr_sought_fl(t_stack *fls, char *fl_path)
{
	t_stack		*tmp;

	tmp = fls;
	// while the filepath does not match the tmp->path

	while (tmp->next && ft_strcmp(tmp->path, fl_path) != 0)
	{

		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			extr_sought_fl(tmp->subdir, fl_path);
		tmp = tmp->next;
	}
	// freeing everything after the sought after element
	tmp->next = NULL;
	return (tmp);
}


// this function handles the case of a single file path being put in as the main input
t_stack			*handle_single_fl(char *fl_path, char *flags)
{
	struct stat buf;
	t_stack *fls;

	fls = NULL;
	// check to make sure this file path is valid and existent
	if (lstat(fl_path, &buf) < 0)
	{
		ft_putstr("----> ");
		ft_putendl(fl_path);
		error_msg("This is not an actual file! (handle_single_fl)");
	}
	// somehow make it so once fls is returned it points to a printable list element
		// containing the file
	
	// allocating the whole list. Then return only the sought for
	// which is the file of the given file path (fl_path)
	fls = alloc_list(".", flags);
	fls = extr_sought_fl(fls, fl_path);
	free(fl_path);
	return (fls);

}


