/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:28:52 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/02 01:01:33 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_rgb(int n)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = pow(n, 5) * 255;
	r = pow(n, 6) * 255;
	g = pow(n, 4) * 255;
	b = pow(n, 2) * 255;
	return (t << 24 | r << 16 | g << 8 | b);
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
