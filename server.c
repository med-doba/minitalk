/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srever.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:31:06 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/02 21:02:28 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (pid == NULL)
	{
		ft_printf("allocation error\n");
		exit(1);
	}
	write(1, "SERVER_PID : ", 14);
	write(1, pid, ft_strlen(pid));
	write(1, "\0\n", 2);
	free(pid);
}

static void	ft_hdl(int sig, siginfo_t *info, void *context)
{
	static char	x;
	static int	bits;
	static int	pid;

	(void)context;
	if (info->si_pid != pid)
	{
		pid = 0;
		x = 0xFF;
		bits = 0;
	}
	if (sig == 30)
		x ^= (0x80 >> bits);
	else if (sig == 31)
		x |= (0x80 >> bits);
	bits++;
	if (bits == 8)
	{
		write(1, &x, 1);
		bits = 0;
		x = 0xFF;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_hdl;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit (1);
	ft_pid();
	while (1)
		pause();
}
