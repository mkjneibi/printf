/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:41:40 by mealjnei          #+#    #+#             */
/*   Updated: 2022/07/12 15:50:37 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int p_check(va_list m, char c)
{
	int i;

	i = 0;
	if (c == 's')
		i = ft_putstr(va_arg(m, char *));
	else if (c == 'c')
		i = ft_putchar(va_arg(m, int));
	else if (c == 'd')
		i = ft_putnbr(va_arg(m, int));
	else if (c == 'i')
		i = ft_putnbr(va_arg(m, int));
	else if (c == 'u')
		i = ft_putnbr_un(va_arg(m, unsigned int));
	else if (c == 'x' || c == 'X' || c == 'p')
		i = ft_puthex(va_arg(m, unsigned long long), c);
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	check_in(int a)
{
	if (a == 's' || a == 'c' || a == 'd' || a == 'u' || a == 'i' || a == 'x' || a == 'X' || a == '%' || a == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list m;
	int j;

	j = 0;
	va_start(m, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (check_in(str[i + 1]))
				j += p_check(m, str[i + 1]);
			i += 2;
		}
		j += write(1, &str[i], 1);
		i++;
	}
	return (j);
}
#include <limits.h>
int	main()
{
	char *str = "hello world";
	int i = 15;
	char c = 'c';
	// int j = ft_printf("here we have string: %s\nhere we have char: %c\nhere we have d: %d\nhere we have un: %u\nhere we have in: %i", str, c, i, i, i);
	// printf("\nhere is total: %d\n", j);
	// int x = write(1, "hello worl", 10);
	ft_printf(" %d", -42);
}