/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:19:07 by pedro             #+#    #+#             */
/*   Updated: 2024/04/25 12:52:54 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *store_bit_value(int signal)
{
   char *bit_values = (char *)malloc(sizeof(char) * 8);
   int i;

   i = 0;
	while(i >= 0)
   {
         if (signal == SIGUSR1)
            bit_values[i] = (char)49;
         else
            bit_values[i] = (char)48;
         i--;
   }
   bit_values[8] = '\0';
   return(bit_values);
}

void show_chr(int signal)
{  
    char *bit_values;
    char chr;
    static int i;
    static int bit_index;
   
   bit_values = store_bit_value(signal);
   i = 7;
   while (i >= 0)
   {
      if (bit_values[i] == 49 || bit_values[i] == 48)
      {
         if (bit_values[i] == 49)
            chr += (1 << bit_index);
         if (bit_index++ == 7)
         {
            write(1, &chr, 1);
            bit_index = 0;
            chr = 0;
         }
      }
      i--;
   }
}

int main (void)
{
   int pid;
   
   pid = getpid();
   ft_printf("\t PID: %d\n", pid);
   signal(SIGUSR1, show_chr);
   signal(SIGUSR2, show_chr);
   while(1)
      sleep(1);
} 