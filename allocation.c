/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:04:12 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/25 19:48:36 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


pt	*ft_allocation_point(pt	*point)
{
	point = malloc(sizeof(pt));
	return (point);	
}

t_data	*ft_allocation_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	return (data);
}

t_coordinate	*ft_allocation_coordinate(t_coordinate *coordinate)
{
	coordinate = malloc(sizeof(t_coordinate));
	return (coordinate);
}