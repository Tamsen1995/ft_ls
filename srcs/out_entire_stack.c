#include "../includes/ft_ls.h"

//This function recursively otuputs all the stack elements in the stack
// This is the current treatment for the -R flag and -R flag only
void    out_entire_stack(t_stack *stack, char *flags)
{
	
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion

    tmp = NULL;
	tmp = stack;

    flags = NULL; // leaving flags at null JUST FOR NOW because I haven't figured out how exactly to treat them in regards to the output yet

	while (tmp)
	{
     //   ft_putendl(tmp->filename); // This will be replaced by the making and putting out of a buffer. The buffer will contain all the information the flags given demand
        // If there is a subdir
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DT_DIR)
		{
			out_entire_stack(tmp->subdir, flags); // recursively calling the function again with the newly made path in the stack elem
        
        }
		tmp = tmp->next; 
	}
}