/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:22:53 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/19 21:56:42 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int				ft_strlen(const char *str);
char			*ft_strchr(char *str, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			ft_putchar(unsigned int fd, const char c);
void			ft_putnbr(int fd, int nb);
int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nitems, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
char			*ft_memset(void *ptr, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
char			ft_putchar(unsigned int fd, const char c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int fd, int nb);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(char *str, int c);
char			*ft_strdup(char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1,const  char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int i);
int				ft_toupper(int i);

#endif
