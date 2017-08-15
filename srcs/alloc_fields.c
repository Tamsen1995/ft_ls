/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:16:15 by tbui              #+#    #+#             */
/*   Updated: 2017/08/10 18:16:18 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_fields		*alloc_fields(void)
{
	t_fields *fields;

	fields = NULL;
	if (!(fields = (t_fields *)malloc(sizeof(t_fields))))
		exit(-1);
	return (fields);
}
