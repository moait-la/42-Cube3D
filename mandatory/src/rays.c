#include "../include/cube.h"

float normalize(float angle)
{
    angle = fmod(angle, 2 * PI); // Use modulo for floating-point
    if (angle < 0)
        angle = angle + (2 * PI); // Ensure angle is in [0, 2PI]
    return angle;
}

bool	getRayDirection(float angle, int flag)
{
	if (!flag)
	{
		if (angle >= PI && angle < PI * 2)
			return (true);
	}
	else if (flag)
		if (angle > 270*(PI/180) || angle < 90*(PI/180))
			return (true);
	return false;
}

void	castRay(t_cube *cube)
{
	int endX = cube->player->x + 50 * cos(cube->player->degree * (PI/180));
	int endY = cube->player->y + 50 * sin(cube->player->degree * (PI/180));

	float deltaX = endX - cube->player->x;
	float deltaY = endY - cube->player->y;

	int steps;
	if (fabsf(deltaX) > fabsf(deltaY))
		steps = fabsf(deltaX);
	else
		steps = fabsf(deltaY);

	float xInc = deltaX / steps;
	float yInc = deltaY / steps;

	float tmpx = cube->player->x;
	float tmpy = cube->player->y;
	int i = -1;
	while (++i < steps)
	{
		myPixelPut(cube, tmpx, tmpy, 0xFF0000);
		tmpx += xInc;
		tmpy += yInc;
	}
}


void	castAllRays(t_cube *cube)
{
	float	firstRayAngle;
	float	angleInc;
	int		colom;

	firstRayAngle = (cube->player->degree - FOV/2) * (PI / 180);
	firstRayAngle = normalize(firstRayAngle);
	angleInc = (FOV * PI/180) / (float)WIDTH;
	colom = -1;
	while (++colom < 1)
	{
		cube->ray[colom].hitHori = false;
		cube->ray[colom].hitVert = false;
		cube->ray[colom].closestHit = UNKNOWN;
		cube->ray[colom].rayAngle = firstRayAngle;
		cube->ray[colom].horizHitP = (t_point *)ft_malloc(sizeof(t_point));
		cube->ray[colom].vertiHitP = (t_point *)ft_malloc(sizeof(t_point));
		// getHorizInter(cube, colom);
		// renderRay();
		firstRayAngle += angleInc;
	}
}
