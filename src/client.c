/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:15:16 by sklaokli          #+#    #+#             */
/*   Updated: 2024/11/18 01:07:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_status = 0;

static int	is_invalid_input(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (1);
	return (0);
}

static void	feedback_handler(int signal)
{
	(void)signal;
	g_status = 1;
}

static void	send_bits(int pid, unsigned char octet)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		g_status = 0;
		if (octet & 1 << bit)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_exit_error(SIGNAL_SENT_FAILURE_MSG);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_exit_error(SIGNAL_SENT_FAILURE_MSG);
		}
		while (g_status != 1)
			pause();
	}
}

static void	send_message_to_server(int pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		send_bits(pid, msg[i]);
	send_bits(pid, '\0');
	send_bits(pid, '\n');
}

int	main(int ac, char *av[])
{
	int		pid;

	if (ac != 3)
		ft_exit_error(INVALID_ARGS_MSG);
	if (is_invalid_input(av[1]))
		ft_exit_error(INVALID_PID_MSG);
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		ft_exit_error(INVALID_PID_MSG);
	if (signal(SIGUSR2, &feedback_handler) == SIG_ERR)
		ft_exit_error(SIGNAL_SENT_FAILURE_MSG);
	send_message_to_server(pid, av[2]);
	exit(EXIT_SUCCESS);
}
