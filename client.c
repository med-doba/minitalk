/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:30:28 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/18 16:08:44 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendmsg(char msg, int pid)
{
	int	shift;

	shift = 7;
	while (shift >= 0)
	{
		if (msg >> shift & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
		shift--;
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("./clent [pid] [msg]");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	while (av[2][i])
	{
		ft_sendmsg(av[2][i], pid);
		i++;
	}
	ft_sendmsg(0, pid);
	return (0);
}
