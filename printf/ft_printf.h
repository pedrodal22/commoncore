
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:37:38 by marvin            #+#    #+#             */
/*   Updated: 2023/11/28 19:37:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void    ft_hexa_Cap(long long int);
void    ft_hexa(long long int);
int		ft_printf(const char *str, ...);
void    ft_conv(char *str, int i, va_list args);
void    ft_ptr(void *ptr);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void ft_unsint(unsigned int nb);

#endif