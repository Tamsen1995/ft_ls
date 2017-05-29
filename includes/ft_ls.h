#ifndef FT_LS_H
# define FT_LS_H

# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGLIGHT "\033[47m"
# define BGGRAY "\033[47m"



# include				"../includes/libft.h"
# include				<dirent.h>
# include				<unistd.h>
# include				<pwd.h>
# include				<grp.h>
# include				<time.h>
# include				<sys/stat.h>
# include				<sys/types.h>
# include				<errno.h>



void                print_total_blocks(t_stack *file, char *flags);
t_bool		        is_hidden_file(t_stack *file);
void		        print_list(t_stack *file);
void        		print_flags(t_stack *file, char *flags);
void		        print_dir(t_stack *files, char *flags);

void                output_module(t_stack *files, char *flags);
char                *extract_nbr_of_links(struct stat buf);
char                *extract_file_size(struct stat buf);
char                *isolate_date_time(char *temps);
void                extract_date_time(struct stat buf, t_fields *fields);
char                *extract_group(struct stat buf);
char                *extract_owner(struct stat buf);
void                extract_permissions_mode(struct stat fileStat, t_stack *file);
t_fields            *alloc_fields(void);
t_fields			*get_file_info(t_stack *file);

void        error_msg(char *message);
void	    print_dir_path(t_stack *file, char *flags);
char		*make_path_dir(char *name, char *cathis);
t_stack     *register_fls_in_dir(char *name, char *flags);
t_bool		not_curr_and_prev(t_stack *entry);
void    out_entire_stack(t_stack *stack, char *flags);
int		    parse_flags(int ac, char **av, char *flags);
void		extract_proper_time(char *c_time_string, t_files *fls);
void		print_yr_only(t_files *fls);
void		print_time(t_files *fls);
void		print_perms(t_files *fls);
t_stack		*alloc_list(char *name,char *flags);
t_flags		*get_flags(int argc, char **argv);
char		*make_path_dir(char *name, char *cathis);
void		print_all_test(t_files *files, t_flags *flags);//testing?!
int			ft_init_flags(t_flags **flags);
void		det_flags(char *flag, t_flags **flags);
void		big_r(DIR *rep);
void		normal_ls(t_files *fls, t_flags *flags);
void		assess_output(t_files *files, t_flags *flags);


#endif