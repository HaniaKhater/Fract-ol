# include "fractol.h"

int     main(int ac, char **av)
{
    t_mlx   d;

    if (ac == 2)
    {
        if (!ft_strcmp(av[1], "julia") || !ft_strcmp(argv[1], "Julia"))
            d->fractal = 1;
        else if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "Mandelbrot"))
            d->fractal = 2;
        else if (!ft)
        check_fractal(d, av);
        fractol(d);
    }
    else
}