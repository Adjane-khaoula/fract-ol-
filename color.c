/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:28:52 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/27 13:07:02 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_RGB(int n)
{   
    int t;
    int r;
    int g;
    int b;
    
  
    
    t = pow(n ,5) * 255;
    r = pow(n,6) * 255;
    g = pow(n,4) * 255; 
    b = pow(n,2) * 255;
    return (t << 24 | r << 16 | g << 8 | b);
}

int ft_color(int n)
{
    int color;
    
    if (n == MAX_ITER)
        color = 0 ;
    else 
        color = ft_RGB(n);
    return (color);
}