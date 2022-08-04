/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:08:41 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/04 18:43:48 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 2)
	{
		while (++i <= 6)
		{
			if ((ft_isfractol(av[1], data)) == i)
			{
				ft_guide();
				ft_windows(data);
				return (0);
			}
		}
	}
	ft_is_notfractol();
	return (0);
}

int	ft_isfractol(char *av, t_data	*data)
{
	if (!ft_strcmp(av, "mandelbrot"))
		data->n_frac = 1;
	else if (!ft_strcmp(av, "julia"))
		data->n_frac = 2;
	else if (!ft_strcmp(av, "mandelbrot_2"))
		data->n_frac = 3;
	else if (!ft_strcmp(av, "julia_2"))
		data->n_frac = 4;
	else if (!ft_strcmp(av, "julia_3"))
		data->n_frac = 5;
	else if (!ft_strcmp(av, "Burning_Ship"))
		data->n_frac = 6;
	return (data->n_frac);
}

void	ft_guide()
{
	ft_putstr("use the arrows keys for moving\n");
	ft_putstr("space for change the color\n");
	ft_putstr("scroll wheel for zooming in and out \n");
	ft_putstr("esc and red cross for exit\n");
}

void	ft_is_notfractol()
{
	ft_putstr("please write one of those fractols\n");
	ft_putstr("mandelbrot\n");
	ft_putstr("julia\n");
	ft_putstr("julia_2\n");
	ft_putstr("julia_3\n");
	ft_putstr("mandelbrot_2\n");
	ft_putstr("Burning_Ship\n");
}