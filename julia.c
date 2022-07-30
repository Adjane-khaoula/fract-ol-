/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:35:30 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/30 18:52:43 by kadjane          ###   ########.fr       */
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
