/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:40:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/28 19:37:46 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	keypress(int keyhook, t_data *data)
{
	
	mlx_clear_window(data->mlx,data->win);
	if (keyhook == 124)
	{
		data->start_reel = data->start_reel - (data->end_reel-data->start_reel) / data->dx;
		data->end_reel = data->end_reel - (data->end_reel-data->start_reel) / data->dx;
	}
	if (keyhook == 123)
	{
		data->start_reel = data->start_reel + ((data->end_reel - data->start_reel) / data->dx);
		data->end_reel = data->end_reel + (data->end_reel - data->start_reel) / data->dx;
	}
	if (keyhook == 125)
	{
		data->start_imag = data->start_imag - ((data->end_imag - data->start_imag) / data->dx);
		data->end_imag = data->end_imag - ((data->end_imag - data->start_imag )/ data->dx);
	}
	if (keyhook == 126)
	{
		data->start_imag= data->start_imag + (data->end_imag - data->start_imag / data->dx);
		data->end_imag= data->end_imag + ((data->end_imag - data->start_imag) / data->dx);
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

