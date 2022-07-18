/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:30:23 by mkhan             #+#    #+#             */
/*   Updated: 2022/07/02 19:59:35 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"

void	reciever(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (sig == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
		{
			usleep(300);
			kill(siginfo->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa1;
	struct sigaction	sa2;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr_fd("PID: ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		sa1.sa_flags = SA_SIGINFO;
		sa1.sa_sigaction = reciever;
		sigemptyset(&sa1.sa_mask);
		sa2.sa_flags = SA_SIGINFO;
		sa2.sa_sigaction = reciever;
		sigemptyset(&sa2.sa_mask);
		sigaction(SIGUSR1, &sa1, NULL);
		sigaction(SIGUSR2, &sa2, NULL);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Wrong number of arguments : ./server", 2);
	return (0);
}
