/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:56:39 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/01 23:27:19 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
		
int	ft_mandelbrot(pt c)
{
	pt	z;
	pt	z_multiple;
	int	n;
	
	n = 0;
	z.x = 0;
	z.y = 0;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return(n);
}

int	ft_julia(pt z)
{
	pt	c;
	pt	z_multiple;
	int	n;
	
	n = 0;
	c.x = -0.8;
	c.y = 0.156;
	while (ft_modulo(z) <= 2 && n < MAX_ITER)
	{
		z_multiple = ft_multiple(z, z);
		z = ft_add(z_multiple, c);
		n++;
	}
	return(n);
}

