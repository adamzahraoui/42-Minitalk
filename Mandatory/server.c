/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:33:01 by adzahrao          #+#    #+#             */
/*   Updated: 2025/03/09 07:35:54 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_characters(int sig, siginfo_t *info, void *con)
{
	static int	i = 0;
	static char	c = 0;
	static int	pid;

	(void)con;
	if (pid != info->si_pid)
	{
		c = 0;
		i = 0;
	}
	pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= 1 << (7 - i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		ft_printf("%d\n", getpid());
		sa.sa_sigaction = print_characters;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		ft_printf("Error\n");
}
