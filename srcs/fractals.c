/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:04:01 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/10 01:04:39 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	custom_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bpp / 8) + (y * mlx->line_len);
	*(unsigned int *)dst = color;
}

int	draw_julia(t_mlx *d, double r, double i)
{
	int		iter;
	double	x;
	double	y;
	double	tmp;

	iter = 1;
	x = r;
	y = i;
	while (iter < ITER_MAX)
	{
		tmp = x;
		x = (x * x - y * y) - 0.835 + d->julia_x_var;
		y = (2 * tmp + y) - 0.2321 + d->julia_y_var;
		if (x * x + y * y > 5)
		{
			custom_pixel(d, d->done_x, d->done_y, (d->color + iter * CLR_VAR));
			return (0);
		}
		iter++;
	}
	custom_pixel(d, d->done_x, d->done_y, 0x00000000);
	return (0);
}

int	draw_mandelbrot(t_mlx *d, double r, double i)
{
	int		iter;
	double	x;
	double	y;
	double	tmp;

	iter = 1;
	x = 0;
	y = 0;
	while (iter < ITER_MAX)
	{
		tmp = x;
		x = (x * x - y * y) + r;
		y = (2 * tmp + y) + i;
		if (x * x + y * y > 5)
		{
			custom_pixel(d, d->done_x, d->done_y, (d->color + iter * CLR_VAR));
			return (0);
		}
		iter++;
	}
	custom_pixel(d, d->done_x, d->done_y, 0x00000000);
	return (0);
}
