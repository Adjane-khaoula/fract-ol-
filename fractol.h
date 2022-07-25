/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:28:01 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/25 23:00:43 by kadjane          ###   ########.fr       */
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
 
#define width 1000
#define height 1000
#define	MAX_ITER 80

int	ft_modulo(pt point);
pt	ft_multiple(pt z1, pt z2);
pt	ft_add(pt	z, pt	c);
t_data	*ft_allocation_data(t_data *data);
int	exit_hook(int keyhook,t_data *data);
int	close(int x, t_data *bd);
#endif
