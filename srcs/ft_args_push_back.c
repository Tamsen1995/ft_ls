#include "../includes/ft_ls.h"

/*
** INVALID overrides everything
** rev overrides everything in the
** sense that it cooperates with the given condition
*/

int			args_sorting(t_args *s1, t_args *s2, char *flags)
{
	time_t s1_time;
	time_t s2_time;

	s1_time = s1->stats.st_mtimespec.tv_sec;
	s2_time = s2->stats.st_mtimespec.tv_sec;
	if (s1->type == INVALID && s2->type != INVALID)
		return (-1);
	if (s1->type != INVALID && s2->type == INVALID)
		return (1);
	if (flags[f_time] && s1->type != INVALID && s2->type != INVALID
	&& s1_time != s2_time)
	{
		if (flags[f_rev])
			return (s1_time - s2_time);
		return (s2_time - s1_time);
	}
	if (flags[f_rev])
		return (ft_strcmp(s2->name, s1->name));
	return (ft_strcmp(s1->name, s2->name));
}

/*
** almost identical in logic to the
** push_back function for the files
** but is responsible for the sorting of
** the initial arguments
*/

void		ft_args_push_back(t_args **begin_list, char *name, char *flags)
{
	t_args *cur;
	t_args *prev;
	t_args *new;

	new = ft_new_arg(name);
	prev = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_arg(name);
		return ;
	}
	cur = *begin_list;
	if (args_sorting(cur, new, flags) > 0)
	{
		new->next = cur;
		*begin_list = new;
		return ;
	}
	while (cur && args_sorting(cur, new, flags) <= 0)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
}
