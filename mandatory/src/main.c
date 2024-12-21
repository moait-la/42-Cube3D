#include "../include/cube.h"

void	render(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	updatePosition(cube);
	renderMapGrid(cube);
	renderPlayer(cube);
	castRay(cube);
}

int main()
{
	t_cube cube;

	cube.window = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
	if (!cube.window)
		ft_error("Error Creating Window\n");

	cube.img = mlx_new_image(cube.window, (uint32_t)WIDTH, (uint32_t)HEIGHT);
	if (!cube.img)
		ft_error("Error Allocating Img Buffer\n");

	allocations(&cube);
	getMap(&cube);


	initStartingValues(&cube);


	updatePosition(&cube);
	render(&cube);

	mlx_key_hook(cube.window, keyPress, &cube);	

	mlx_image_to_window(cube.window, cube.img, 0, 0);
	mlx_loop_hook(cube.window, render, &cube);
	mlx_loop(cube.window);

    return 0;
}

/*
WIDTH 1700
HEIGHT 1000
*/