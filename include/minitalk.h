/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:15:26 by sklaokli          #+#    #+#             */
/*   Updated: 2024/11/18 01:09:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

# define PERROR_MSG "error: an error occurs during process.\n"
# define INVALID_ARGS_MSG "error: invalid number of arguments.\n"
# define INVALID_PID_MSG "error: invalid PID, please try again.\n"
# define SIGNAL_SENT_FAILURE_MSG "signal error! :(\n"
# define SIGNAL_SENT_SUCCESS_MSG "signal sent OK! :D\n"

int		ft_atoi(const char *ptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int num, int fd);
void	ft_exit_error(char *s);

#endif
