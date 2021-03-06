/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:59:09 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 17:59:13 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*extract_owner(struct stat buf)
{
	struct passwd		*pwd;

	pwd = getpwuid(buf.st_uid);
	if (pwd && pwd->pw_name)
		return (pwd->pw_name);
	return (NULL);
}

char			*extract_group(struct stat buf)
{
	struct group	*grp;

	grp = getgrgid(buf.st_gid);
	if (grp && grp->gr_name)
		return (grp->gr_name);
	return (NULL);
}

char			*extract_file_size(struct stat buf)
{
	char		*file_size;

	file_size = NULL;
	if (!(file_size = ft_itoa(buf.st_size)))
		return (NULL);
	return (file_size);
}

char			*extract_nbr_of_links(struct stat buf)
{
	char		*nbr_links;

	nbr_links = NULL;
	if (!(nbr_links = ft_itoa(buf.st_nlink)))
		return (NULL);
	return (nbr_links);
}

t_fields		*get_file_info(t_stack *file)
{
	t_stack			*tmp;
	struct stat		buf;

	tmp = file;
	tmp->fields = NULL;
	tmp->fields = alloc_fields();
	lstat(tmp->path, &buf);
	extract_permissions_mode(buf, tmp);
	extract_date_time(buf, tmp->fields);
	tmp->fields->st_blocks = (long long int)buf.st_blocks;
	tmp->fields->owner = extract_owner(buf);
	tmp->fields->group = extract_group(buf);
	tmp->fields->size = extract_file_size(buf);
	tmp->fields->links = extract_nbr_of_links(buf);
	if (tmp->fields->owner == NULL)
		file->fields = NULL;
	return (file->fields);
}
