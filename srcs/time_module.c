#include "ft_ls.h"

char		*cut_off_seconds(char *mtime)
{
	char **split_time;
	char *proper_hour;

	split_time = NULL;
	if ((!mtime))// || ft_strlen(mtime) <= 0)
		return NULL;
	split_time = ft_strsplit(mtime, ':'); // so there is a segfault here
	proper_hour = ft_strnew(ft_strlen(mtime));
	proper_hour = ft_strcpy(proper_hour, split_time[0]); // and there is also one that is here
	proper_hour = ft_strcat(proper_hour, ":");
	proper_hour = ft_strcat(proper_hour, split_time[1]);
	return (proper_hour);
}

int 		cmp_time_with_cur(t_files *fls)
{
	time_t now_time;
	int times[2];

	now_time = time(0);
	times[0] = (int)fls->mtime;
	times[1] = (int)now_time;
	times[1] = times[1] - 15552000;
	if (times[0] < times[1])
		return (1);
	return (0);
}

void		extract_proper_time(char *c_time_string, t_files *fls)
{
	char **extraction; //putting the time in a 2 d array
	int i;

	if (!c_time_string)
		return ;

	i = 0;
	extraction = ft_strsplit(c_time_string, ' ');
	extraction++;
	while (extraction[i] != '\0')
		i++;
	if (cmp_time_with_cur(fls) == 1)//one means yea it is indeed 6 months older than the current time
	{
		print_yr_only(fls);
		return ;
	}
	//extraction[i - 2] = cut_off_seconds(extraction[i - 2]); //this tab contains the time. passing it through this function will cut off the seconds
	i = 0;
	while (extraction[i] != '\0')
	{
		//ft_putstr(extraction[i]);
		ft_putstr(" ");
		i++;
	}
}

void		print_yr_only(t_files *fls)
{

	fls = NULL; //temporary measure until I code this function
	//print_time(fls);

//code this!
	//function which will extract the year of when the file was last modified and print it out


}
