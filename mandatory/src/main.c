#include "../include/cube.h"
  #include <sys/time.h>

void	updatePosition(t_cube *cube);

void	render(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	updatePosition(cube);
	renderMapGrid(cube);
	renderPlayer(cube);
	castRay(cube);
}

void	keyRelease(mlx_key_data_t keydata, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->moveFront = false;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->moveBack = false;
}

void	keyPress(mlx_key_data_t keydata, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->movment->moveFront = true;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->movment->moveBack = true;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->moveFront = false;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->moveBack = false;
}

long    getTime()
{
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);
    long milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (milliseconds);
}

void	moveForward(t_cube *cube)
{
	float	degreeRad;
	float	newX;
	float	newY;

	degreeRad = cube->player->degree * (PI/180);
	newX = cube->player->position->x + (cos(degreeRad) * cube->player->speed);
	newY = cube->player->position->y + (sin(degreeRad) * cube->player->speed);
	cube->player->position->x = newX;
	cube->player->position->y = newY;
}

void	moveBack(t_cube *cube)
{
	float	degreeRad;
	float	newX;
	float	newY;

	degreeRad = cube->player->degree * (PI/180);
	newX = cube->player->position->x - (cos(degreeRad) * cube->player->speed);
	newY = cube->player->position->y - (sin(degreeRad) * cube->player->speed);
	cube->player->position->x = newX;
	cube->player->position->y = newY;
}

void	updatePosition(t_cube *cube)
{
	if (getTime() - cube->lastFameUpdate < 16.67 && cube->lastFameUpdate != 0)
		return ;
	if (cube->player->movment->moveFront == true)
		moveForward(cube);
	if (cube->player->movment->moveBack == true)
		moveBack(cube);
	cube->lastFameUpdate = getTime();
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

	getMap(&cube);


	initStartingValues(&cube);

	cube.lastFameUpdate = 0;
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