#include "../includes/ft_ls.h"

/*
typedef enum e_flgs
{
	f_recur = 0,
	f_hidden = 1,
	f_list = 2,
	f_rev = 3,
	f_time = 4,
	f_main = 5
}			t_flags;
*/


// this outputs the directory along with the requested flags
void		print_dir(t_stack *files, char *flags)
{
	t_stack *tmp;

	tmp = files;
	flags = NULL; // TESTING 
	while (tmp)
	{
		ft_putendl(tmp->filename);
		tmp = tmp->next;
	}
}



// This is where the entire logic of the output module will stem from
// I have two main flows, one with handling the recursive output and the other
// one handling the normal output
// they will be nearlt identical.
void		output_module(t_stack *files, char *flags)
{
    //

	print_dir(files, flags);

	// 
	//out_entire_stack(files, flags); // TESTING




}