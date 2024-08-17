#include <stdlib.h>

int     ft_abs(int x)
{
        if (x < 0)
                return (-x);
        else
                return (x);
}

int     *ft_range(int start, int end)
{
        int *nbr;
        int len = ft_abs(end - start) + 1;
        nbr = (int *)malloc(sizeof(int) * len);
        if (nbr == NULL)
                return (NULL);
        *nbr = start;
        int i;
        i = 0;
        while (start != end)
        {
                i++;
                if (start < end)
                        start++;
                else
                        start--;
                nbr[i] = start;
        }
        return (nbr);
}

#include <stdio.h>

int     main(void)
{
        int start;
        int end;

        start = -4;
        end = 5;

        int *nbr = ft_range(start, end);
        int len = ft_abs(end - start) + 1;
        int     i;
        i = 0;
        while (i < len)
        {
                printf("%d\n", nbr[i]);
                i++;
        }
}

