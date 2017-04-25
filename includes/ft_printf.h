/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 08:26:18 by tbui              #+#    #+#             */
/*   Updated: 2016/05/09 08:26:20 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef	int			t_bool;

typedef	struct		s_list
{
	t_bool			hashtag;
	t_bool			zero;
	t_bool			minus;
	t_bool			space;
	t_bool			plus;
	t_bool			ell;
	t_bool			ll;
	t_bool			h;
	t_bool			hh;
	t_bool			j;
	t_bool			z;
	t_bool			precisionthere;
	t_bool			itsazero;
	t_bool			validtype;
	int				width;
	int				precision;
	char			type;
	int				result;
}					t_list;

void				ft_hex_case_free(char *hex, char *aff);
void				ft_hex_normal_two(t_list **lst, char *aff, \
int *i, int *added);
void				ft_hex_normal_fill(char *aff, char *hex, int *i, int *j);
unsigned long long	ft_determine_ten(t_list **lst, va_list *ap);
void				ft_determine_neuf(t_list **lst, va_list *ap);
void				ft_determine_huit(t_list **lst, va_list *ap, int *nbr);
void				ft_determine_seven(int *nbr, int *support, \
t_list **lst, va_list *ap);
void				ft_determine_two(t_list **lst, va_list *ap);
void				ft_determine_three(t_list **lst, va_list *ap);
void				ft_determine_four(int *support, int *nbr);
void				ft_determine_five(t_list **lst, int *support, int *nbr);
void				ft_determine_six(t_list **lst, va_list *ap);
void				ft_determine2(t_list **lst, va_list *ap);
void				ft_determine3(t_list **lst, va_list *ap);
void				ft_determine4(t_list **lst, va_list *ap);
void				ft_determine5(t_list **lst, va_list *ap);
void				ft_determine6(t_list **lst, va_list *ap);
void				ft_check_width_four(t_list **lst, const char *str, int *i);
void				ft_check_width_five(int *skip, int *i);
void				ft_check_width_six(const char *str, \
t_list **lst, int *i, int *skip);
void				ft_check_width_three(const char *str, \
t_list **lst, int *star, int *i);
void				check_width_two(const char *str, int *j, \
					int *skip, int *i);
void				ft_manage4(t_list *lst, const char *str, int *i, int *j);
void				ft_manage5(t_list *lst, int *added);
void				ft_ugly_manage(t_list *lst, int *added, \
const char *str, int *i);
int					ft_cut_it(t_list *lst, const char *str, int *i, int *added);
void				add_skip(int *i, int n, int *j);
int					nbr_justify_norm1(char *aff, char *nbr, int *temp, int *i);
int					nbr_justify_norm2(char *nbr, char *aff, int *i, int *j);
void				nbr_justify_norm3(t_list **lst, int len, int *added);
void				nbr_normal0(int *len, int *i, int *j, char *nbr);
int					nbr_normal13(t_list **lst, char *aff, char *nbr, int *i);
int					nbr_normal12(t_list **lst, char *nbr, char *aff, int *i);
int					nbr_normal9(t_list **lst, char *aff, int *i);
void				nbr_normal8(char *aff, int *i, int *added);
void				nbr_normal7(t_list **lst, int *added, int *len);
void				nbr_normal6(int *added, int *i, char *aff);
void				nbr_normal5(t_list **lst, int *added, char *nbr, int len);
void				nbr_normal4(t_list **lst, char *aff, int *i, int *added);
void				nbr_normal3_two(char *aff, int *i, int *j, int *len);
int					nbr_normal2(t_list **lst, char *nbr, char *aff, int *i);
void				nbr_normal10(char *nbr, char *aff, \
int *i, int *j);
int					ft_manage3(const char *str, int *i, t_list *lst, int *j);
void				conv_hex_x_put(unsigned int quotient, char *hex, int *i);
char				*ft_puthex_no0x(char *hex, int i);
char				*get_octal(unsigned long long quotient, int *i);
void				ft_perc_case_two(t_list **lst, int *added, char *aff);
int					nbr_justify_two(t_list **lst, char *aff, \
int *added, char *nbr);
int					ft_str_case2_two(t_list **lst, char *str, char *aff, int i);
void				ft_str_case_two(t_list **lst, int added, \
char *str, char *aff);
void				hex_show_norm(t_list **lst, char *str, int *len);
int					conv_ert_hex_put(unsigned long long quotient, \
char *hex, int i);
char				*ft_puthex_zero(t_list **lst, char *tmp);
void				ft_puthex_two(t_list **lst, char *tmp, int i, char *hex);
int					sub_ft_printf(va_list *ap, const char *str, t_list **lst);
void				ft_char_case_norm(t_list **lst, char *aff, int i, char c);
int					conv_ert_put(unsigned nbr, char *hex, int i);
int					conv_ert_put_ll(unsigned long long nbr, char *hex, int i);
int					put_spaces(int amount);
int					put_zeros(int amount);
int					wide_char_ss(wchar_t *string, \
t_list **lst, int *k, int len);
void				count_wide_charss(wchar_t *string, int i, int *add);
int					get_added(t_list **lst, int len);
size_t				count_wide_chars(t_list **lst, \
wchar_t *string, int *length);
size_t				ft_strlen_wide(const wchar_t *original);
void				wide_char_s(wchar_t *string, t_list **lst);
int					ft_printf(const char *str, ...);
void				print_chars(void *memory, int size, t_list **lst);
char				*conv_binary(unsigned int decimal);
void				wchar_case(t_list **lst, wchar_t widechar);
void				ft_nbr_case_unsigned(t_list **lst, unsigned long long nbr);
char				*ft_itoa_unsigned(unsigned long long n);
void				unsigned_nbr_case_l(t_list **lst, unsigned long long nbr);
char				*unsigned_itoa_l(unsigned long long n);
void				ft_nbr_case_ll(t_list **lst, signed long long nbr);
char				*ft_itoa_ll(signed long long n);
char				*conv_hex_x_cap_ll(t_list **lst, unsigned long long nbr);
void				ft_cap_hex_case_ll(t_list **lst, unsigned long long dec);
void				octal_nbr_choose(t_list **lst, char *octal);
void				unsigned_nbr_case(t_list **lst, unsigned int nbr);
void				octal_nbr_case(t_list **lst, unsigned long long nbr);
void				ft_char_case(t_list **lst, char c);
char				*conv_hex_x_cap(t_list **lst, unsigned int nbr);
void				ft_cap_hex_case(t_list **lst, unsigned int dec);
char				*conv_hex_x_long(t_list **lst, unsigned long long nbr);
void				ft_hex_long_case(t_list **lst, unsigned long long alongone);
char				*ft_puthex_no0x(char *hex, int i);
void				ft_hex_case(t_list **lst, unsigned int hex);
void				ft_hex_justify(t_list **lst, char *hex, \
char *aff, int added);
void				ft_hex_normal(t_list **lst, char *hex, \
char *aff, int added);
char				*conv_hex_x(t_list **lst, unsigned int nbr);
void				ft_perc_case(t_list **lst);
void				ft_perc_justify(int added, t_list **lst, char *aff);
void				ft_manage2(const char *str, int *i, t_list *lst, int *j);
int					precision_fill(char *aff, char *nbr, int added, int i);
int					nbr_justify(t_list **lst, char *aff, char *nbr);
int					nbr_normal(t_list **lst, char *aff, char *nbr);
void				ft_nbr_case(t_list **lst, int nbr);
void				ft_determine(t_list **lst, va_list *ap);
int					ft_str_case2(char *str, char *aff, int added, t_list **lst);
int					ft_str_case3(char *str, char *aff, int added, t_list **lst);
void				ft_str_case(t_list **lst, char *str);
char				*ft_puthex(t_list **lst, char *hex, int i);
char				*conv_hex(t_list **lst, unsigned long long ptr);
int					hex_show(t_list **lst, char *str, int width);
void				ft_ptr_case(t_list **lst, unsigned long long ptr);
int					ft_write_list(t_list **lst);
int					check_alph(const char *str, t_list **lst, int i);
int					check_alph2(const char *str, t_list **lst, int i);
int					check_alph3(const char *str, t_list **lst, int i);
int					check_flags(const char *str, t_list **lst, int i);
int					check_flags2(const char *str, t_list **lst, int i);
int					check_width(va_list *ap, const char *str, \
int i, t_list **lst);
int					check_type(const char *str, int i, t_list **lst);
int					ft_manage(const char *str, int *i, \
va_list *ap, t_list *lst);
int					ft_printf(const char *str, ...);
int					ft_check_praezision(va_list *ap, const char *str, \
int i, t_list **lst);

#endif
