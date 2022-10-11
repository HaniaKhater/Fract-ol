/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:37:33 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/10 01:38:19 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	ft_quit(void)
{
	ft_putstr("quit");
	exit(1);
	return (0);
}

int	trigger(int key, t_mlx *d)
{
	if (key == ESC)
	{
		ft_putstr("ESC quit\n");
		exit(0);
		return (0);
	}
	if (key == SPC)
		d->color += 0x00abc123; //test others
	if (key == Q)
		d->julia_x_var += 0.1;
	if (key == W)
		d->julia_x_var -= 0.1;
	if (key == A)
		d->julia_y_var += 0.1;
	if (key == S)
		d->julia_y_var -= 0.1;
	ft_putstr("triggered\n");
	fractol(d, 1);
	ft_putstr("passed key hook\n");
	return (0);
}

int	zoom(int key, int x, int y, t_mlx *d)
{
	float	scale_x;
	float	scale_y;

	scale_x = (d->xmax - d->xmin) / WIN_X;
	scale_y = (d->ymax - d->ymin) / WIN_Y;
	if (key == ZOOM_IN)
	{
		d->xmin = (d->xmin + (ZOOM_VAR * scale_x * x));
		d->xmax = (d->xmax - (ZOOM_VAR * scale_x * (WIN_X - x)));
		d->ymin = (d->ymin + (ZOOM_VAR * scale_y * (WIN_Y - y)));
		d->ymax = (d->ymax - (ZOOM_VAR * scale_y * y));
	}
	if (key == ZOOM_OUT)
	{
		d->xmin = (d->xmin - (ZOOM_VAR * scale_x * x));
		d->xmax = (d->xmax + (ZOOM_VAR * scale_x * (WIN_X - x)));
		d->ymin = (d->ymin - (ZOOM_VAR * scale_y * (WIN_Y - y)));
		d->ymax = (d->ymax + (ZOOM_VAR * scale_y * y));
	}
	fractol(d, 1);
	ft_putstr("zoomed");
	return (0);
}