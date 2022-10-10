/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:12:55 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/08 02:13:02 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

char	*find_name(t_mlx *d)
{
	if (d->fractal == 1)
		return("Julia");
	else if (d->fractal == 2)
		return("Mandelbrot");
	//else if (d->fractal == 3)
	//	d->name = "Burning ship";
	return (NULL);
}

int 	set_up_win(t_mlx *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		return (0);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIN_X, WIN_Y, find_name(d));
	if (!d->win_ptr)
		return (0);
	d->img_ptr = mlx_new_image(d->mlx_ptr, WIN_X, WIN_Y);
	if (!d->img_ptr)
		return (0);
	d->addr = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->line_len, &d->endian);
	if (!d->addr)
		return (0);
	return (1);
}

void	fractal_set(t_mlx *d, double r, double i)
{
	if (d->fractal == 1)
		julia_pp(d, r, i);
	else if (d->fractal == 2)
		mandelbrot_pp(d, r, i);
	//else if (d->fractal == 3)
	//	draw_burning_pp(d, r, i);
}

void	custom_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bpp / 8) + (y * mlx->line_len);
	*(unsigned int *)dst = color;
}

int	loop_pp(t_mlx *d)
{
	double	r;
	double	i;

	d->done_x = 0;
	d->done_y = 0;
	//mlx_clear_window(d->mlx_ptr, d->win_ptr);
	while (d->done_y < WIN_Y)
	{
		while (d->done_x < WIN_X)
		{
			r = d->xmin + (d->done_x * (d->xmax - d->xmin) / WIN_X);
			i = d->ymin + (d->done_y * (d->ymax - d->ymin) / WIN_Y);
			fractal_set(d, r, i);
			d->done_x++;
		}
		d->done_x = 0;
		d->done_y++;
	}
	ft_putstr("rows & columns done!?");
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
	return (1);
}
