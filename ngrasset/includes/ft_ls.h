/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 16:05:26 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:53:33 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <dirent.h>
# define VALID_FLAGS	"Ralrt1"
# define NB_FLAGS		6

typedef enum		e_flags
{
	f_recur = 0,
	f_hidden = 1,
	f_list = 2,
	f_rev = 3,
	f_time = 4,
	f_main = 5
}					t_flags;

typedef enum		e_filetype
{
	BLOCK,
	CHAR_SP,
	DIRECTORY,
	SYM_LINK,
	SOCK_LINK,
	FIFO,
	REG,
	INVALID
}					t_filetype;

typedef struct		s_fields
{
	char			*mode;
	char			*links;
	char			*owner;
	char			*group;
	char			*major;
	char			*size;
	char			*date;
}					t_fields;

typedef struct		s_stack
{
	char			*path;
	char			*filename;
	t_filetype		type;
	struct stat		stats;
	t_fields		*fields;
	char			*err_msg;
	struct s_stack	*next;
}					t_stack;

void				log_flags(char arg);
void				log_invalid_elem(t_stack *elem);
void				log_opendir(char *file, char *err);
void				log_folder(char *path);
void				log_total_size(t_stack *head);
void				init_flags(char *flags);
int					parse_flags(int ac, char **av, char *flags);
int					flag_index(char c);
t_stack				*stack_new_elem(char *path, char *filename);
void				stack_delete_elem(t_stack *elem);
void				stack_delete_list(t_stack **head);
void				delete_fields(t_fields *f);
void				redirect_symlink(t_stack *elem);
t_fields			*create_fields(struct stat stats, t_filetype type);
char				*mode_to_str(mode_t st_mode, t_filetype type);
char				*uid_to_str(uid_t uid);
char				*gid_to_str(gid_t gid);
char				*date_to_str(time_t clock);
t_filetype			find_file_type(mode_t mode);
char				filetype_to_char(t_filetype t);
char				*join_path(char *s1, char *s2);
void				stack_push_ordered(t_stack **head, t_stack *new,
						char *flags);
int					sort_stack(t_stack *s1, t_stack *s2, char *flags);
void				list_main(t_stack *files, t_stack *directories,
						char *flags);
void				list_dir(char *path, char *flags);
void				list_each_dir(t_stack *head, char *flags);
int					ignore_folder(char *str);
void				dir_fill_stack(char *p, t_stack **output,
						t_stack **folders, char *f);
void				main_output(t_stack *head, char *flags);
void				simple_output(t_stack *head);
void				list_output(t_stack *head);
void				find_padding(t_stack *head, size_t *padding);
int					find_total_size(t_stack *head);
void				put_field(char *str);
void				put_field_padding(char *str, size_t size, int right);
void				put_name(t_stack *elem);
#endif
