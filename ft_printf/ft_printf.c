/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 08:20:29 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 08:20:31 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_praezision(va_list *ap, const char *str, int i, t_list **lst)
{
	int skip;
	int star;

	skip = 0;
	if (str[i] == '.')
	{
		i++;
		skip++;
		if (str[i] == '*')
		{
			star = va_arg(*ap, int);
			(*lst)->precision = star;
		}
		else
			(*lst)->precision = ft_atoi(str + i);
		(*lst)->precisionthere = TRUE;
		while (ft_isdigit(str[i]) || str[i] == '*')
		{
			i++;
			skip++;
		}
	}
	else
		return (0);
	return (skip);
}

int		check_type(const char *str, int i, t_list **lst)
{
	int skip;

	skip = 0;
	if (str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd')
		(*lst)->type = str[i];
	if (str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O')
		(*lst)->type = str[i];
	if (str[i] == 'u' || str[i] == 'U' || str[i] == 'x' || str[i] == 'X')
		(*lst)->type = str[i];
	if (str[i] == 'c' || str[i] == 'C' || str[i] == '%' ||\
	str[i] == 'f' || str[i] == 'F')
		(*lst)->type = str[i];
	if ((*lst)->type != ' ')
	{
		(*lst)->validtype = TRUE;
		i++;
		skip++;
	}
	return (skip);
}

int		ft_manage(const char *str, int *i, va_list *ap, t_list *lst)
{
	int		n;
	int		j;
	int		added;
	int		fuggit;

	j = 1;
	added = 0;
	(*i)++;
	if (str[*i] == '\0')
		return (j);
	ft_manage4(lst, str, i, &j);
	fuggit = 100;
	while (fuggit > 0)
	{
		n = check_width(ap, str, *i, &(lst));
		add_skip(i, n, &j);
		n = ft_check_praezision(ap, str, *i, &lst);
		add_skip(i, n, &j);
		fuggit--;
	}
	ft_manage2(str, i, lst, &j);
	if (ft_cut_it(lst, str, i, &added) == 0)
		return (j);
	ft_determine(&lst, ap);
	return (j);
}

int		sub_ft_printf(va_list *ap, const char *str, t_list **lst)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_write_list(lst);
			ft_manage(str, &i, ap, *lst);
			if ((*lst)->result == -1)
				return (-1);
			ret = ret + (*lst)->result;
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_list		*lst;
	int			ret;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	va_start(ap, str);
	ret = sub_ft_printf(&ap, str, &lst);
	va_end(ap);
	free(lst);
	lst = NULL;
	return (ret);
}
