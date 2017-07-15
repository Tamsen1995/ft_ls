#include "../includes/ft_ls.h"

// same as the initial not current not prev
// but for character strings
t_bool		not_curr_and_prev_ch(char *dir_name)
{
	if (ft_strcmp(dir_name, ".") != 0 && ft_strcmp(dir_name, "..") != 0)
		return (TRUE);
	return (FALSE);
}


// This function takes in the file path and gets rid of the "./" in the beginning
// This is essential as a filename starting with "./"
// Will be recognized as a hidden file
char		*expend_root(char *fl_path)
{
	char *tmp;

	tmp = fl_path;
	if (ft_strncmp("./", fl_path, 2) == 0)
		tmp += 2;
//	ft_putendl(tmp); // TESTING

	return (tmp);
}

// takes in the file path and directory path
// then returns a single file entry corresponding to that
// file by looping over every file in the root and all subdirs
void		ret_sing_ent(t_stack **fls, char *fl_path, char *dir_path, char *flags)
{
	DIR				*dir;
	struct dirent	*ent;
	char 			*ent_path; // the path of the entry
	char 			*nw_path;

	nw_path = NULL;
	if (!(dir = opendir(dir_path)))
		error_msg("Could not open directory (ret_sing_ent)");
	// this loop is going to look for the sought after ent
	while ((ent = readdir(dir)))
	{		
		ent_path = ft_strjoin(dir_path, ent->d_name);
		if (ft_strcmp(ent_path, fl_path) == 0)
		{
			free(ent_path);
			(*fls) = ft_lstnew(ent, dir_path, flags);
			free((*fls)->filename);
			fl_path = expend_root(fl_path); // WIP
			(*fls)->filename = ft_strdup(fl_path); // TODO get rid of the directory path in the beginning "./"
			closedir(dir);
			return ;
		}
		if (ent->d_type == DT_DIR && not_curr_and_prev_ch(ent->d_name))
		{
			nw_path = ft_strjoin(ent_path, "/");
			ret_sing_ent(fls, fl_path, nw_path, flags); // Gotta figure out why the passing of the dir_path doesn't function
			free(nw_path);
		}
		free(ent_path);
	}
	closedir(dir);
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
	// TODO somehow make it so once fls is returned it points to a printable list element
	// containing the file
	ret_sing_ent(&fls, fl_path, "./", flags); // WIP
	fls->fields = get_file_info(fls);
	free(fl_path);
	return (fls);

}


