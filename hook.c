/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:40:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/23 16:56:50 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(int keyhook,t_data *data)
{
	exit(0);
}

int	close(int x, t_data *bd)
{
	if (x == 53)
	{
		mlx_destroy_window(bd->mlx, bd->win);
		exit(0);
	}
		
	return (0);
}

