#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str);
void ft_putnbr(int nb);

int main(int argc, char *argv[])
{
        int a;
        int b;
        int result;
	result = 0;
        if (argc == 4)
        {
                a = ft_atoi(argv[1]);
                b = ft_atoi(argv[3]);
                if (argv[2][0] == '+') 
		{
                        result = a + b;
		}
		else if (argv[2][0] == '-')
		{
                        result = a - b;
		}
		else if (argv[2][0] == '*')
                        result = a * b;
		else if (argv[2][0] == '/' && argv[3][0] != 0) 
		{
                        result = a / b;
		}
		else if (argv[2][0] == '%') 
		{
                        result = a % b;
		}
		ft_putnbr(result);
	}
	write(1, "\n", 1);
}


#include <unistd.h>

void ft_putnbr(int nb)
{
        if (nb == -2147483648)
        {
                write(1, "-2", 2);
                nb = 147483648;
        }
	else if (nb < 0)
	{
		write(1, "-", 1);
                nb *= -1;
	}
        if (nb >= 10)
        {
                ft_putnbr(nb / 10);
                ft_putnbr(nb % 10);
        }
        if (nb < 10)
        {
                nb += 48;
                write(1, &nb, 1);
        }
}

int ft_atoi(char *str)
{
        int     result;
        result = 0;
        int     sign;
        sign = 1;
        if (*str == '-' || *str == '+')
        {
                if (*str == '-')
                {
                        sign *= -1;
                }
                str++;
        }
        while (*str >= '0' && *str <= '9')
        {
                result = result * 10 + (*str - 48);
                str++;
        }
        return (result * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
        char *str = "-045";
        int a = ft_atoi(str);
        int s = atoi("-045");
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
        printf("%d\n", a);
        printf("%d\n", s);
}
*/
