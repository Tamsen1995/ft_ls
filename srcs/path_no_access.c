#include "../includes/ft_ls.h"

T_BOOL path_no_access(t_stack *alist)
{
    if (lstat(alist->path, &(alist->stats)) < 0 && errno == EACCES)
        return (TRUE);
    return (FALSE);
}