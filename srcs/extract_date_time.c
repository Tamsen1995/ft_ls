#include "../includes/ft_ls.h"

void		free_twod_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

/*
** this function gets rid of the
** seconds in the time and returns the reduced time
*/

char		*get_hour(char **split_time)
{
	char	*hour;
	char	**hour_array;

	hour_array = NULL;
	hour = NULL;
	if (!(hour_array = ft_strsplit(split_time[3], ':')))
		error_msg("Could not split the time array in (get_hour)");
	if (!hour_array[0] || !hour_array[1])
		error_msg("Was not able to recuperate a proper hour array (get_hour)");
	if (!(hour = (char *)malloc(sizeof(char) * 100)))
		error_msg("(get_hour) could not malloc");
	hour = ft_strcat(hour, hour_array[0]);
	hour = ft_strcat(hour, ":");
	hour = ft_strcat(hour, hour_array[1]);
	free_twod_arr(hour_array);
	free(hour_array);
	return (hour);
}

/*
** this function gets a clean string of date and time into the structure
*/

char		*isolate_date_time(char *temps)
{
	char	*date;
	char	*hour;
	char	**split_time;

	date = NULL;
	hour = NULL;
	split_time = ft_strsplit(temps, ' ');
	hour = get_hour(split_time);
	if (!split_time[1] || !split_time[2] || !hour)
		error_msg("The time could not be properly split (isolate_date_time)");
	if (!(date = (char *)malloc(sizeof(char) * 100)))
		error_msg("(isolate_date_time), could not malloc");
	date = ft_strcat(date, split_time[1]);
	date = ft_strcat(date, " ");
	date = ft_strcat(date, split_time[2]);
	date = ft_strcat(date, " ");
	date = ft_strcat(date, hour);
	free(hour);
	free_twod_arr(split_time);
	free(split_time);
	return (date);
}

/*
** This function takes in the stat buffer and returns the date of the last time
** the file was modified in the form of a string
** the string is essentially put into the t_fields structure
*/

void		extract_date_time(struct stat buf, t_fields *fields)
{
	char *temps;

	temps = NULL;
	temps = ctime(&buf.st_mtime);
	fields->date = isolate_date_time(temps);
}
