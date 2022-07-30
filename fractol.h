/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:28:01 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/30 19:39:51 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>	
#include <mlx.h>
#include <math.h>
#include <stdio.h>


#define width 1000
#define height 1000
#define	MAX_ITER 60
#define up 126
#define down 125
#define left 123
#define right 124
#define mouse_up 4
#define mouse_down 5
#define space	49
#define esc	53
#define red_cross 8800
 
typedef struct	s_data {
		void		*img;
		char		*addr;
		int			bits_per_pixel;
		int			line_length;
		int			endian;
		void		*mlx;
		void		*win;
		
		long double	start_reel;
		long double	end_reel;
		long double	start_imag;
		long double	end_imag;
		double		m;
		double		n;
		long double	dx;
		int			n_frac;		
		}	t_data;

typedef struct point 
{
	long double	x;
	long double	y;
}	pt;

int	ft_modulo(pt point);
pt	ft_multiple(pt z1, pt z2);
pt	ft_add(pt	z, pt	c);
t_data	*ft_allocation_data(t_data *data);
int	keypress(int keyhook,t_data *data);
int ft_color(t_data *data);
int ft_draw(t_data *data);
int	ft_mandelbrot(pt c);
pt	Convert_coordinate(pt cord_windows, t_data *data);
void	my_mlx_pixel_put(t_data *data, long double x, long double y, int color);
void	ft_windows(t_data *data);
int	ft_mlx_hooks(t_data *data);
int	ft_move(int keyhook, t_data *data);
int	change_color(int	keyhook,t_data *data);
int	ft_zoom(int keyhook,int	x,int y,t_data	*data);
int	ft_strcmp(const char *s1, const char *s2);
#endif
