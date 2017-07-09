#include "../includes/ft_ls.h"

// this function gets rid of the seconds in the time and returns the reduced time
char *get_hour(char **split_time)
{
    char *hour;
    char **hour_array;

    hour_array = NULL;
    hour = NULL;
    if (!(hour_array = ft_strsplit(split_time[3], ':')))
        error_msg("Could not split the time array in (get_hour)");
    if (!hour_array[0] || !hour_array[1])
        error_msg("Was not able to recuperate a proper hour array (get_hour)");
    hour = ft_strjoin(hour_array[0], ":");
    hour = ft_strjoin(hour, hour_array[1]);
    return (hour);
}


// this function gets a clean string of date and time into the structure
char *isolate_date_time(char *temps)
{
    char    *date;
    char    *hour;
    char    **split_time;


    date = NULL;
    hour = NULL;
    split_time = ft_strsplit(temps, ' '); // splitting the time/date into an array for better processing
    hour = get_hour(split_time);
    if (!split_time[1] || !split_time[2] || !hour)
        error_msg("The time could not be properly split (isolate_date_time)");
    date = ft_strjoin(split_time[1], " ");
    date = ft_strjoin(date, split_time[2]);
    date = ft_strjoin(date, " ");
    date = ft_strjoin(date, hour);
    free(split_time);
    return (date);

}

// This function takes in the stat buffer and returns the date of the last time
// the file was modified in the form of a string
// the string is essentially put into the t_fields structure
void        extract_date_time(struct stat buf, t_fields *fields)
{
    char *temps;

    temps = NULL;
    temps = ctime(&buf.st_mtime);
    fields->date = isolate_date_time(temps);
}