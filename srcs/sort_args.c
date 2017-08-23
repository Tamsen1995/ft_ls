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


char			**swap_arr(char **av_tmp, int arg_one, int arg_two)
{
	char *tmp;

	tmp = NULL;
	//tmp = av_tmp[arg_one];
	//av_tmp[arg_one] = av_tmp[arg_two];
	//av_tmp[arg_two] = tmp;

	//tmp = ft_strdup(av_tmp[arg_one]);
	//av_tmp[arg_one] = ft_strdup(av_tmp[arg_two]);
	//av_tmp[arg_two] = ft_strdup(tmp);
	return (av_tmp);
}

char			**sort_args(char **av_tmp)
{

}
