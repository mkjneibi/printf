# include <stdarg.h>
#include <stdio.h>
#include "printf.h"
#include <unistd.h>
int test(char *str, ...)
{
    va_list arg;
    int i = 0;
    va_start(arg, str);

    while(str[i])
    {
        if(str[i] == '$')
        {
            if (str[i + 1] == 's')
            {
                ft_putstr(va_arg(arg, char *));
                i++;
            }
            i++;
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main()
{
    test("test $s $s\n","hello", "meera" );
}