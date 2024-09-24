/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:03:01 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/24 12:21:55 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("Error sending signal.\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("Error sending signal.\n");
				exit(EXIT_FAILURE);
			}
		}
		bit++;
		usleep(400);
	}
}

void	handle_confirmation(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("Message received by server.\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client [server_pid] [message]\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, handle_confirmation);
	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\n');
	send_char(pid, '\0');
	return (0);
}
