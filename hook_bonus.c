/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:30:50 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/03 21:01:31 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_move(int keyhook, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (keyhook == RIGHT)
	{
		data->start_reel -= data->dx;
		data->end_reel -= data->dx;
	}
	if (keyhook == LEFT)
	{
		data->start_reel += data->dx;
		data->end_reel += data->dx;
	}
	if (keyhook == DOWN)
	{
		data->start_imag -= data->dx;
		data->end_imag -= data->dx;
	}
	if (keyhook == UP)
	{
		data->start_imag += data->dx;
		data->end_imag += data->dx;
	}
	if (keyhook == SPACE)
		change_color(data);
	ft_draw(data);
	return (0);
}

int	change_color(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->m += data->n;
	ft_draw(data);
	return (0);
}
