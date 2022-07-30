/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:40:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/30 17:44:56 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	ft_move(int keyhook, t_data *data)
{
	mlx_clear_window(data->mlx,data->win);
	if (keyhook == right)
	{
		data->start_reel = data->start_reel -  data->dx;
		data->end_reel = data->end_reel - data->dx;
	}
	if (keyhook == left)
	{
		data->start_reel = data->start_reel +  data->dx;
		data->end_reel = data->end_reel + data->dx;
	}
	if (keyhook == down)
	{
		data->start_imag = data->start_imag -  data->dx;
		data->end_imag = data->end_imag - data->dx;
	}
	if (keyhook == up)
	{
		data->start_imag= data->start_imag + data->dx;
		data->end_imag= data->end_imag +  data->dx;
	}
	ft_draw(data);
	return (0);
}

int	ft_zoom(int keyhook, int x, int y, t_data	*data)
{
	pt c;
	pt cv;
	
	mlx_clear_window(data->mlx,data->win);
	c.x = x;
	c.y = y;
	cv = Convert_coordinate(c,data);
	if (keyhook == mouse_up)
	{
		data->start_reel +=  (data->start_reel - cv.x) / 10;
		data->end_reel -= (cv.x - data->end_reel) / 10;
		data->start_imag += (data->start_imag - cv.y) / 10;
		data->end_imag -= (cv.y - data->end_imag) / 10;
	}
	if (keyhook == mouse_down)
	{
		data->start_reel -=((data->start_reel - cv.x) / 10);
		data->end_reel += ((cv.x - data->end_reel) / 10);
		data->start_imag -= ((data->start_imag - cv.y) / 10);
		data->end_imag += ((cv.y - data->end_imag) / 10);
	}
	ft_draw(data);
	return (0);
}

int	keypress(int keyhook,t_data *data)
{
	if (keyhook == space)
	{
		mlx_clear_window(data->mlx,data->win);
		data->m += data->n;
		ft_draw(data);
	}
	if(keyhook == esc || keyhook == red_cross)
		exit(0);
	return(0);
}

