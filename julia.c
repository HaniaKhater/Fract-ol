/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:13:41 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/08 02:13:47 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, t_mlx *d)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	tmp;

	iter = 1;
	z_re = x;
	z_im = y;
	while (iter < ITER_MAX)
	{
		tmp = z_re;
		z_re = (z_re * z_re - z_im * z_im) - 0.835 + d->julia_x_var;
		z_im = (2 * tmp + z_im) - 0.2321 + d->julia_y_var;
		if (z_re * z_re + z_im * z_im > 5)
		{
			custom_pixel(d, d->done_x, d->done_y, (d->color + iter * CLR_VAR));
			return (0);
		}
		iter++;
	}
	custom_pixel(d, d->done_x, d->done_y, 0x00000000);
	return (0);
}

int	julia_pp(t_mlx *d)
{
	double	x;
	double	y;

	d->done_x = 0;
	d->done_y = 0;
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	while (d->done_x < WIN_X)
	{
		while (d->done_y < WIN_Y)
		{
			x = d->xmin + (d->done_x * (d->xmax - d->xmin) / WIN_X);
			y = d->ymin + (d->done_y * (d->ymax - d->ymin) / WIN_Y);
		}
		d->done_y = 0;
		d->done_x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (1);
}
