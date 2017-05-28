#include "../includes/ft_ls.h"

void error_msg(char *message)
{
    if (!message)
    {
        ft_putendl("This is an unknown error.");
        exit (-1);
    }
    ft_putendl(message);
    exit (-1);
}