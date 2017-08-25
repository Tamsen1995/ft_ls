#include "../includes/libft.h"

/*
** Takes in an int and allocates a 
** null terminated 2d array
** with the amount of strings
** requested
*/

char 			**ft_alloc_twod_arr(int nbr)
{
    char **twod_arr;

    twod_arr = NULL;
	if (!(twod_arr = (char **)malloc(sizeof(char *) * nbr + 1)))
		error_msg("could not malloc (ft_alloc_twod_arr)");
    twod_arr[nbr + 1] = NULL;
    return (twod_arr);
}
