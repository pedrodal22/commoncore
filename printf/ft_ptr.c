/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:30:41 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 19:30:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclulde "ft_printf.h"

static void ((void *) ptr)
{
	uintptr_t i = (uintptr_t) ptr;
	    char buf[sizeof(endereco) * 2]; // Tamanho suficiente para o endereço como uma string hexadecimal

    int i = sizeof(endereco) * 2 - 1;
    buf[i--] = '\n'; // Adiciona uma quebra de linha ao final

    while (endereco != 0) {
        int remainder = endereco % 16;
        buf[i--] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
        endereco /= 16;
    }

    write(STDOUT_FILENO, &buf[i + 1], sizeof(buf) - i - 2); // Escreve o endereço no console, excluindo o último caractere ('\n')
}