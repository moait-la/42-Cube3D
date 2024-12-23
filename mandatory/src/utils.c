#include "../include/cube.h"

void	initStartingValues(t_cube *cube)
{
	cube->player->position->x = WIDTH/2;
	cube->player->position->y = HEIGHT/2;
	cube->player->degree = 0;
	cube->player->speed = 3;
	cube->player->movment->moveForward = false;
	cube->player->movment->moveBack = false;
	cube->player->movment->rotateLeft = false;
	cube->player->movment->rotateLeft = false;
}

void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		ft_error("Error Malloc failed\n");
	return (ptr);
}

void	allocations(t_cube *cube)
{
	cube->map = (t_map *)ft_malloc(sizeof(t_map));
	cube->player = (t_player *)ft_malloc(sizeof(t_player));
	cube->player->position = (t_point *)ft_malloc(sizeof(t_point));
	cube->player->movment = (t_movment *)ft_malloc(sizeof(t_movment));
	cube->ray = (t_ray *)ft_malloc(sizeof(t_ray) * WIDTH);
}

void	myPixelPut(t_cube *cube, int x, int y, int color)
{
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	mlx_put_pixel(cube->img, x, y, color);
}

void	getSquareFactor(t_cube *cube)
{
	int	scaleX;
	int	scaleY;

	scaleX = WIDTH/NUM_COLOM;
	scaleY = HEIGHT/NUM_ROWS;

	cube->map->sqaureFactorX = scaleX;
	cube->map->sqaureFactorY = scaleY;
}
