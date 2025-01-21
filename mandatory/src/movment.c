#include "../include/cube.h"

int	wallCheck(t_cube *cube, int	newX, int newY)
{
	int	gridPositionX;
	int	gridPositionY;

	if (newX <= 0 || newX <= 0)
		return (1);
	gridPositionX = floor(newX/cube->map->sqaureFactorX);
	gridPositionY = floor(newY/cube->map->sqaureFactorY);
	if (cube->map->map[gridPositionY][gridPositionX])
		return (0);
	return (1);
}

void	moveForward(t_cube *cube)
{
	float	degreeRad;
	float	newX;
	float	newY;

	degreeRad = cube->player->degree * (PI/180);
	newX = cube->player->x + (cos(degreeRad) * cube->player->speed);
	newY = cube->player->y + (sin(degreeRad) * cube->player->speed);
	if (!wallCheck(cube, newX, newY))
		return ;
	cube->player->x = newX;
	cube->player->y = newY;
}

void	moveBack(t_cube *cube)
{
	float	degreeRad;
	float	newX;
	float	newY;

	degreeRad = cube->player->degree * (PI/180);
	newX = cube->player->x - (cos(degreeRad) * cube->player->speed);
	newY = cube->player->y - (sin(degreeRad) * cube->player->speed);
	if (!wallCheck(cube, newX, newY))
		return ;
	cube->player->x = newX;
	cube->player->y = newY;
}

void	updatePosition(t_cube *cube)
{
	float	rotationSpeed;

	rotationSpeed = 1;
	if (cube->player->moveForward == true)
		moveForward(cube);
	else if (cube->player->moveBack == true)
		moveBack(cube);
	if (cube->player->rotateRight == true)
		cube->player->degree += rotationSpeed;
	else if (cube->player->rotateLeft == true)
		cube->player->degree -= rotationSpeed;
}
