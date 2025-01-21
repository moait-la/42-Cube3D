#include "../include/cube.h"

void	getHorizInter(t_cube *cube, int colom)
{
	cube->ray[colom].yInter = floor(cube->player->y / cube->map->sqaureFactorY) * cube->map->sqaureFactorY;
	if (cube->ray[colom].facingDown == true)
		cube->ray[colom].yInter += cube->map->sqaureFactorY;
	cube->ray[colom].xInter = cube->player->x + (cube->ray[colom].yInter - cube->player->y) / (tan(cube->ray[colom].rayAngle));

	float	xstep, ystep;
	ystep = cube->map->sqaureFactorY;
	if (cube->ray[colom].facingUp == true && ystep > 0)
		ystep *= -1;
	xstep = ystep / (tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingLeft && xstep > 0)
		xstep *= -1;
	else if (cube->ray[colom].facingRight && xstep < 0)
		xstep *= -1;

	float	posX, posY;
	posX = cube->ray[colom].xInter;
	posY = cube->ray[colom].yInter;
	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
	{
		// -1 for up 1 for down
		if (!wallCheck(cube, posX, posY + getPixel(cube, colom, true)))
			break ;
		posX += xstep;
		posY += ystep;
	}
	// draw_x_sign(cube, posX, posY, 10, 0x0000FF);
	cube->ray[colom].horizHitP->x = posX;
	cube->ray[colom].horizHitP->y = posY;
}

void getVertInter(t_cube *cube, int colom)
{
	cube->ray[colom].xInter = floor(cube->player->x / cube->map->sqaureFactorX) * cube->map->sqaureFactorX;
	if (cube->ray[colom].facingRight == true)
		cube->ray[colom].xInter += cube->map->sqaureFactorX;
	cube->ray[colom].yInter = cube->player->y + (cube->ray[colom].xInter - cube->player->x) * (tan(cube->ray[colom].rayAngle));

	float xstep, ystep;
	xstep = cube->map->sqaureFactorX;
	if (cube->ray[colom].facingLeft == true && xstep > 0)
		xstep *= -1;
	ystep = xstep * (tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingUp && ystep > 0)
		ystep *= -1;
	else if (cube->ray[colom].facingDown && ystep < 0)
		ystep *= -1;

	float posX, posY;
	posX = cube->ray[colom].xInter;
	posY = cube->ray[colom].yInter;
	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
	{
		if (!wallCheck(cube, posX + getPixel(cube, colom, false), posY))
			break ;
		posX += xstep;
		posY += ystep;
	}
	cube->ray[colom].vertiHitP->x = posX;
	cube->ray[colom].vertiHitP->y = posY;
}

void	renderWall(t_cube *cube, int c)
{
	double	disprolane;
	double	wallHeight;
	int		topPixel;
	int		botPixel;

	cube->ray[c].distance *= cos(cube->ray[c].rayAngle - (cube->player->degree * (M_PI/180)));
	disprolane = (cube->window->height / 2) / tan((FOV * (PI/180)) / 2);
	wallHeight = (cube->map->sqaureFactorX/cube->ray[c].distance) * disprolane;
	topPixel = (cube->window->height/2) - (wallHeight/2);
	botPixel = (cube->window->height/2) + (wallHeight/2);
	if (topPixel < 0)
		topPixel = 0;
	if (botPixel >= cube->window->height)
		botPixel = cube->window->height;
	renderCeiling(cube, c, topPixel);
	renderStripe(cube, topPixel, botPixel, c);
	renderFloor(cube, c, botPixel);
}

void	castAllRays(t_cube *cube)
{
	float	firstRayAngle;
	float	angleInc;
	int		colom;

	firstRayAngle = (cube->player->degree - FOV/2) * (PI / 180);
	firstRayAngle = normalize(firstRayAngle);
	angleInc = (FOV * PI/180) / (float)cube->window->width;
	colom = -1;
	while (++colom < WIDTH)
	{
		initRayData(cube, firstRayAngle, colom);
		setRayDirection(cube, colom);
		getHorizInter(cube, colom);
		getVertInter(cube, colom);
		getClosestHit(cube, colom);
		renderWall(cube, colom);
		firstRayAngle += angleInc;
		ft_free(cube->ray[colom].horizHitP, cube->ray[colom].vertiHitP);
	}
}
