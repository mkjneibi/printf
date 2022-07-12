/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:39:50 by mealjnei          #+#    #+#             */
/*   Updated: 2022/07/12 16:03:52 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putnbr(int n)
{
	int     i;

	i = 0;
	if (n == -2147483648)
	{
		// ft_putstr("\n");
		i += ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}


int ft_putnbr_un(int n)
{
	int     i;
	long	m;

	i = 0;
	m = (long)n;
	if (m > 9)
	{
		i += ft_putnbr_un(m / 10);
		i += ft_putchar(m % 10 + '0');
	}
	else
		i += ft_putchar(m + '0');
	return (i);
}

int	ft_puthex(unsigned long long nbr, char c)
{
	char	*b;
	int		i;

	i = 0;
	b = "0123456789abcdef";
	if (c == 'X')
		b = "0123456789ABCDEF";
	if (c == 'p')
	{
		i += write(1, "0x", 2);
		if (nbr == 0)
		{
			i += write(1, "0" , 1);
			return (i);
		}
	}
	if (nbr > 15)
		i += ft_puthex(b[nbr / 16], c);
	i += ft_putchar(b[nbr % 16]);
}
