/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:20:29 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/27 16:46:52 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_fields	*create_fields(struct stat stats, t_filetype type)
{
	t_fields	*f;

	if (!(f = (t_fields *)malloc(sizeof(t_fields))))
		return (NULL);
	f->mode = mode_to_str(stats.st_mode, type);
	f->links = ft_itoa((int)stats.st_nlink);
	f->owner = uid_to_str(stats.st_uid);
	f->group = gid_to_str(stats.st_gid);
	if (type == BLOCK || type == CHAR_SP)
	{
		f->major = ft_itoa((int)major(stats.st_rdev));
		f->size = ft_itoa((int)minor(stats.st_rdev));
	}
	else
	{
		f->major = NULL;
		f->size = ft_itoa((int)stats.st_size);
	}
	f->date = date_to_str(stats.st_mtimespec.tv_sec);
	return (f);
}

char		*mode_to_str(mode_t st_mode, t_filetype type)
{
	char	*c_mode;

	if (!(c_mode = ft_strnew(11)))
		return (NULL);
	c_mode[0] = filetype_to_char(type);
	c_mode[1] = (st_mode & S_IRUSR ? 'r' : '-');
	c_mode[2] = (st_mode & S_IWUSR ? 'w' : '-');
	if (st_mode & S_IXUSR)
		c_mode[3] = (st_mode & S_ISUID ? 's' : 'x');
	else
		c_mode[3] = (st_mode & S_ISUID ? 'S' : '-');
	c_mode[4] = (st_mode & S_IRGRP ? 'r' : '-');
	c_mode[5] = (st_mode & S_IWGRP ? 'w' : '-');
	if (st_mode & S_IXGRP)
		c_mode[6] = (st_mode & S_ISGID ? 's' : 'x');
	else
		c_mode[6] = (st_mode & S_ISGID ? 'S' : '-');
	c_mode[7] = (st_mode & S_IROTH ? 'r' : '-');
	c_mode[8] = (st_mode & S_IWOTH ? 'w' : '-');
	if (st_mode & S_IXOTH)
		c_mode[9] = (st_mode & S_ISVTX ? 't' : 'x');
	else
		c_mode[9] = (st_mode & S_ISVTX ? 'T' : '-');
	return (c_mode);
}

char		*uid_to_str(uid_t uid)
{
	struct passwd	*ret;

	ret = getpwuid(uid);
	if (!ret)
		return (ft_itoa((int)uid));
	return (ft_strdup(ret->pw_name));
}

char		*gid_to_str(gid_t gid)
{
	struct group	*ret;

	ret = getgrgid(gid);
	if (!ret)
		return (ft_itoa((int)gid));
	return (ft_strdup(ret->gr_name));
}

char		*date_to_str(time_t clock)
{
	char	*str;
	char	*c_time;
	int		diff;

	if (!(str = ft_strnew(13)))
		return (NULL);
	if (clock > 253402214400)
		clock = 253402214400;
	diff = (int)(clock - time(NULL));
	c_time = ctime(&clock);
	ft_strncpy(str, c_time + 4, 7);
	if (diff >= 15778774 || diff <= -15778774)
		ft_strncpy(str + 7, c_time + 19, 5);
	else
		ft_strncpy(str + 7, c_time + 11, 5);
	return (str);
}
