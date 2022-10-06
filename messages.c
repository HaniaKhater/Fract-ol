# include "fractol.h"

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int     ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    ft_putstr(char *str)
{
    int len;

    len = ft_strlen(str);
    write(1, &str, len);
}

void    print_av_list(void)
{
    ft_putstr("****************************************************");
    ft_putstr("*--------------------------------------------------*");
    ft_putstr("*        Try ./fractol <available fractal>         *");
    ft_putstr("*--------------------------------------------------*");
    ft_putstr("*--------------------------------------------------*");
    ft_putstr("*********** List of available fractals: ************");
    ft_putstr("*--------------------------------------------------*");
    ft_putstr("*------------------- Julia ------------------------*");
    ft_putstr("*----------------- Mandelbrot ---------------------*");
    ft_putstr("*----------------- ?????????? ---------------------*");
    ft_putstr("*--------------------------------------------------*");
    ft_putstr("****************************************************");
}
