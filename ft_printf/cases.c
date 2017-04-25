/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 06:34:53 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 06:34:55 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_determine_seven(int *nbr, int *support, \
t_list **lst, va_list *ap)
{
	(*nbr) = (int)va_arg(*ap, int);
	if ((*nbr) < -128)
		ft_determine_four(support, nbr);
	else if ((*nbr) > 127)
		ft_determine_five(lst, support, nbr);
	ft_nbr_case(lst, (*nbr));
}

void					ft_determine_huit(t_list **lst, va_list *ap, int *nbr)
{
	int		support;

	if ((*lst)->j == FALSE && (*lst)->z == FALSE && \
	(*lst)->h == TRUE && (*lst)->type == 'd')
		ft_determine_three(lst, ap);
	else if ((*lst)->hh == TRUE && \
	((*lst)->type == 'i' || (*lst)->type == 'd'))
		ft_determine_seven(nbr, &support, lst, ap);
	else if ((*lst)->type == 'D' || (*lst)->z == TRUE || \
	(*lst)->ll == TRUE || \
	(*lst)->ell == TRUE || (*lst)->j == TRUE)
		ft_determine_six(lst, ap);
	else
	{
		(*nbr) = va_arg(*ap, int);
		if ((*nbr) == 0)
			(*lst)->itsazero = TRUE;
		ft_nbr_case(lst, (*nbr));
	}
}

void					ft_determine_neuf(t_list **lst, va_list *ap)
{
	unsigned int			notsigned;
	unsigned long long		ptr;

	(*lst)->space = FALSE;
	(*lst)->plus = FALSE;
	if ((*lst)->hh == TRUE && (*lst)->type != 'U')
	{
		notsigned = (unsigned int)va_arg(*ap, unsigned int);
		while (notsigned > 255)
			notsigned = notsigned - 256;
		unsigned_nbr_case(lst, notsigned);
	}
	else if ((*lst)->z == TRUE || (*lst)->type == 'U' || \
	(*lst)->ell == TRUE || (*lst)->ll == TRUE || (*lst)->j == TRUE)
	{
		ptr = (unsigned long long)va_arg(*ap, unsigned long long);
		ft_nbr_case_unsigned(lst, ptr);
	}
	else
	{
		notsigned = va_arg(*ap, unsigned int);
		if (notsigned == 0)
			(*lst)->itsazero = TRUE;
		unsigned_nbr_case(lst, notsigned);
	}
}

unsigned long long		ft_determine_ten(t_list **lst, va_list *ap)
{
	unsigned long long ptr;

	ptr = va_arg(*ap, unsigned long long);
	if (ptr > 4294967295 && !(*lst)->j && (*lst)->type != 'O' && \
	!(*lst)->ll && !(*lst)->ell && !(*lst)->z)
		ptr = 4294967295;
	if (ptr == 0)
		(*lst)->itsazero = TRUE;
	if ((*lst)->h == TRUE && (*lst)->type != 'O')
	{
		while (ptr > 65535)
			ptr = ptr - 65536;
	}
	if ((*lst)->hh == TRUE && (*lst)->type != 'O')
	{
		while (ptr > 255)
			ptr = ptr - 256;
	}
	return (ptr);
}

void					ft_determine(t_list **lst, va_list *ap)
{
	unsigned long long	ptr;
	int					nbr;
	int					i;

	i = 0;
	ft_determine_two(lst, ap);
	if ((*lst)->type == 'p')
	{
		ptr = (unsigned long long)va_arg(*ap, void *);
		ft_ptr_case(lst, ptr);
		return ;
	}
	if ((*lst)->type == 'D' || (*lst)->type == 'd' || (*lst)->type == 'i')
		ft_determine_huit(lst, ap, &nbr);
	if ((*lst)->type == 'u' || (*lst)->type == 'U')
		ft_determine_neuf(lst, ap);
	if ((*lst)->type == 'o' || (*lst)->type == 'O')
		octal_nbr_case(lst, ft_determine_ten(lst, ap));
	ft_determine2(lst, ap);
	return ;
}
