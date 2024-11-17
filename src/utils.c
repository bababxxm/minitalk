/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:16:23 by sklaokli          #+#    #+#             */
/*   Updated: 2024/11/17 22:55:10 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || (ptr[i] == ' '))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i++] == '-')
			sign = -1;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
		result = (result * 10) + (ptr[i++] - 48);
	return (sign * result);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if ((!s) || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putnbr_fd(int num, int fd)
{
	long	n;

	n = num;
	if (fd < 0)
		return ;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_exit_error(char *s)
{
	if (!s)
		return ;
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}
