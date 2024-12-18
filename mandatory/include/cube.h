#ifndef CUBE_H
#define CUBE_H

#include "macros.h"
#include "struct.h"
#include "/Users/moait-la/Desktop/MLX42/include/MLX42/MLX42.h"
#include "../../libft/libft.h"
#include <stdbool.h>
#include <math.h>

void	renderMapGrid(t_cube *cube);
void	ft_error(char *errorMsj);
void	getSquareFactor(t_cube *cube);
void	initStartingValues(t_cube *cube);
void	*ft_malloc(unsigned long size);
void	allocations(t_cube *cube);
void	getMap(t_cube *cube);
void	renderPlayer(t_cube *cube);
void	castRay(t_cube *cube);

#endif