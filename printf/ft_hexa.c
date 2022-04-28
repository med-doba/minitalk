/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:55:14 by med-doba          #+#    #+#             */
/*   Updated: 2021/12/21 12:09:11 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long a, char *base, int *i)
{
	if (a >= 16)
		ft_hexa(a / 16, base, i);
	*i += write(1, base + (a % 16), 1);
}

int	ft_p(unsigned long a)
{
	int		i;

	i = 0;
	i += write(1, "0x", 2);
	ft_hexa(a, "0123456789abcdef", &i);
	return (i);
}

int	ft_xandx(char c, unsigned int a)
{
	int		i;
	char	*base;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_hexa(a, base, &i);
	return (i);
}
