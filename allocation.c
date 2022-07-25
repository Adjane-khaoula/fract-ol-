/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:04:12 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/25 20:19:29 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_data	*ft_allocation_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	return (data);
}

// t_coordinate	*ft_allocation_coordinate(t_coordinate *coordinate)
// {
// 	coordinate = malloc(sizeof(t_coordinate));
// 	return (coordinate);
// }