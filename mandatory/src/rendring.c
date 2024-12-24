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
				cube->player->x + k,
				cube->player->y + i, 0xFF0000);
		}
	}
}
