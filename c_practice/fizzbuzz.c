#include <unistd.h>

void ft_putnbr_easy(int nb)
{
        if (nb >= 10)
        {
                ft_putnbr_easy(nb / 10);
                ft_putnbr_easy(nb % 10);
        }
        if (nb < 10)
        {
                nb += 48;
                write(1, &nb, 1);
        }
}

void fizzbuzz(void)
{
        int n;
        n = 1;
        while (n <= 100)
        {
                if (n % 3 == 0 && n % 5 == 0)
                        write(1, "fizzbuzz\n", 9);
                else if (n % 3 == 0)
                        write(1, "fizz\n",5);
                else if (n % 5 == 0)
                        write(1, "buzz\n", 5);
                else
                {
                        ft_putnbr_easy(n);
                        write(1, "\n", 1);
                }
                n++;
        }
}

int main(void)
{
        fizzbuzz();
        return (0);
}

