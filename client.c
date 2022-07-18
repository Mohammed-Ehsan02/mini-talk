/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:30:26 by mkhan             #+#    #+#             */
/*   Updated: 2022/07/02 20:36:13 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"

int	checkstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	send_data(int pid, char c)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (i >= 0)
	{
		if ((c >> i & 1) == 1)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		usleep(150);
		i--;
	}
	if (j == -1)
	{
		ft_putstr_fd("Kill function failed to connect. Check PID.\n", 2);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		if ((checkstr(argv[1])) != 1)
		{
			ft_putstr_fd("Error: Invalid PID Format\n", 2);
			return (0);
		}
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_data(pid, argv[2][i]);
			i++;
		}
		send_data(pid, '\0');
	}
	else
		ft_putendl_fd("Wrong number of arguments : ./client 'pid' 'text'", 2);
	return (0);
}
