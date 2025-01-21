#include "../include/cube.h"

void	renderStripe(t_cube *cube, int topP, int botP, int c)
{
	int	k;
	int	color;

	k = topP - 1;
	while (++k < botP)
	{
		if (cube->ray[c].closestHit == HORIZONTAL)
		{
			color = getColor(0, 148, 153, 255);
			myPixelPut(cube, c, k, color);
		}
		else
		{

			color = getColor(0, 173, 179, 255);
			myPixelPut(cube, c, k, color);
		}
	}
}

void	renderCeiling(t_cube *cube, int c, int topPixel)
{
	int	k;
	int	color;

	k = -1;
	while (++k < topPixel)
	{
		color = getColor(120, 208, 200, 255);
		myPixelPut(cube, c, k, color);
	}
}

void	renderFloor(t_cube *cube, int c, int botPixel)
{
	int	color;

	while (botPixel < cube->window->height)
	{
		color = getColor(82, 67, 48,255);
		myPixelPut(cube, c, botPixel, color);
		botPixel++;
	}
}


void	renderMapGrid(t_cube *cube)
{
	int	row;
	int	colom;
	float	mapSizeFactor;
	
	row = -1;
	mapSizeFactor = 0.1;
	while (++row < NUM_ROWS)
	{
		colom = -1;
		while (++colom < NUM_COLOM)
		{
			int y = -1;
			while (++y < cube->map->sqaureFactorX * mapSizeFactor)
			{
				int x = -1;
				while (++x < cube->map->sqaureFactorX * mapSizeFactor)
				{
					int positionX = (colom * cube->map->sqaureFactorX * mapSizeFactor) + x;
					int positionY = (row * cube->map->sqaureFactorX * mapSizeFactor) + y;
					if (row >= NUM_ROWS || colom >= NUM_COLOM || row < 0 || colom < 0)
                        return;
					int mapValue = cube->map->map[row][colom];
                    if (mapValue == 1)
                        myPixelPut(cube, positionX, positionY, 0x4B4B4B);
                    else if (mapValue == 0)
                        myPixelPut(cube, positionX, positionY, 0xFFFFFF);
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
