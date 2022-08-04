/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:20:14 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/04 16:04:00 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_modulo(t_pt point)
{
	return (sqrt((point.x * point.x) + (point.y * point.y)));
}

t_pt	ft_multiple(t_pt z1, t_pt z2)
{
	t_pt	z_multiple;

	z_multiple.x = (z1.x * z2.x) - (z1.y * z2.y);
	z_multiple.y = (z1.x * z2.y) + (z2.x * z1.y);
	return (z_multiple);
}

t_pt	ft_add(t_pt	z, t_pt	c)
{
	t_pt	z_add;

	z_add.x = z.x + c.x;
	z_add.y = z.y + c.y;
	return (z_add);
}
