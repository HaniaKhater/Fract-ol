/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:14:30 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/08 02:14:34 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X		1000
# define WIN_Y		1000
# define MIN_X		-2.0
# define MAX_X		2.0
# define MIN_Y		-2.0
# define MAX_Y		2.0
# define ZOOM_VAR	0.25
# define ZOOM_IN	4
# define ZOOM_OUT	5
# define ESC		0xFF1B
# define Q			0x71
# define W			0x77
# define A			0x61
# define S			0x73
# define SPC		0x20
# define CLR		0x00001111
# define CLR_VAR	0x00abc123
# define ITER_MAX	255

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_mlx
{
	char	*name;
	int		fractal;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		line_len;
	int		bpp;
	int		endian;
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		done_x;
	int		done_y;
	int		color;
	int		julia_x_var;
	int		julia_y_var;
} t_mlx;

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char*s2);
void	print_av_list(void);
int		set_up_win(t_mlx *d);
void	fractol(t_mlx *d, int update);
void	draw(t_mlx *d);
int		loop_pp(t_mlx *d);
int		julia_pp(t_mlx *d, double r, double i);
int		mandelbrot_pp(t_mlx *d, double r, double i);
int		burning_ship(t_mlx *mlx);
void	custom_pixel(t_mlx *mlx, int x, int y, int color);
int		ft_quit(void);
int		trigger(int key, t_mlx *d);
int		zoom(int key, int x, int y, t_mlx *d);

#endif
