/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:08:41 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/02 01:57:11 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			data->n_frac = 1;
		if (!ft_strcmp(av[1], "julia"))
			data->n_frac = 2;
		if (!ft_strcmp(av[1], "mandelbrot_2"))
			data->n_frac = 3;
		if (!ft_strcmp(av[1], "julia_2"))
			data->n_frac = 4;
		ft_windows(data);
	}
	return (0);
}
