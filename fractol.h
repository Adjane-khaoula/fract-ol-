/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:28:01 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/02 01:41:56 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<stdlib.h>
# include<mlx.h>
# include<math.h>
# include<stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define SPACE 49
# define ESC 53
# define RED_CROSS 8800

typedef struct s_data {
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

typedef struct point{
	long double	x;
	long double	y;
}	t_pt;

int		ft_modulo(t_pt point);
t_pt	ft_multiple(t_pt z1, t_pt z2);
t_pt	ft_add(t_pt	z, t_pt	c);
t_data	*ft_allocation_data(t_data *data);
int		keypress(int keyhook, t_data *data);
int		ft_color(t_data *data);
int		ft_draw(t_data *data);
int		ft_mandelbrot(t_pt c);
t_pt	convert_coordinate(t_pt cord_windows, t_data *data);
void	my_mlx_pixel_put(t_data *data, long double x, long double y, int color);
void	ft_windows(t_data *data);
int		ft_mlx_hooks(t_data *data);
int		ft_move(int keyhook, t_data *data);
// int		change_color(int keyhook, t_data *data);
int		ft_zoom(int keyhook, int x, int y, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_rgb(int n);
int		main(int ac, char **av);
int		ft_julia(t_pt z);
int		ft_mandelbrot_2(t_pt c);
int		ft_julia_2(t_pt z);
#endif
