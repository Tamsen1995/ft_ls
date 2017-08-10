#include "../includes/ft_ls.h"

void			extract_permissions_mode(struct stat buf, t_stack *file)
{
	char		*string;

	string = file->fields->mode;
	string[0] = *((S_ISDIR(buf.st_mode)) ? "d" : "-");
	if (file->type == SYMLINK)
		string[0] = 'l';
	else if (file->type == FIFO)
		string[0] = 'p';
	else if (file->type == SOCK_LINK)
		string[0] = 's';
	string[1] = *((buf.st_mode & S_IRUSR) ? "r" : "-");
	string[2] = *((buf.st_mode & S_IWUSR) ? "w" : "-");
	string[3] = *((buf.st_mode & S_IXUSR) ? "x" : "-");
	string[4] = *((buf.st_mode & S_IRGRP) ? "r" : "-");
	string[5] = *((buf.st_mode & S_IWGRP) ? "w" : "-");
	string[6] = *((buf.st_mode & S_IXGRP) ? "x" : "-");
	string[7] = *((buf.st_mode & S_IROTH) ? "r" : "-");
	string[8] = *((buf.st_mode & S_IWOTH) ? "w" : "-");
	string[9] = *((buf.st_mode & S_IXOTH) ? "x" : "-");
	string[10] = '\0';
}