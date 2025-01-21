#include "../include/cube.h"

void	myPixelPut(t_cube *cube, int x, int y, int color)
{
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	mlx_put_pixel(cube->img, x, y, color);
}

void	getSquareFactor(t_cube *cube)
{
	cube->map->sqaureFactorX = floor(WIDTH/NUM_COLOM);
	cube->map->sqaureFactorY = floor(HEIGHT/NUM_ROWS);
}

int	getColor(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void	getClosestHit(t_cube *cube, int colom)
{
	float	horizDist;
	float	vertiDist;

	horizDist = sqrt(pow(cube->ray[colom].horizHitP->x - cube->player->x, 2) +
		pow(cube->ray[colom].horizHitP->y - cube->player->y, 2));
	vertiDist = sqrt(pow(cube->ray[colom].vertiHitP->x - cube->player->x, 2) +
		pow(cube->ray[colom].vertiHitP->y - cube->player->y, 2));
	if (horizDist < vertiDist)
	{
		cube->ray[colom].closestHit = HORIZONTAL;
		cube->ray[colom].distance = horizDist;
		return ;
	}
	cube->ray[colom].closestHit = VERTICAL;
	cube->ray[colom].distance = vertiDist;
}
