/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:49:37 by tbui              #+#    #+#             */
/*   Updated: 2016/04/23 15:49:42 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int					get_next_line(int const fd, char **line);
size_t				ft_strlen(char const *s);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
void				ft_exit(char *s);
void				ft_init_tab(char **tab);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
void				ft_strlclr(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrn(int n);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_strclr(char *s);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_clear_tab(char ***tab);
void				ft_colstr(char *col, char *msg);
void				ft_strcol(char *col, char *o, char *t, char *l);
int					ft_atoi(char const *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdigitand(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strdup(char const *s1);
char				*ft_strndup(char const *s1, int i);
char				*ft_strstr(char const *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *s, char c);

#endif
