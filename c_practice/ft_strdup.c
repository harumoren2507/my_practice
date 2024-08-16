#include <stdlib.h>

int     ft_strlen(char *str)
{
        int len;

        len = 0;
        while (*str != '\0')
        {
                str++;
                len++;
        }
        return (len);
}

char* ft_strdup(char *src)
{
        char *dest;
        char *dest_start;

        dest = (char *)malloc(ft_strlen(src) + 1);
        if (dest == NULL)
                return (NULL);
        dest_start = dest;
        while (*src != '\0')
        {
                *dest = *src;
                dest++;
                src++;
        }
        *dest = '\0';
        return (dest_start);
}

/*
#include <stdio.h>

int     main(void)
{
        char str[] = "abcde";
        char *src = ft_strdup(str);
        printf("%s\n", src);
}
*/
