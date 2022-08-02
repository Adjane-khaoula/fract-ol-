/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:40:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/02 01:55:18 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_move(int keyhook, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (keyhook == RIGHT)
	{
		data->start_reel = data->start_reel - data->dx;
		data->end_reel = data->end_reel - data->dx;
	}
	if (keyhook == LEFT)
	{
		data->start_reel = data->start_reel + data->dx;
		data->end_reel = data->end_reel + data->dx;
	}
	if (keyhook == DOWN)
	{
		data->start_imag = data->start_imag - data->dx;
		data->end_imag = data->end_imag - data->dx;
	}
	if (keyhook == UP)
	{
		data->start_imag = data->start_imag + data->dx;
		data->end_imag = data->end_imag + data->dx;
	}
	ft_draw(data);
	return (0);
}

int	ft_zoom(int keyhook, int x, int y, t_data *data)
{
	t_pt	c;
	t_pt	cv;

	c.x = x;
	c.y = y;
	mlx_clear_window(data->mlx, data->win);
	cv = convert_coordinate(c, data);
	if (keyhook == MOUSE_UP)
	{
		data->start_reel += (data->start_reel - cv.x) / 10;
		data->end_reel -= (cv.x - data->end_reel) / 10;
		data->start_imag += (data->start_imag - cv.y) / 10;
		data->end_imag -= (cv.y - data->end_imag) / 10;
	}
	if (keyhook == MOUSE_DOWN)
	{
		data->start_reel -= ((data->start_reel - cv.x) / 10);
		data->end_reel += ((cv.x - data->end_reel) / 10);
		data->start_imag -= ((data->start_imag - cv.y) / 10);
		data->end_imag += ((cv.y - data->end_imag) / 10);
	}
	ft_draw(data);
	return (0);
}

int	keypress(int keyhook, t_data *data)
{
	if (keyhook == SPACE)
	{
		mlx_clear_window(data->mlx, data->win);
		data->m += data->n;
		ft_draw(data);
	}
	if (keyhook == ESC || keyhook == RED_CROSS)
		exit (0);
	return (0);
}
