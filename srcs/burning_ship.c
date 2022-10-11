/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:17:22 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/11 08:18:45 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	burning_ship_set(double c_re, double c_im, t_mlx *d)
{
	int		iter;
	double	x;
	double	y;
	double	tmp;

	x = 0;
	y = 0;
	iter = 1;
	while (iter < ITER_MAX)
	{
		tmp = x;
		x = x * x - y * y - c_re;
		y = fabs(2 * tmp * y) - c_im;
		if (x * x + y * y > 4)
		{
			custom_pixel(d, d->done_x, d->done_y,
				(d->color) + 0x00110000 * iter);
			return (0);
		}
		iter++;
	}
	custom_pixel(d, d->done_x, d->done_y, 0x00000000);
	return (0);
}

int	burning_ship(t_mlx *d)
{
	double	c_re;
	double	c_im;

	d->done_x = 0;
	d->done_y = 0;
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	while (d->done_y < WIN_Y)
	{
		while (d->done_x < WIN_X)
		{
			c_re = d->xmin + (d->done_x * (d->xmax - d->xmin)
					/ WIN_X);
			c_im = d->ymax - (d->done_y * (d->ymax - d->ymin)
					/ WIN_Y);
			burning_ship_set(c_re, c_im, d);
			d->done_x++;
		}
		d->done_y++;
		d->done_x = 0;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (1);
}
/*
int	window_init_burning_ship(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "Burning ship");
	if (!mlx->win)
		return (0);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
	if (!mlx->img_ptr)
		return (0);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (0);
	return (1);
}
*/

void	draw_burning_ship(void)
{
	t_mlx	mlx;

	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	if (!set_up_win(&d))
		return ;
	mlx.color = 0;
	mlx.fractol = 3;
	burning_ship((void *)&d);
	mlx_hook(mlx.win, 17, 2, ft_quit, (void *)0);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_key_hook(mlx.win, trigger, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
}