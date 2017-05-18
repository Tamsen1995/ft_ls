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


t_bool		is_hidden_file(t_stack *file)
{
	if (!file || !file->filename || !file->filename[0])
		exit (-1);
	if (file->filename[0] == '.')
		return (TRUE);
	return (FALSE);
}

void		print_list(t_stack *file)
{
	ft_putstr(file->fields->mode);
	ft_putstr("\t");
	ft_putstr(file->fields->links);
	ft_putstr("\t");
	ft_putstr(file->fields->owner);
	ft_putstr("\t");
	ft_putstr(file->fields->group);
	ft_putstr("\t");
	ft_putstr(file->fields->size);
	ft_putstr("\t");
	ft_putstr(file->fields->date);
	ft_putstr("\t");
}

// This function prints 
void		print_flags(t_stack *file, char *flags)
{
	t_stack *tmp;


	tmp  = NULL;
	if (!file)
		exit (-1);
	tmp = file;
	if (flags[f_list])
		print_list(tmp);
}

// this outputs the directory along with the requested flags
void		print_dir(t_stack *files, char *flags)
{
	t_stack *tmp;

	tmp = files;

	while (is_hidden_file(tmp) && !flags[f_hidden])
		tmp = tmp->next;
	while (tmp)
	{
		print_flags(tmp, flags);
		ft_putendl(tmp->filename);
		tmp = tmp->next;
	}
}

void print_total_blocks(t_stack *file)
{
	t_stack *tmp;
	long long int total_blk_size;

	total_blk_size = 0;
	tmp = file->subdir;
	while (tmp)
	{
		total_blk_size = total_blk_size + tmp->fields->st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr((int)total_blk_size);
	ft_putendl("");
}


// this function handles the output of the directory in within the recursive output
// first it need to output the folders name itself since it is considered a file contained in the higher level directory
// then the output of the directories path with some output
void	print_dir_path_recur(t_stack *file)
{
	//ft_putendl(file->filename);	
	ft_putendl("");
	ft_putendl("");
	ft_putendl(file->path);	
	print_total_blocks(file);
}

// this function handles the recursive output
void    out_entire_stack(t_stack *stack, char *flags)
{
	
	t_stack 		*tmp; // This pointer serves as a tmp pointer for the recursion

    tmp = NULL;
	tmp = stack;


	while (is_hidden_file(tmp) && !flags[f_hidden])
		tmp = tmp->next;
	print_dir(tmp, flags);
	while (tmp)
	{
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY) // hacky
			print_dir_path_recur(tmp);	
		if (not_curr_and_prev(tmp) == TRUE && tmp->type == DIRECTORY)
			out_entire_stack(tmp->subdir, flags); // recursively calling the function again with the newly made path in the stack elem
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
	if (flags[f_recur])
		out_entire_stack(files, flags); // TESTING
	else
		print_dir(files, flags);
}

