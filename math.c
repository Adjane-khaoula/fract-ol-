/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:20:14 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/25 20:04:26 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_modulo(pt point)
{
	 return (sqrt((point.x * point.x)+ (point.y * point.y)));                                                                                                                               
}

pt	ft_multiple(pt z1, pt z2)
{
	pt z_multiple;
	
	// z_multiple = ft_int_point(z_multiple);
	z_multiple.x = (z1.x * z2.x) - (z1.y * z2.y);
	z_multiple.y = (z1.x * z2.y) + (z2.x * z1.y);
	return (z_multiple);
}

pt	ft_add(pt	z, pt	c)
{
	pt	z_add;
	
	// z_add = ft_int_point(z_add);
	z_add.x = z.x + c.x;
	z_add.y = z.y + c.y;
	return(z_add);
}

