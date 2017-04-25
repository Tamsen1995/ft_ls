/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:45:41 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:53:13 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int ac, char **av)
{
	char	flags[NB_FLAGS];
	int		i;
	t_stack	*files;
	t_stack	*directories;
	t_stack	*new;

	i = parse_flags(ac, av, flags);
	files = NULL;
	directories = NULL;
	while (i < ac)
	{
		new = stack_new_elem(av[i], NULL);
		if (new->type == SYM_LINK && !flags[f_list])
			redirect_symlink(new);
		if (new->type == DIRECTORY)
			stack_push_ordered(&directories, new, flags);
		else
			stack_push_ordered(&files, new, flags);
		i++;
	}
	list_main(files, (!(directories || files) ?
		stack_new_elem(".", NULL) : directories), flags);
	return (0);
}

void	redirect_symlink(t_stack *elem)
{
	struct stat		target;

	if (stat(elem->path, &(target)) == -1)
		return ;
	if (find_file_type(target.st_mode) != DIRECTORY)
		return ;
	elem->type = DIRECTORY;
}
