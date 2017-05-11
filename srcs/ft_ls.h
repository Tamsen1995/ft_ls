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


# define VALID_FLAGS	"Ralrt1"
# define NB_FLAGS		6

typedef enum e_flgs
{
	f_recur = 0, // -R
	f_hidden = 1, // -a
	f_list = 2, // -l
	f_rev = 3, //  -r
	f_time = 4, // -t
	f_main = 5 // for bonuses //modify later
}			t_flags;

typedef enum e_filetype
{
	BLOCK, 
	CHAR_SP,
	DIRECTORY,
	SYMLINK,
	SOCK_LINK,
	FIFO,
	REG,
	INVALID
}			t_filetype;


typedef struct 		s_fields
{
	char			*mode;
	char 			*links;
	char			*owner;
	char 			*group;
	char			*major;
	char			 *size;
	char 			*date;
}					t_fields;

typedef struct		 s_stack
{
	char 			*path;
	char 			*filename;
	t_filetype 		type;
	struct stat 	stats;
	t_fields 		*fields;
	char 			*err_msg;
	struct s_stack 	*next;
}					t_stack;



int		parse_flags(int ac, char **av, char *flags);
int 		flag_index(char c);
void	init_flags(char *flags);
void	log_flags(char arg);
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