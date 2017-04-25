/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 16:05:18 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/26 16:19:23 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_stack		*stack_new_elem(char *path, char *filename)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->next = NULL;
	if (!filename)
		new->filename = ft_strdup(path);
	else
		new->filename = ft_strdup(filename);
	new->path = join_path(path, filename);
	if (lstat(new->path, &(new->stats)) == -1)
	{
		new->type = INVALID;
		new->fields = NULL;
		new->err_msg = ft_strdup(strerror(errno));
		return (new);
	}
	new->type = find_file_type(new->stats.st_mode);
	new->fields = create_fields(new->stats, new->type);
	new->err_msg = NULL;
	return (new);
}

void		stack_delete_elem(t_stack *elem)
{
	if (!elem)
		return ;
	if (elem->path)
		free(elem->path);
	if (elem->filename)
		free(elem->filename);
	if (elem->fields)
		delete_fields(elem->fields);
	if (elem->err_msg)
		free(elem->err_msg);
	free(elem);
}

void		stack_delete_list(t_stack **head)
{
	t_stack		*cur;
	t_stack		*next;

	if (!head || (head && !*head))
		return ;
	cur = *head;
	while (cur)
	{
		next = cur->next;
		stack_delete_elem(cur);
		cur = next;
	}
	*head = NULL;
}

void		delete_fields(t_fields *f)
{
	if (!f)
		return ;
	if (f->mode)
		free(f->mode);
	if (f->links)
		free(f->links);
	if (f->owner)
		free(f->owner);
	if (f->group)
		free(f->group);
	if (f->size)
		free(f->size);
	if (f->date)
		free(f->date);
	free(f);
}
