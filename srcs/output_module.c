#include "ft_ls.h"

void		print_spaces(char *name)
{
	size_t l;
	size_t spcs;
	size_t i;

	l = ft_strlen(name);
	spcs = 20;
	i = 0;
	spcs = spcs - l;
	while (i <= spcs)
	{
		ft_putchar(' ');
		i++;
	}
}

void		print_grp_usrs(t_files *fls)
{
	struct passwd *usrstruct;
	struct group *grpstruct;

	if ((usrstruct = getpwuid(fls->st_uid)) == NULL)
		return ;
	if ((grpstruct = getgrgid(fls->st_gid)) == NULL)
		return ;
	ft_putstr("\t");
	ft_putstr(usrstruct->pw_name);
	ft_putstr("\t");
	ft_putstr(grpstruct->gr_name);
//	free(usrstruct);
}

void		print_size(t_files *fls)
{
	ft_putstr(" ");
	ft_putnbr((int) fls->st_size);
}



void		print_time(t_files *fls)
{
	char *c_time_string;

	ft_putstr(" "); //continue here
	c_time_string = ctime(&fls->mtime);
	if (!c_time_string)
		return ;
	ft_putstr("\t");
	extract_proper_time(c_time_string, fls);//extracts month, day, time
	//ft_putstr(proper_time);
}


//this is in a loop in both the recursion as well as the normal ls
void		print_flags(t_files *fls, t_flags *flags)
{
	if (flags->l)
	{
		print_perms(fls); //permissions_module
		print_grp_usrs(fls);
		print_size(fls);
		//print_time(fls); // there are about a million bugs in this module
		print_spaces(fls->ent->d_name);
	}
}

void		normal_ls(t_files *files, t_flags *flags) //not considering the -a case
{
	t_files *tmp;

	tmp = files;
	while (tmp)
	{
		if ((ft_strncmp(tmp->ent->d_name, ".", 1) == 0 || ft_strcmp(tmp->ent->d_name, "..") == 0) && flags->a == FALSE)// && ft_strcmp(tmp->ent->d_name, ".") == 0)
			tmp = tmp->next;
		else
		{
			print_flags(tmp, flags);
			ft_putendl(tmp->ent->d_name);
		}
		tmp = tmp->next;
	}
	return ;
}

// here we pass a temp pointer which is actually a pointer TO the main list we're working with
void print_files(t_files *tmp, t_flags *flags) {
	while (tmp)
	{
		if ((ft_strcmp(tmp->file_name, ".") == 0 || ft_strcmp(tmp->file_name, "..") == 0) && flags->a == TRUE)
			ft_putendl(tmp->file_name);
		if ((ft_strcmp(tmp->file_name, ".") != 0 && ft_strcmp(tmp->file_name, "..") != 0))
			ft_putendl(tmp->file_name);
		tmp  = tmp->next;
	}
}

void		print_all_test(t_files *files, t_flags *flags)//testing?!
{
	t_files *tmp;
	tmp = files;




	print_files(tmp, flags); //this function prints the files in a directory
	while (tmp) {
		if ((tmp->ent->d_type == DT_DIR) && (ft_strcmp(tmp->file_name, ".") != 0 && ft_strcmp(tmp->file_name, "..") != 0))
		{
			ft_putstr("\n\n");
			//if (tmp->dir_path)
			if (tmp->dir_path)	
			{
				ft_putstr(tmp->dir_path);
				ft_putstr(":\n");
			}
			print_all_test(tmp->subdir, flags);
		}
		tmp = tmp->next;
	}
	return ;
}
