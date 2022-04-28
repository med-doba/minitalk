/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:59:40 by med-doba          #+#    #+#             */
/*   Updated: 2022/03/24 15:08:58 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *med, ...);
int		ft_flag(va_list par, char x);
int		ft_xandx(char c, unsigned int a);
void	ft_hexa(unsigned long a, char *base, int *i);
int		ft_p(unsigned long a);
int		ft_putstr(char *str);
int		ft_putnbr(long int nbr);
int		ft_putnbrun(unsigned long nbr);
int		ft_length(long int n);
int		ft_putchar(char c);

#endif 
