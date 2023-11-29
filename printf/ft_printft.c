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

int ft_printf(const char *str, ...)
{
    int i;
    va_list arg;
    void args;
    args = va_start(arg, str);

    i = 0;
    if(str == NULL)
		return (NULL);
    while(str[i] != NULL)
    {
        if(str[i] == '%' && str[i + 1] == ('c' || 's' || 'p' || 'd' || 'i' 
            || 'u' || 'x' || 'X' || '%'))
        {
            ft_conv(*str, i++, args);
            i++;
        }
        else
            ft_char(str[i], i++, args);
    }
    va_end(args);
}

void ft_conv(char *str, int i, va_list args)
{
	if(str[i] == 'c')
		ft_putchar(va_arg(args));
    else if  (str[i] == 's')
        ft_putstr(va_arg(args));
    else if (str[i] == 'd' || str[i] == 'i') //falta o str[i] == 'p'
        ft_putnbr(va_arg(args));
    else if (str[i] == 'u')
        ft_unsint(va_arg(args));
    else if(str[i] == 'x')
        ft_hexa(va_arg(args));
    else if(str[i] == 'X')
        ft_hexa_Cap(va_arg(args));
    else if(str[i] == '%')
        ft_putchar('%');
}