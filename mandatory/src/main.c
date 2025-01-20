/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 04:06:21 by zqouri            #+#    #+#             */
/*   Updated: 2025/01/19 01:35:07 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	updatePosition(cube);
	renderMapGrid(cube);
	renderPlayer(cube);
	castRay(cube);
	// castAllRays(cube);
}

int main(int argc, char *argv[])
{
	// t_cube cube;
	t_maap	*map;

	if (argc != 2)
		return (ft_error("Error: Invalid Number of Arguments\n"), 1);
	map = init_map(argv[1]);
	pars(map);
	//rendering
	
	// cube.window = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
	// if (!cube.window)
	// 	ft_error("Error Creating Window\n");

	// cube.img = mlx_new_image(cube.window, WIDTH, HEIGHT);
	// if (!cube.img)
	// 	ft_error("Error Allocating Img Buffer\n");

	// allocations(&cube);
	// getMap(&cube);
	// initStartingValues(&cube);

	// updatePosition(&cube);
	// render(&cube);

	// mlx_key_hook(cube.window, keyPress, &cube);	
	// mlx_image_to_window(cube.window, cube.img, 0, 0);
	// mlx_loop_hook(cube.window, render, &cube);
	// mlx_loop(cube.window);

    return 0;
}

/*
WIDTH 1700
HEIGHT 1000
*/