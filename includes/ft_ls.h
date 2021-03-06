/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:33:36 by tbui              #+#    #+#             */
/*   Updated: 2017/09/11 21:57:42 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../includes/libft.h"
# include <dirent.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>

t_args				*ft_new_arg(char *name);
int					args_sorting(t_args *s1, t_args *s2, char *flags);
void				ft_args_push_back(t_args **begin, char *name, char *flags);
void				perm_denied(t_stack *file);
void				print_dir_path_recur(t_stack *file, char *flags);
void				print_total_blocks_cur(t_stack *file, char *flags);
T_BOOL				path_no_access(t_stack *alist);
void				free_list(t_stack *list, char *flags);
T_BOOL				directory_no_access(t_stack *elem);
t_fields			*alloc_fields(void);
void				ret_sing_ent(t_stack **fls, char *fl_path, \
char *dir_path, char *flags);
void				free_list_elem(t_stack *tmp);
char				*make_dir_path(char *dir_path);
char				**sort_args(char **av_tmp, char *flags);
char				**check_args_for_dirs(char **av_tmp, int i, int ac);
T_BOOL				is_valid_folder(char *path);
char				**copy_args(int ac, char **av);
void				free_twod_arr(char **arr);
t_stack				*extr_sought_fl(t_stack *fls, char *fl_path);
t_stack				*handle_single_fl(char *fl_path, char *flags);
void				print_total_blocks(char *dir_path, char *flags);
T_BOOL				is_hidden_file(t_stack *file);
void				print_list(t_stack *file, char *flags);
void				print_flags(t_stack *file, char *flags);
void				print_dir(t_stack *files, char *flags);
void				output_module(t_stack *files, char *flags);
char				*extract_nbr_of_links(struct stat buf);
char				*extract_file_size(struct stat buf);
char				*isolate_date_time(char *temps);
void				extract_date_time(struct stat buf, t_fields *fields);
char				*extract_group(struct stat buf);
char				*extract_owner(struct stat buf);
void				extract_permissions_mode(struct stat file_stat,\
t_stack *file);
t_fields			*alloc_fields(void);
t_fields			*get_file_info(t_stack *file);
void				print_dir_path(t_stack *file, char *flags);
char				*make_path_dir(char *name, char *cathis);
t_stack				*register_fls_in_dir(char *name, char *flags);
T_BOOL				not_curr_and_prev(t_stack *entry);
void				out_entire_stack(t_stack *stack, char *flags);
int					parse_flags(int ac, char **av, char *flags);
t_stack				*alloc_list(char *name, char *flags);
t_flags				*get_flags(int argc, char **argv);
char				*make_path_dir(char *name, char *cathis);
int					ft_init_flags(t_flags **flags);
void				det_flags(char *flag, t_flags **flags);
void				big_r(DIR *rep);

#endif
