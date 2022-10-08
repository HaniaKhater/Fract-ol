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

int	set_up_win(t_mlx d)
{
	d->mlx_ptr = mlx_init(void);
	d->win_ptr = mlx_new_window(d->mlx_ptr);
	d->img_ptr = mlx_new_image(d->mlx_ptr, d->win_ptr);
	d->addr = mlx_get_data_addr(d->img_ptr);
	mlx_loop(d->mlx_ptr);
}
