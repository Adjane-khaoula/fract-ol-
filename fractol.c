/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:04:46 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/29 17:30:35 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
		
int	ft_mandelbrot(pt c)
{
	pt	z;
	pt	z_multiple;
	int	n;
	
	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return(n);
}

pt	Convert_coordinate(pt cord_windows, t_data *data)
{
	pt	cord_fractol;
	cord_fractol.x= (data->start_reel + ((cord_windows.x ) / width)
		*(data->end_reel - data->start_reel));
	cord_fractol.y= (data->start_imag + (cord_windows.y / height)
		*(data->end_imag - data->start_imag));
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

int	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->win,2,0,keypress,data);
	mlx_key_hook(data->win,close,data);
	mlx_mouse_hook(data->win, ft_zoom,data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	return(0);
}

void	ft_windows(t_data *data)
{
	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fractol");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	
	data->start_reel = -2;
	data->end_reel = 2;
	data->start_imag = -2;
	data->end_imag = 2;
	data->dx = 0.2;
	ft_draw(data);
	mlx_loop_hook(data->mlx, ft_mlx_hooks, data);
	mlx_loop(data->mlx);
	
}

int ft_draw(t_data *data)
{
	pt	c;
	int	n;
	int	color;
	
	c.x = 0;
	while (c.x++ <= width)
	{
		c.y = 0;
		while (c.y++ <= height)
		{
			n = ft_mandelbrot(Convert_coordinate(c,data));
			color = ft_color(n);
			my_mlx_pixel_put(data, c.x , c.y, color);
		}
	}
	
	mlx_put_image_to_window(data->mlx,data->win,data->img,0,0);
	return (0);
}


int	main(void)
{
	t_data	*data;
	
	ft_windows(data);
	return 0;
	}