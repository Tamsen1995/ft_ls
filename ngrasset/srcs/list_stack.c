/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:52:28 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:44:04 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	list_main(t_stack *files, t_stack *directories, char *flags)
{
	t_stack		*save_files;

	save_files = files;
	if (directories && directories->next == NULL && !files)
	{
		list_dir(directories->path, flags);
		stack_delete_list(&directories);
		return ;
	}
	while (files && files->type == INVALID)
	{
		log_invalid_elem(files);
		files = files->next;
	}
	main_output(files, flags);
	if (files && directories)
		ft_putchar('\n');
	list_each_dir(directories, flags);
	stack_delete_list(&save_files);
	stack_delete_list(&directories);
}

int		ignore_folder(char *str)
{
	if (ft_strcmp(str, ".") == 0)
		return (1);
	if (ft_strcmp(str, "..") == 0)
		return (1);
	return (0);
}

void	dir_fill_stack(char *p, t_stack **output, t_stack **folders, char *f)
{
	DIR				*dirp;
	struct dirent	*elem;

	dirp = opendir(p);
	if (!dirp)
	{
		log_opendir(p, strerror(errno));
		return ;
	}
	while ((elem = readdir(dirp)))
	{
		if (elem->d_name[0] != '.' || f[f_hidden])
		{
			stack_push_ordered(output, stack_new_elem(p, elem->d_name), f);
			if (elem->d_type == DT_DIR && f[f_recur] &&
				!ignore_folder(elem->d_name))
				stack_push_ordered(folders, stack_new_elem(p, elem->d_name), f);
		}
	}
	closedir(dirp);
}

void	list_dir(char *path, char *flags)
{
	t_stack			*folders;
	t_stack			*output;

	output = NULL;
	folders = NULL;
	dir_fill_stack(path, &output, &folders, flags);
	if (flags[f_list] && output)
		log_total_size(output);
	main_output(output, flags);
	stack_delete_list(&output);
	if (folders)
		ft_putchar('\n');
	list_each_dir(folders, flags);
	stack_delete_list(&folders);
}

void	list_each_dir(t_stack *head, char *flags)
{
	while (head)
	{
		if (head->type == INVALID)
		{
			log_invalid_elem(head);
			head = head->next;
			continue ;
		}
		log_folder(head->path);
		list_dir(head->path, flags);
		if (head->next)
			ft_putchar('\n');
		head = head->next;
	}
}
