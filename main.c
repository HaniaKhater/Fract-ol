/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:11:49 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/08 02:12:02 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	d;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "julia") || !ft_strcmp(argv[1], "Julia"))
			d->fractal = 1;
		else if (!ft_strcmp(av[1], "mandelbrot")
			|| !ft_strcmp(av[1], "Mandelbrot"))
			d->fractal = 2;
		else if (!ft_strcmp(av[1], "?????"))
			d->fractal = 3;
		else
		{
			print_av_list
			return (0);
		}
		set_up_win(d);
		fractol(d);
	}
	else
	{
		print_av_list();
		return (0);
	}
}
