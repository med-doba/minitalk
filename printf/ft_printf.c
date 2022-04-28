/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:27:15 by med-doba          #+#    #+#             */
/*   Updated: 2022/03/24 15:09:36 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag(va_list par, char x)
{
	int	i;

	i = 0;
	if (x == 'c')
		i += ft_putchar(va_arg(par, int));
	else if (x == 's')
		i += ft_putstr(va_arg(par, char *));
	else if (x == 'p')
		i += ft_p(va_arg(par, unsigned long));
	else if (x == 'd' || x == 'i')
		i += ft_putnbr(va_arg(par, int));
	else if (x == 'u')
		i += ft_putnbrun(va_arg(par, unsigned int));
	else if (x == 'x')
		i += ft_xandx(x, va_arg(par, int));
	else if (x == 'X')
		i += ft_xandx(x, va_arg(par, int));
	else if (x == '%')
		i += ft_putchar('%');
	else
		i += write(1, &x, 1);
	return (i);
}

int	ft_printf(const char *med, ...)
{
	int		i;
	int		j;
	va_list	par;

	i = 0;
	j = 0;
	va_start(par, med);
	while (med[i])
	{
		if (med[i] == '%')
		{
			i++;
			j += ft_flag(par, med[i]);
		}
		else
			j += ft_putchar(med[i]);
		i++;
	}
	va_end(par);
	return (j);
}
