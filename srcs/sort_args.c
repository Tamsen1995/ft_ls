/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:28:25 by tbui              #+#    #+#             */
/*   Updated: 2017/07/17 16:28:29 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_filetype		get_type_from_path(char *path)
{
	struct stat		buf;
	mode_t			type;

	path = make_dir_path(path);
	lstat(path, &buf);
	type = buf.st_mode;
	free(path);
	if (S_ISDIR(type))
		return (DIRECTORY);
	return (INVALID);
}

T_BOOL			sorted(char **array)
{
	int				i;
	int				k;
	t_filetype		type_i;
	t_filetype		type_k;

	i = 0;
	k = 1;
	while (array[k] && array[i])
	{
		type_i = get_type_from_path(array[i]);
		type_k = get_type_from_path(array[k]);
		if (ft_strcmp(array[i], array[k]) > 0 &&\
			((type_i == INVALID && type_k == INVALID) ||\
			(type_i == DIRECTORY && type_k == DIRECTORY)))
			return (FALSE);
		if (type_k == INVALID && type_i == DIRECTORY)
			return (FALSE);
		i++;
		k++;
	}
	return (TRUE);
}

T_BOOL			cmp_args(char *arg_one, char *arg_two)
{
	t_filetype type_one;
	t_filetype type_two;

	type_one = get_type_from_path(arg_one);
	type_two = get_type_from_path(arg_two);
	if (ft_strcmp(arg_one, arg_two) > 0 &&\
		((type_one == INVALID && type_two == INVALID) ||\
		(type_one == DIRECTORY && type_two == DIRECTORY)))
		return (TRUE);
	if (type_two == INVALID && type_one == DIRECTORY)
		return (TRUE);
	return (FALSE);
}

char			**swap_arr(char **av_tmp, int arg_one, int arg_two)
{
	char *tmp;

	tmp = NULL;
	tmp = av_tmp[arg_one];
	av_tmp[arg_one] = av_tmp[arg_two];
	av_tmp[arg_two] = tmp;
	return (av_tmp);
}

char			**sort_args(char **av_tmp)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (sorted(av_tmp) == FALSE)
	{
		i = 0;
		k = 1;
		while (av_tmp[k])
		{
			if (cmp_args(av_tmp[i], av_tmp[k]))
				av_tmp = swap_arr(av_tmp, i, k);
			i++;
			k++;
		}
	}
	return (av_tmp);
}
