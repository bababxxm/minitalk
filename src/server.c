/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:15:09 by sklaokli          #+#    #+#             */
/*   Updated: 2024/11/18 01:08:20 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		tmp[n - 1] = (char)c;
		n--;
	}
	return ((char *)tmp);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	octet = 0;

	(void)context;
	if (signal == SIGUSR2)
		octet |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &octet, 1);
		bit = 0;
		octet = 0;
	}
	if (kill(info -> si_pid, SIGUSR2) == -1)
		ft_exit_error(PERROR_MSG);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit_error(SIGNAL_SENT_FAILURE_MSG);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit_error(SIGNAL_SENT_FAILURE_MSG);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
