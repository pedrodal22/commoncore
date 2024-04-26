/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:19:16 by pedro             #+#    #+#             */
/*   Updated: 2024/04/26 11:55:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdarg.h>
# include <string.h>
# include <stdint.h>

int		pid_check(const char *str);
void	send_bits(char c, int pid);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	*ft_strchr(const char *str, int c);
int		ft_conv(char *str, int i, va_list args);
int		ft_printf(const char *str, ...);
void	show_chr(int signal);

#endif