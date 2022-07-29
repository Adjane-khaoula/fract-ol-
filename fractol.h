/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:28:01 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/29 19:10:36 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>	
#include <mlx.h>
#include <math.h>
#include<stdio.h>
#define width 1000
#define height 1000
#define	MAX_ITER 60
 
typedef struct	s_data {
		void	*img;
		char	*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
		void	*mlx;
		void	*win;
		float	start_reel;
		float	end_reel;
		float	start_imag;
		float	end_imag;
		float	dx;		
		}	t_data;

typedef struct point 
{
	float	x;
	float	y;
}	pt;

int	ft_modulo(pt point);
pt	ft_multiple(pt z1, pt z2);
pt	ft_add(pt	z, pt	c);
t_data	*ft_allocation_data(t_data *data);
int	exit_hook(int keyhook,t_data *data);
int ft_color(int n);
int ft_draw(t_data *data);
int	ft_mandelbrot(pt c);
pt	Convert_coordinate(pt cord_windows, t_data *data);
void	my_mlx_pixel_put(t_data *data, float x, float y, int color);
void	ft_windows(t_data *data);
int	ft_mlx_hooks(t_data *data);
int	keypress(int keyhook, t_data *data);
int	close(int	keyhook,t_data *data);
//  int	ft_zoom(int keyhook,t_data	*data);
 int	ft_zoom(int keyhook,int	x,int y,t_data	*data);
#endif
