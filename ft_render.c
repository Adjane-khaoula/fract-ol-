/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:00:51 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/02 01:46:21 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_windows(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->start_reel = -2;
	data->end_reel = 2;
	data->start_imag = -2;
	data->end_imag = 2;
	data->dx = 0.2;
	data->m = 0;
	ft_draw(data);
	mlx_loop_hook(data->mlx, ft_mlx_hooks, data);
	mlx_loop(data->mlx);
}

int	ft_draw(t_data *data)
{
	t_pt	c;
	int		color;

	c.x = 0;
	while (c.x++ <= WIDTH)
	{
		c.y = 0;
		while (c.y++ <= HEIGHT)
		{
			if (data->n_frac == 1)
				data->n = ft_mandelbrot(convert_coordinate(c, data));
			if (data->n_frac == 2)
				data->n = ft_julia(convert_coordinate(c, data));
			if (data->n_frac == 3)
				data->n = ft_mandelbrot_2(convert_coordinate(c, data));
			if (data->n_frac == 4)
				data->n = ft_julia_2(convert_coordinate(c, data));
			color = ft_color(data);
			my_mlx_pixel_put(data, c.x, c.y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

t_pt	convert_coordinate(t_pt cord_windows, t_data *data)
{
	t_pt	cord_fractol;

	cord_fractol.x = (data->start_reel + (cord_windows.x / WIDTH)
			*(data->end_reel - data->start_reel));
	cord_fractol.y = (data->start_imag + (cord_windows.y / HEIGHT)
			*(data->end_imag - data->start_imag));
	return (cord_fractol);
}

void	my_mlx_pixel_put(t_data *data, long double x, long double y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = data->addr + ((int)y * data->line_length + (int)x
				*(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 0, ft_move, data);
	mlx_mouse_hook(data->win, ft_zoom, data);
	mlx_key_hook(data->win, keypress, data);
	mlx_hook(data->win, 17, 0, keypress, data);
	return (0);
}
