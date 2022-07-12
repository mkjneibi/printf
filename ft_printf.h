/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:37:56 by mealjnei          #+#    #+#             */
/*   Updated: 2022/07/12 15:46:36 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int ft_putchar(char c);
int ft_putnbr(int n);
int ft_putnbr_un(int n);
int p_check(va_list m, char c);
int ft_puthex(unsigned long long nbr, char c);

#endif
