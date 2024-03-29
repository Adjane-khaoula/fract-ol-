/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:28:52 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/03 20:59:14 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_rgb(int n)
{
	return (0 << 24 | (n * 10) % 255 << 16
		| (n * 20) % 255 << 8 | (n * 30) % 255);
}

int	ft_color(t_data *data)
{
	int	color;

	if (data->n == MAX_ITER)
		color = 0 ;
	else
	{
		if (data->n + data->m == MAX_ITER)
			color = 0 ;
		else
			color = ft_rgb(data->n + data->m);
	}
	return (color);
}
