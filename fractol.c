/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:04:46 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/25 19:38:51 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
		
int	ft_mandelbrot(pt *c)
{
	pt	*z;
	pt	*z_multiple;
	int	n;
	
	n = 0;
	z->x = 0;
	z->y = 0;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		 z_multiple = ft_multiple(z, z);
		 z = ft_add(z_multiple, c);
		 n++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 	
	}
	return (n);
}

pt	*Convert_coordinate(pt *cord_windows)
{
	t_coordinate	*start_end_cord;
	pt				*cord_fractol;
	
	start_end_cord = ft_allocation_coordinate(start_end_cord);
	cord_fractol = ft_allocation_point(cord_fractol);
	start_end_cord->start_reel = -2;
	start_end_cord->end_reel = 2;
	start_end_cord->start_imag = -2;
	start_end_cord->end_imag = 2;
	
	
	cord_fractol->x= (start_end_cord->start_reel + (cord_windows->x / width)*(start_end_cord -> end_reel - start_end_cord -> start_reel));
	cord_fractol->y= (start_end_cord->start_imag + (cord_windows->y / width)*(start_end_cord -> end_imag - start_end_cord -> start_imag));
	return (cord_fractol);
}

void	my_mlx_pixel_put(t_data *data, float x, float y, int color)
{
	char	*dst;

	if((x >= 0 && x < width) && (y >= 0 && y < height))
	{
		dst = data->addr + ((int)y * data->line_length + (int)x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int ft_draw(t_data *data)
{
	pt	*c;
	int	n;
	int	color;
	int	i;
	int	j;

	c = ft_allocation_point(c);
	i = -1;
	j = -1;
	
	while (++i <= width)
	{
		c->x = i;
		while (++j <= height)
		{
			c->y = j;
			c = Convert_coordinate(c);
			printf("x=%lf, y=%lf\n", c->x, c->y);
			n = ft_mandelbrot(c);
			color = 255 - (n * 255 / MAX_ITER);
			my_mlx_pixel_put(data,i , j, color);
		}
	}
	mlx_put_image_to_window(data->mlx,data->win,data->img,350,350);
	return (0);
}


int	main(void)
	{
		t_data	*img;
		
		img = malloc(sizeof(t_data));
		img->mlx = mlx_init();
		img->win = mlx_new_window(img->mlx, width, height, "fractol");
		img->img = mlx_new_image(img->mlx, width, height);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		 
		ft_draw(img);
		mlx_loop(img->mlx);
		return 0;
	}