/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:53:38 by adeboose          #+#    #+#             */
/*   Updated: 2025/01/19 20:15:21 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_response = false;

void	onsig(__attribute__((unused)) int ac)
{
	g_response = true;
}

void	send_char(int pid, char c)
{
	int	i;
	int	timer;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		timer = 0;
		while (!g_response && timer <= 4200)
		{
			usleep(42);
			timer++;
		}
		if (timer >= 4200)
		{
			ft_printf("Server : %d\nNever gave a response\n", pid);
			exit (1);
		}
		g_response = false;
		i--;
	}
}

void	send_message(int pid, const char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("PID invalide: %d\n", server_pid);
		return (1);
	}
	signal(SIGUSR1, onsig);
	send_message(server_pid, argv[2]);
	return (0);
}
