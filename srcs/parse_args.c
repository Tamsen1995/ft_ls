/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:46:36 by tbui              #+#    #+#             */
/*   Updated: 2017/07/17 16:46:37 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			**copy_args(int ac, char **av)
{
	char		**av_tmp;
	char		**tmp;
	int			i;

	i = 0;
	av_tmp = NULL;
	tmp = NULL;
	if (!(av_tmp = (char **)malloc(sizeof(char *) * ac)))
		error_msg("Error in the copying of arguments ! (copy_args)");
	tmp = av_tmp;
	while (i < ac)
	{
		(*tmp) = ft_strdup(av[i]);
		tmp++;
		i++;
	}
	return (av_tmp);
}

T_BOOL			is_valid_folder(char *path)
{
	struct stat		buf;
	char			*dir_path;

	dir_path = ft_strjoin("./", path);
	if (lstat(dir_path, &buf) == 0 || ft_strncmp("/", path, 1) == 0)
	{
		free(dir_path);
		return (TRUE);
	}
	free(dir_path);
	return (FALSE);
}

T_BOOL			flags_absent(char *flags)
{
	int i;

	i = 0;
	while (i < NB_FLAGS)
	{
		if (flags[i] == 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

T_BOOL			inv_fls_present(char **av_tmp, int i, int ac)
{
	T_BOOL		flag;
	struct stat buf;
	DIR			*dir;
	char		*dir_path;

	flag = FALSE;
	dir = NULL;
	while (i < ac && av_tmp[i])
	{
		dir_path = ft_strjoin("./", av_tmp[i]);
		if (!(dir = opendir(av_tmp[i])) && lstat(dir_path, &buf) < 0)
		{
			ft_putstr("No such file or directory:\t");
			ft_putendl(av_tmp[i]);
			flag = TRUE;
		}
		free(dir_path);
		if (dir)
			closedir(dir);
		free(av_tmp[i]);
		i++;
	}
	return (flag);
}

/*
** Makes a copy of all the potential directories
** in the arguments array and copies it into
** a directory array
** Also outputs an error message in case an invalid directory
** was inputted
*/

char			**check_args_for_dirs(char **av_tmp, int i, int ac)
{
	char		**dir_arr;
	int			k;
	int			j;

	dir_arr = NULL;
	k = 0;
	j = 0;
	if (!(dir_arr = (char **)malloc(sizeof(char *) * ac + 1)))
		error_msg("ERROR: (check_args_for_dir)");
	while (i < ac && av_tmp[i])
	{
		if (is_valid_folder(av_tmp[i]) == TRUE)
		{
			dir_arr[k] = ft_strdup(av_tmp[i]);
			k++;
		}
		i++;
		j++;
	}
	i = i - j;
	if (inv_fls_present(av_tmp, i, ac) && k <= 0)
		error_msg("");
	dir_arr[k] = NULL;
	free(av_tmp);
	return (dir_arr);
}
