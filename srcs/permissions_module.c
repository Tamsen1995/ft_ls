#include "ft_ls.h"


char		*make_path_fl(char *dir, char *file)
{
	char *nw_path;
	size_t l; //length for new path

	l = ft_strlen(dir) + ft_strlen(file);
	l = l + 1;
	nw_path = NULL;
	if (!(nw_path = (char *)malloc(sizeof(char) * l)))
		return (NULL);
	nw_path = ft_strcpy(nw_path, dir);
	nw_path = ft_strcat(nw_path, "/");
	nw_path = ft_strcat(nw_path, file);
	//ft_printf("\n------>%s\n", nw_path);
	return (nw_path);


}

void		print_perms(t_files *fls)
{
    ft_printf( (S_ISDIR(fls->st_mode)) ? "d" : "-");
    ft_printf( (fls->st_mode & S_IRUSR) ? "r" : "-");
    ft_printf( (fls->st_mode & S_IWUSR) ? "w" : "-");
    ft_printf( (fls->st_mode & S_IXUSR) ? "x" : "-");
    ft_printf( (fls->st_mode & S_IRGRP) ? "r" : "-");
    ft_printf( (fls->st_mode & S_IWGRP) ? "w" : "-");
    ft_printf( (fls->st_mode & S_IXGRP) ? "x" : "-");
    ft_printf( (fls->st_mode & S_IROTH) ? "r" : "-");
    ft_printf( (fls->st_mode & S_IWOTH) ? "w" : "-");
    ft_printf( (fls->st_mode & S_IXOTH) ? "x" : "-");

}
