#include "ft_ls.h"

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

t_files			*alloc_list(char *name)
{
	DIR				*dir;
	t_files			*fls;
	struct dirent	*ent;
	t_files			*tmp;//testing

	tmp = NULL;
	fls = NULL;
	if (!(dir = opendir(name))) //opening the directory with the name
		return (NULL);
	if (!(ent = readdir(dir))) //entry read from the directory itself
		return (NULL);
		 //making a new struct to add onto the list
	if (!(fls = ft_lstnew(ent, name)))	//with all the info of the file
		return (NULL);
	while ((ent = readdir(dir)))
	{
		if (ft_strcmp(ent->d_name, "..") != 0 && ft_strcmp(ent->d_name, ".") != 0)
			ft_list_push_back(&fls, ent, name);
	}
	tmp = fls;
	while (tmp)
	{

		// If the current entry is a directory but not the current one (.) and neither the previous one
		if (tmp->ent->d_type == DT_DIR && ft_strcmp(tmp->file_name, ".") != 0)// && ft_strcmp(tmp->file_name, "..") != 0))
			tmp->subdir = alloc_list(make_path_dir(name, tmp->ent->d_name));
		tmp = tmp->next;
	}
	return (fls);
}
