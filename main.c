/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:08:41 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/30 20:08:08 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*data;
	if (ac >1)
	{
        if (ft_strcmp(av[1] , "mandelbrot.c") == 0)
	    {
	    	data->n_frac = 1;
	    	ft_windows(data);
	    }
        if (ft_strcmp(av[1] , "julia.c") == 0)
	    {
	    	data->n_frac = 2;
	    	ft_windows(data);
	    }
    }
	//system ("leaks a.out");
	return 0;
	}