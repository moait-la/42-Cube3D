#include "../include/cube.h"

void	getSquareFactor(t_cube *cube)
{
	int	scaleX;
	int	scaleY;

	scaleX = WIDTH/NUM_COLOM;
	scaleY = HEIGHT/NUM_ROWS;

	cube->map->sqaureFactorX = scaleX;
	cube->map->sqaureFactorY = scaleY;
}
