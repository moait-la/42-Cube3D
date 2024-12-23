#include "../include/cube.h"

int	wallCheck(t_cube *cube, int	newX, int newY)
{
	int	gridPositionX;
	int	gridPositionY;

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
	newX = cube->player->position->x + (cos(degreeRad) * cube->player->speed);
	newY = cube->player->position->y + (sin(degreeRad) * cube->player->speed);
	if (!wallCheck(cube, newX, newY))
		return ;
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
	if (!wallCheck(cube, newX, newY))
		return ;
	cube->player->position->x = newX;
	cube->player->position->y = newY;
}

void	updatePosition(t_cube *cube)
{
	// if (getTime() - cube->lastFameUpdate < 16.67 && cube->lastFameUpdate != 0)
	// 	return ;
<<<<<<< HEAD
	if (cube->player->movment->moveFront == true)
=======
	if (cube->player->movment->moveForward == true)
>>>>>>> 754f8609c00c0dfb252eb74cde0b4691fef0eba0
		moveForward(cube);
	else if (cube->player->movment->moveBack == true)
		moveBack(cube);
	if (cube->player->movment->rotateRight == true)
		cube->player->degree += 5;
	else if (cube->player->movment->rotateLeft == true)
		cube->player->degree -= 5;
	// cube->lastFameUpdate = getTime();
}
