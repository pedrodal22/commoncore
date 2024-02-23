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
# include <string.h>
# include <stdint.h>

int	ft_hexa_cap(unsigned int nb);
int	ft_hexa(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_conv(char *str, int i, va_list args);
int	ft_ptr(void *ptr);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(const char *str);
int	ft_unsint(unsigned int nb);

#endif