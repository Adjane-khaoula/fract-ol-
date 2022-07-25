/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:28:01 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/25 15:08:38 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>	
#include <mlx.h>
#include <math.h>
#include<stdio.h>

typedef struct	s_data {
		void	*img;
		char	*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
		void	*mlx;
		void	*win;
		}	t_data;

typedef struct point 
{
	float	x;
	float	y;
}	pt;

typedef struct	s_coordinate
 {
	int	start_reel;
	int	end_reel;
	int	start_imag;
	int	end_imag;
	
 }	t_coordinate;
 
#define width 700
#define height 700
#define	MAX_ITER 80

int	ft_modulo(pt *point);
pt	*ft_multiple(pt *z1, pt *z2);
pt	*ft_add(pt	*z, pt	*c);
pt	*ft_allocation_point(pt	*point);
t_data	*ft_allocation_data(t_data *data);
t_coordinate    *ft_allocation_coordinate(t_coordinate *coordinate);

#endif
