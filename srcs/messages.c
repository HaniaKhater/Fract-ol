/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:14:01 by hkhater           #+#    #+#             */
/*   Updated: 2022/10/08 02:14:11 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

void	print_av_list(void)
{
	ft_putstr("****************************************************\n");
	ft_putstr("*--------------------------------------------------*\n");
	ft_putstr("*        Try ./fractol <available fractal>         *\n");
	ft_putstr("*--------------------------------------------------*\n");
	ft_putstr("*--------------------------------------------------*\n");
	ft_putstr("*********** List of available fractals: ************\n");
	ft_putstr("*--------------------------------------------------*\n");
	ft_putstr("*------------------- Julia ------------------------*\n");
	ft_putstr("*----------------- Mandelbrot ---------------------*\n");
	ft_putstr("*----------------- ?????????? ---------------------*\n");
	ft_putstr("*--------------------------------------------------*\n");
	ft_putstr("****************************************************\n");
}
