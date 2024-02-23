/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:51:17 by pedro             #+#    #+#             */
/*   Updated: 2024/02/23 19:29:22 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *ptr)
{
	int			count;
	uintptr_t	pointer;

	pointer = (uintptr_t)ptr;
	count = 0;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_hexa(pointer);
	return (count);
}
