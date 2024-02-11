
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:35 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 12:52:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_conv(char *str, int i, va_list args)
{
	if(str[i] == 'c')
		ft_putchar(va_arg(args, int));
    else if  (str[i] == 's')
        ft_putstr(va_arg(args, const char *));
    else if (str[i] == 'd' || str[i] == 'i') //falta o str[i] == 'p'
        ft_putnbr(va_arg(args, int));
    else if (str[i] == 'p')
        ft_ptr(va_arg(args, unsigned int));
    else if (str[i] == 'u')
        ft_unsint(va_arg(args, unsigned int));
    else if(str[i] == 'x')
        ft_hexa(va_arg(args, unsigned int));
    else if(str[i] == 'X')
        ft_hexa_Cap(va_arg(args, unsigned int));
    else if(str[i] == '%')
        ft_putchar('%');
}

int ft_printf(const char *str, ...)
{
    int i;
    va_list args;
    va_start(args, str);

    i = 0;
    if(str[0] == '\0')
		return ('\0');
    while(str[i] != '\0')
    {
        if(str[i] == '%' && str[i + 1] == ('c' || 's' || 'p' || 'd' || 'i' 
            || 'u' || 'x' || 'X' || '%'))
            ft_conv(*str, i++, args);
        else
            ft_putchar(str[i]);
        i++;
    }
    va_end(args);
}
