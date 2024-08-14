void    ft_swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

/*
#include <stdio.h>
int     main(void)
{
        int a;
        int b;

        a = 5;
        b = 3;
        ft_swap(&a, &b);
        printf("%d\n", a);
        printf("%d\n", b);
}
*/
