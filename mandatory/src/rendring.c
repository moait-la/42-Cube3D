#include "../include/cube.h"

void	renderMapGrid(t_cube *cube)
{
	int	row;
	int	colom;
	int	x;
	int	y;

	getSquareFactor(cube);	
	row = -1;
	while (++row < NUM_ROWS)
	{
		colom = -1;
		while (++colom < NUM_COLOM)
		{
			y = -1;
			while (++y < cube->map->sqaureFactorY + 7)
			{
				x = -1;
				while (++x < cube->map->sqaureFactorX + 7)
				{
					int positionX = (colom * cube->map->sqaureFactorX) + x;
					int positionY = (row * cube->map->sqaureFactorY) + y;
					int mapValue = cube->map->map[row][colom];
					if (mapValue == 1)
						mlx_put_pixel(cube->img, positionX, positionY, 0x4B4B4B);
					else if (mapValue == 0)
						mlx_put_pixel(cube->img, positionX, positionY, 0xFFFFFF);
				}
			}	
		}
	}
}

void	renderPlayer(t_cube *cube)
{
	int	playerSize;

	playerSize = 4;
	int	i = -playerSize;
	while (++i < playerSize)
	{
		int k = -playerSize;
		while (++k < playerSize)
		{
			mlx_put_pixel(cube->img,
				cube->player->position->x + k,
				cube->player->position->y + i, 0xFF0000);
		}
	}
}

void	castRay(t_cube *cube)
{
	int endX = cube->player->position->x + 20 * cos(cube->player->degree * (PI/180));
	int endY = cube->player->position->y + 20 * sin(cube->player->degree * (PI/180));

	float deltaX = endX - cube->player->position->x;
	float deltaY = endY - cube->player->position->y;

	int steps;
	if (fabsf(deltaX) > fabsf(deltaY))
		steps = fabsf(deltaX);
	else
		steps = fabsf(deltaY);

	float xInc = deltaX / steps;
	float yInc = deltaY / steps;

	float tmpx = cube->player->position->x;
	float tmpy = cube->player->position->y;
	int i = -1;
	while (++i < steps)
	{
		mlx_put_pixel(cube->img, tmpx, tmpy, 0xFF0000);
		tmpx += xInc;
		tmpy += yInc;
	}
}
