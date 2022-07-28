/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:48:52 by kadjane           #+#    #+#             */
/*   Updated: 2022/07/27 03:26:10 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include <stdlib.h>	
// #include <mlx.h>
// #include <math.h>

// // typedef struct	s_data {
// // 	void	*img;
// // 	char	*addr;
// // 	int		bits_per_pixel;
// // 	int		line_length;
// // 	int		endian;
// // }				t_data;

// // void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// // {
// // 	char	*dst;

// // 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// // 	*(unsigned int*)dst = color;
// // }

// // typedef struct	s_vars {
// // 	void	*mlx;
// // 	void	*win;
// // }				t_vars;

// // int	hook(int x, t_vars *vars)
// // {
// // 	printf("x = %d\n", x);
// // 	if (x == 126)
// // 		mlx_pixel_put(vars->mlx, vars->win, 50, 50, 0x00FF00);
// // 	if (x == 125)
// // 		mlx_pixel_put(vars->mlx, vars->win, 60, 60, 0xFFFFFF);
// // 	// while(++i < 1000 && ++j < 1000)
// // 	// 	my_mlx_pixel_put(&img, 50,j, 0x0000FF00);
// // 	return (0);
// // }

// // int	main(void)
// // {
// // 	t_vars	*vars;

// // 	vars = malloc(sizeof(t_vars));
// // 	vars->mlx = mlx_init();
// // 	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
// // 	// img.img = mlx_new_image(mlx, 1920, 1080);
// // 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// // 	mlx_hook(vars->win, 2, 0L,hook, vars);
// // 	mlx_loop(vars->mlx);
// // }
// //***************************************************************************************************************************************



// typedef struct	s_data {
// 		void	*img;
// 		char	*addr;
// 		int		bits_per_pixel;
// 		int		line_length;
// 		int		endian;
// 		void	*mlx;
// 		void	*win;
// 		}	t_data;
		
// typedef struct	s_vars {

// 	}			t_vars;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	close(int x, t_data *bd)
// {
// 	printf("x = %d\n", x);
// 	if (x == 53)
// 	{
// 		mlx_destroy_window(bd->mlx, bd->win);
// 		exit(0);
// 	}
		
// 	return (0);
// }

// int	exit_hook(int keyhook,t_data *data)
// {
// 	exit(0);
// }

// int	cercle(t_data *bd)
// {
// 	int		x0;
// 	int		y0;
// 	int		r;
// 	int 	a;
// 	int		b;
// 	float	y;

// 	x0 = 200;
// 	y0 = 100;
// 	r = 50;
// 	a = x0 - r;
// 	b = x0 + r;

	
// 	while (a <= b)
// 	{
// 		my_mlx_pixel_put(bd, a, sqrt(pow(r,2) - pow(a - x0, 2)) + y0, 0x00FF00);
// 		my_mlx_pixel_put(bd, a, -sqrt(pow(r,2) - pow(a - x0, 2)) + y0, 0x00FF00);
// 		a++;
// 	}
// 	mlx_put_image_to_window(bd->mlx,bd->win,bd->img,100,100);
// 	mlx_hook(bd->win,2,0,close,bd);
// 	mlx_hook(bd->win, 17, 0, exit_hook, bd);
// 	return 0;
// }

// int	main(void)
// 	{
// 		t_data	*img;
		
// 		img = malloc(sizeof(t_data));
// 		img->mlx = mlx_init();
// 		img->win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
// 		img->img = mlx_new_image(img->mlx, 1920, 1080);
// 		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		 
// 		// mlx_hook(img->win, 2, 0L, cercle, img);
// 		cercle(img);
// 		mlx_loop(img->mlx);
// 		return 0;
// 	}





#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n ",keycode);
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}