/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:21:37 by marvin            #+#    #+#             */
/*   Updated: 2023/11/28 20:21:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_hexa (int nb)
{
    int resto;

    if (!nb)
        return ;
    if (nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    if (nb >= 16)
	{
		ft_putnbr(nb / 16);
		resto = nb % 16;
        if(resto < 10)
            ft_putchar(resto + 48);
        else
            ft_putchar(resto - 10 + 64);
        
	}
	else
		ft_putchar(nb + '0');
}