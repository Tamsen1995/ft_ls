#include "../includes/ft_ls.h"

//This function recursively otuputs all the stack elements in the stack
// This is the current treatment for the -R flag and -R flag only
void    out_entire_stack(t_stack *stack)
{
	
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion

    tmp = NULL;
	tmp = stack;
	while (tmp)
	{
        ft_putendl(tmp->filename);
        // If there is a subdir
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DT_DIR)
		{
			out_entire_stack(tmp->subdir); // recursively calling the function again with the newly made path in the stack elem
		}
		tmp = tmp->next; 
	}
}