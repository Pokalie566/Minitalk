/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:53:47 by adeboose          #+#    #+#             */
/*   Updated: 2024/12/11 14:53:48 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define MAX_LINE_LENGTH 2147483647

static void	reset_state(t_signal_state *state)
{
	state->bit_count = 0;
	state->current_char = 0;
}

static void	handle_character(t_signal_state *state, char *line
			, int *line_index)
{
	if (state->current_char == '\0' || state->current_char == '\n')
	{
		write(1, line, *line_index);
		write(1, "\n", 1);
		*line_index = 0;
	}
	else
	{
		if (*line_index < MAX_LINE_LENGTH - 1)
		{
			line[*line_index] = state->current_char;
			(*line_index)++;
		}
	}
}

static void	update_character(t_signal_state *state, int sig)
{
	if (sig == SIGUSR1)
		state->current_char = state->current_char << 1;
	else if (sig == SIGUSR2)
		state->current_char = (state->current_char << 1) | 1;
	state->bit_count++;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static t_signal_state	state = {0, 0};
	static char				line[MAX_LINE_LENGTH];
	static int				line_index = 0;

	if (!info)
		return ;
	(void)context;
	update_character(&state, sig);
	if (state.bit_count == 8)
	{
		handle_character(&state, line, &line_index);
		reset_state(&state);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Erreur de sigaction\n");
		return (1);
	}
	ft_printf("Serveur prêt, PID: %d\n", getpid());
	while (42)
		pause();
	return (0);
}
