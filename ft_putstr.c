/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:44:41 by kadjane           #+#    #+#             */
/*   Updated: 2022/08/04 17:38:54 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_write(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	char	*nul;

	nul = "(null)";
	if (!str)
	{
		while (*nul)
			ft_write(*nul++);
	}
	else
	{
		while (*str)
			ft_write(*str++);
	}
}
