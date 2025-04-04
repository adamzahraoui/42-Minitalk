/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:21:37 by adzahrao          #+#    #+#             */
/*   Updated: 2025/03/19 11:48:26 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	if (str[i] == '-')
		i++;
	r = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		return (0);
	return (r * s);
}

void	send_byte(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (ft_printf("Invalid PID\n"), 1);
		while (argv[2][i])
		{
			send_byte(argv[2][i], pid);
			i++;
		}
		send_byte('\0', pid);
	}
	else
		ft_printf("Usage: ./client <server_pid> <message>\n");
	return (0);
}
