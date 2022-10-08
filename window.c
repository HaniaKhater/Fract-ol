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

#include "fractol.h"

void	set_name(t_mlx *d)
{
	if (d->fractal == 1)
		d->name = "Julia";
	else if (d->fractal == 2)
		d->name = "Mandelbrot";
	else if (d->fractal == 3)
		d->name = "?????";
	return ;
}

int	set_up_win(t_mlx *d)
{
	set_name(＆d);
	d->mlx_ptr = mlx_init(void);
	if (!d->mlx_ptr)
		return (0);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIN_X, WIN_Y, &d->name);
	if (!d->win_ptr)
		return (0);
	d->img_ptr = mlx_new_image(d->mlx_ptr, WIN_X, WIN_Y);
	if (!d->img_ptr)
		return (0);
	d->addr = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->line_len, &d->endian);
	if (!d->addr)
		return (0);
	mlx_loop(d->mlx_ptr);
}
