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

int	julia_pp(t_mlx *d, double r, double i)
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

int	mandelbrot_pp(t_mlx *d, double r, double i)
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

void	draw(t_mlx *d)
{
	d->color = 0;
	d->julia_x_var = 0;
	d->julia_y_var = 0;
	d->xmin = MIN_X;
	d->xmax = MAX_X;
	d->ymin = MIN_Y;
	d->ymax = MAX_Y;0.
	if(!set_up_win(d))
		return ;
	loop_pp(d);
	mlx_hook(d->win_ptr, 17, 2, ft_quit, (void *)0);
	mlx_mouse_hook(d->win_ptr, zoom, (void *)&d);
	mlx_key_hook(d->win_ptr, trigger, (void *)&d);
	mlx_loop(d->mlx_ptr);
}
