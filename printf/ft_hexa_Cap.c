/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_Cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:30:37 by pedro             #+#    #+#             */
/*   Updated: 2024/02/23 19:30:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_cap(unsigned int nb)
{
	int				count;
	unsigned int	resto;

	count = 0;
	if (nb >= 16)
	{
		count += ft_hexa_cap(nb / 16);
		resto = nb % 16;
		if (resto < 10)
			count += ft_putchar(resto + 48);
		else
			count += ft_putchar(resto - 10 + 'A');
	}
	else
	{
		if (nb < 10)
			count += ft_putchar(nb + '0');
		else
			count += ft_putchar(nb - 10 + 'A');
	}
	return (count);
}
