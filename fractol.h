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

# define WIN_X		1100
# define WIN_Y		1100
# define MIN_X		-3
# define ESC		0xFF1B
# define CLR_VAR	0x00000011
# define ITER_MAX	200

// redefine path at 42
# include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
} t_mlx

int		ft_strcmp(char *s1, char*s2);
void	print_av_list(void);

#endif
