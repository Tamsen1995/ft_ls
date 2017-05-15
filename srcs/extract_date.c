#include "../includes/ft_ls.h"

// this function gets the complete time including year, hour and everything else
// it extarcts ONLY month and day and returns this in a string
char *isolate_date_from_time(char *temps)
{
    char    *date;
    char    **split_time;


    date = NULL;
    split_time = ft_strsplit(temps, ' ');


    date = ft_strjoin(split_time[1], " ");
    date = ft_strjoin(date, split_time[2]);
    return (date);

}

// This function takes in the stat buffer and returns the date of the last time
// the file was modified in the form of a string
// the string is essentially put into the t_fields structure
char *extract_date(struct stat buf)
{
    char *date;
    char *temps;

    temps = NULL;
    date = NULL;
    temps = ctime(&buf.st_mtime);
    date = isolate_date_from_time(temps);
    //ft_putendl(date);
    return (date);
}