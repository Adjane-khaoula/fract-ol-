/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:56:39 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/02 01:49:58 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_pt c)
{
	t_pt	z;
	t_pt	z_multiple;
	int		n;

	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return (n);
}

int	ft_mandelbrot_2(t_pt c)
{
	t_pt	z;
	t_pt	z_multiple;
	int		n;

	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z_multiple = ft_multiple(z_multiple, z_multiple);
		z = ft_add(z_multiple, c);
		n++;
	}
	return (n);
}

int	ft_julia(t_pt z)
{
	t_pt	c;
	t_pt	z_multiple;
	int		n;

	n = 0;
	c.x = -0.74543;
	c.y = 0.11301;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return (n);
}

int	ft_julia_2(t_pt z)
{
	t_pt	c;
	t_pt	z_multiple;
	int		n;

	n = 0;
	c.x = -0.4;
	c.y = 0.6;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return (n);
}
