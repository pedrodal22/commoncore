/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:19:07 by pedro             #+#    #+#             */
/*   Updated: 2024/04/26 12:34:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_chr(int signal)
{
	char		chr;
	static int	bit_index;

	if (signal == SIGUSR1)
		chr += (1 << bit_index);
	if (bit_index++ == 7)
	{
		write(1, &chr, 1);
		bit_index = 0;
		chr = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\t PID: %d\n", pid);
	signal(SIGUSR1, show_chr);
	signal(SIGUSR2, show_chr);
	while (1)
		sleep(1);
}

/* char *store_bit_value(int signal)
{
   char *bit_values = (char *)malloc(sizeof(char) * 8);
   static int i;

   i = 0;
	while(i >= 0)
	{
         if (signal == SIGUSR1)
            bit_values[i] = (char)49;
         else
            bit_values[i] = (char)48;
        i--;
	}
   return(bit_values);
} */