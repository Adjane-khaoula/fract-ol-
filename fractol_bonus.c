/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:23:59 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/04 16:03:50 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot_bonus(t_pt c)
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

int	ft_Burning_Ship(t_pt c)
{
	t_pt	z;
	t_pt	z_multiple;
	int		n;

	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z.x = fabsl(z.x);
		z.y = fabsl(z.y);
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return (n);
}
