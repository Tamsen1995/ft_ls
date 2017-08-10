#include "../includes/ft_ls.h"

void			free_list(t_stack *list)
{
	t_stack *tmp;

	tmp = NULL;
	if (!list)
		error_msg("Error in the freeing of the list");
	tmp = list;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			free_list(tmp->subdir);
		free_list_elem(tmp);
	}
	free(list);
	return ;
}