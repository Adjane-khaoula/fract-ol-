/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:40:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/29 19:53:02 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	keypress(int keyhook, t_data *data)
{
	mlx_clear_window(data->mlx,data->win);
	if (keyhook == 124)
	{
		data->start_reel = data->start_reel -  data->dx;
		data->end_reel = data->end_reel - data->dx;
	}
	if (keyhook == 123)
	{
		data->start_reel = data->start_reel +  data->dx;
		data->end_reel = data->end_reel + data->dx;
	}
	if (keyhook == 125)
	{
		data->start_imag = data->start_imag -  data->dx;
		data->end_imag = data->end_imag - data->dx;
	}
	if (keyhook == 126)
	{
		data->start_imag= data->start_imag + data->dx;
		data->end_imag= data->end_imag +  data->dx;
	}
	ft_draw(data);
	return (0);
}

// int ft_draw_zoom(t_data *data)
// {
// 	pt	c;
// 	int	n;
// 	int	color;
	
// 	c.x = data->x;
// 	c.y = data->y;
	
// 	n = ft_mandelbrot(Convert_coordinate(c,data));
// 	color = ft_color(n);
// 	my_mlx_pixel_put(data, c.x , c.y, color);
// 	return(0);

// }



int	ft_zoom(int keyhook, int x, int y, t_data	*data)
{
	pt c;
	pt cv;
	
	mlx_clear_window(data->mlx,data->win);
	
	c.x = x;
	c.y = y;
	cv = Convert_coordinate(c,data);
	if (keyhook == 4)
	{
		data->start_reel = data->start_reel -  ((data->end_reel - cv.x) / 10);
		data->end_reel = data->end_reel + ((cv.x - data->start_reel) / 10);
		data->start_imag= data->start_imag - ((data->end_imag - cv.y) / 10);
		data->end_imag= data->end_imag + ((cv.y - data->start_imag) / 10);
	}
	
	if (keyhook == 5)
	{
		data->start_reel = data->start_reel +  ((data->end_reel - cv.x) / 10);
		data->end_reel = data->end_reel - ((cv.x - data->start_reel) / 10);
		data->start_imag = data->start_imag +  ((data->end_imag - cv.y) / 10);
		data->end_imag = data->end_imag - ((cv.y - data->start_imag) / 10);
	}
	ft_draw(data);
	return (0);
}

 
int	close(int	keyhook,t_data *data)
{
	if (keyhook == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return(0);
}

int	exit_hook(int keyhook,t_data *data)
{
	exit(0);
}

