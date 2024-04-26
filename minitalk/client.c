/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:30 by pedro             #+#    #+#             */
/*   Updated: 2024/04/26 11:56:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <signal.h>
#include <string.h>

int	pid_check(const char *str)
{
	int	a;
	int	result;

	a = 0;
	result = 0;
	if (str == NULL)
		return (1);
	while (str[a] != '\0')
	{
		if ((str[a] >= '0' && str[a] <= '9'))
		{
			result = result * 10 + (str[a] - '0');
			a++;
		}
		else
			return (-1);
	}
	return (result);
}

void	send_bits(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(700);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = pid_check(argv[1]);
	if (argc != 3 || pid < 0)
		return (1);
	while (argv[2][i] != '\0')
	{
		send_bits(argv[2][i], pid);
		i++;
	}
	send_bits('\n', pid);
	return (0);
}
