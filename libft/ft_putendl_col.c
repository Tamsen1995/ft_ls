#include "../includes/libft.h"


static	void	my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        my_putchar(s[i]);
        i++;
    }
}

void			ft_putendl_col(t_stack *file)
{
    char *color;

    color = GRAY;
    if (file->type == DIRECTORY)
        color = CYAN;
    else if (file->type == SYMLINK)
        color = MAGENTA;
    if (ft_strcmp(file->filename, "ft_ls") == 0)
        color = RED;
	my_putstr(color);
    my_putstr(file->filename);
    my_putstr(STOP);
    my_putchar('\n');
}
