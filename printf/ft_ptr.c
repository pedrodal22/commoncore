
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:51:17 by pedro             #+#    #+#             */
/*   Updated: 2024/02/10 23:51:18 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_ptr(void *ptr)
{
    ft_putchar('0');
    ft_putchar('x');

    unsigned long long pointer = (unsigned long)ptr;
    ft_hexa_Cap(pointer);
    return (0);
}