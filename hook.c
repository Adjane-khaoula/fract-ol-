/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:40:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/04 16:34:13 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom(int keyhook, int x, int y, t_data *data)
{
	// printf("%d\n",keyhook);
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
	if (keyhook == ESC )
	{
		free (data);
		exit (0);
	}
	return (0);
}

int	cross(t_data *data)
{
	free (data);
	exit (0);
	return (0);
}