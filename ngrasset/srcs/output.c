/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 12:59:20 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 17:07:54 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	main_output(t_stack *head, char *flags)
{
	while (head && head->type == INVALID)
	{
		log_invalid_elem(head);
		head = head->next;
	}
	if (flags[f_list])
		list_output(head);
	else
		simple_output(head);
}

void	simple_output(t_stack *head)
{
	while (head)
	{
		ft_putendl(head->filename);
		head = head->next;
	}
}

void	list_output(t_stack *head)
{
	size_t	padding[5];

	find_padding(head, padding);
	while (head)
	{
		put_field(head->fields->mode);
		put_field_padding(head->fields->links, padding[0], 0);
		put_field_padding(head->fields->owner, padding[1], 1);
		put_field_padding(head->fields->group, padding[2], 1);
		if (head->fields->major)
		{
			put_field_padding(head->fields->major, padding[3], 2);
			put_field_padding(head->fields->size, padding[4], 0);
		}
		else
			put_field_padding(head->fields->size,
				(padding[3] != 0 ? padding[3] + 2 : 0) + padding[4], 0);
		put_field(head->fields->date);
		put_name(head);
		head = head->next;
	}
}
