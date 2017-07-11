#include "../includes/ft_ls.h"

// takes in the file path and directory path
// then returns a single file entry corresponding to that
// file by looping over every file in the root and all subdirs
struct dirent		*ret_sing_ent(char *fl_path, char *dir_path)
{
	DIR				*dir;
	struct dirent	*ent;
	char 			*ent_path; // the path of the entry


	if (!(dir = opendir(dir_path)))
		error_msg("Could not open directory (register_fls_in_dir)");
	// this loop is going to look for the sought after ent
	while ((ent = readdir(dir)))
	{
		ent_path = ft_strjoin(dir_path, ent->d_name);
		if (ft_strcmp(ent_path, fl_path) == 0)
		{
			free(ent_path);
			return (ent);
		}
		if (ent->d_type == DT_DIR)
		{
			// here is where I invoke the recursion but idk how
//			ent = ret_sing_ent(fl_path, ent_path);
		}
		free(ent_path);
	}
	return (ent);
}

// this function handles the case of a single file path being put in as the main input
t_stack			*handle_single_fl(char *fl_path, char *flags)
{
	struct stat buf;
	t_stack *fls;	
	struct dirent	*ent;

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
	
	ent = ret_sing_ent(fl_path, "./"); // WIP
	ft_putendl(ent->d_name); //TESTING
	fls = alloc_list("./", flags); // TESTING purposes (replace with a function which will return the sought after list elemnt)
	free(fl_path);
	return (fls);

}


