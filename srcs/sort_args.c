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

/*
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
*/


/*
** creates a list element for the arguments
** along with all the relevant information
*/

t_args			*ft_new_arg(char *dir_path)
{
 // TODO finish

}

char			**sort_args(char **av_tmp)
{
	int i;
	t_args *begin;

	i = 0;
	if (!av_tmp[i])
		error_msg("Error in (sort_args)");
	begin = ft_new_arg(av_tmp[i]); // Maybe convert into respective directory paths
	while (av_tmp[i])
	{
		// This loop will allocate the arguments list while sorting it
	
		// push it onto the arguments stack list whilst sorting
		i++;
	} // Convert av_tmp elems into list elements dynamically
	ft_putnbr(i);




	// free everything


	// copy the sorted list back into an array and then return this array


	return (NULL);
}
