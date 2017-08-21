/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sngl_fl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:15:37 by tbui              #+#    #+#             */
/*   Updated: 2017/07/17 17:15:38 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

T_BOOL				not_curr_and_prev_ch(char *dir_name)
{
	if (ft_strcmp(dir_name, ".") != 0 && ft_strcmp(dir_name, "..") != 0)
		return (TRUE);
	return (FALSE);
}

char				*expend_root(char *fl_path)
{
	char			*tmp;

	tmp = fl_path;
	if (ft_strncmp("./", fl_path, 2) == 0)
		tmp += 2;
	return (tmp);
}

/*
** invokes the recursion of the
** ret_sing_ent function
*/

void				ret_sing_ent_rec(t_stack **fls, char *fl_path, \
char *ent_path, char *flags)
{
	char *nw_path;

	nw_path = NULL;
	nw_path = ft_strjoin(ent_path, "/");
	ret_sing_ent(fls, fl_path, nw_path, flags);
	free(nw_path);
}

/*
** find a single entry and reurns it as a
** stack element
*/

void				ret_sing_ent(t_stack **fls, char *fl_path, \
char *dir_path, char *flags)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*ent_path;

	if (!(dir = opendir(dir_path)))
		error_msg("Could not open directory (ret_sing_ent)");
	while ((ent = readdir(dir)))
	{
		ent_path = ft_strjoin(dir_path, ent->d_name);
		if (ft_strcmp(ent_path, fl_path) == 0)
		{
			free(ent_path);
			(*fls) = ft_lstnew(ent, dir_path, flags);
			free((*fls)->filename);
			fl_path = expend_root(fl_path);
			(*fls)->filename = ft_strdup(fl_path);
			closedir(dir);
			return ;
		}
		if (ent->d_type == DT_DIR && not_curr_and_prev_ch(ent->d_name))
			ret_sing_ent_rec(fls, fl_path, ent_path, flags);
		free(ent_path);
	}
	closedir(dir);
}

t_stack				*handle_single_fl(char *fl_path, char *flags)
{
	struct stat		buf;
	t_stack			*fls;

	fls = NULL;
	if (lstat(fl_path, &buf) < 0)
	{
		ft_putstr("----> ");
		ft_putendl(fl_path);
		error_msg("This is not an actual file! (handle_single_fl)");
	}
	ret_sing_ent(&fls, fl_path, "./", flags);
	fls->fields = get_file_info(fls);
	print_dir(fls, flags);
	free(fl_path);
	return (fls);
}
