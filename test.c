# include <stdarg.h>
#include <stdio.h>
#include "printf.h"
#include <unistd.h>


int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putnbr_un(unsigned int n)
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

int main()
{
   printf("here is the digit %d\n",ft_putnbr_un(-1));
}