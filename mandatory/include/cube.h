#ifndef CUBE_H
# define CUBE_H

#include "macros.h"
#include "struct.h"
#include "/Users/moait-la/my_libraries/MLX42/include/MLX42.h"
#include "../../libft/libft.h"
#include <math.h>
#include <sys/time.h>
<<<<<<< HEAD
=======
#include <stdio.h>
<<<<<<< HEAD
#include <stdbool.h>

=======
>>>>>>> 754f8609c00c0dfb252eb74cde0b4691fef0eba0
>>>>>>> 3d8cf8c3502ca5ae9460cb7c62c8c50214a58201

void	ft_error(char *errorMsj);
void	*ft_malloc(unsigned long size);
void	myPixelPut(t_cube *cube, int x, int y, int color);

void	getSquareFactor(t_cube *cube);
void	initStartingValues(t_cube *cube);
void	allocations(t_cube *cube);

void	castRay(t_cube *cube);
void	castAllRays(t_cube *cube);

void	getMap(t_cube *cube);
void	renderMapGrid(t_cube *cube);
void	renderPlayer(t_cube *cube);
<<<<<<< HEAD
void	castRay(t_cube *cube);
long    getTime();

void	keyPress(mlx_key_data_t keydata, void *param);

=======

int     wallCheck(t_cube *cube, int	newX, int newY);
>>>>>>> 754f8609c00c0dfb252eb74cde0b4691fef0eba0
void	moveForward(t_cube *cube);
void	moveBack(t_cube *cube);
void	updatePosition(t_cube *cube);

<<<<<<< HEAD
=======
void	keyPress(mlx_key_data_t keydata, void *param);
>>>>>>> 754f8609c00c0dfb252eb74cde0b4691fef0eba0

#endif