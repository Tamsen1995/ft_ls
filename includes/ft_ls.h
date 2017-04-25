#ifndef FT_LS_H
# define FT_LS_H

# include				"get_next_line.h"
# include				"ft_printf.h"
# include				"libft.h"
# include				<dirent.h>
# include				<unistd.h>
# include				<pwd.h>
# include				<grp.h>
# include				<time.h>
# include				<sys/stat.h>
# include				<sys/types.h>
# include				<errno.h>

typedef	struct		s_flags
{
	t_bool			big_r;
	t_bool			small_r;
	t_bool			l;
	t_bool			a;
	t_bool			t;
}					t_flags;


void		extract_proper_time(char *c_time_string, t_files *fls);
void		print_yr_only(t_files *fls);
void		print_time(t_files *fls);
char		*make_path_fl(char *dir, char *file);
void		print_perms(t_files *fls);
char		*make_path_fl(char *dir, char *file);
t_files		*alloc_list(char *name);
t_flags		*get_flags(int argc, char **argv);
char		*make_path_dir(char *name, char *cathis);
void		print_all_test(t_files *files, t_flags *flags);//testing?!
int			ft_init_flags(t_flags **flags);
void		det_flags(char *flag, t_flags **flags);
void		big_r(DIR *rep);
void		normal_ls(t_files *fls, t_flags *flags);
void		assess_output(t_files *files, t_flags *flags);


#endif