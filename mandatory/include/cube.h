#ifndef CUBE_H
# define CUBE_H

# include "macros.h"
# include "struct.h"
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../libft/libft.h"
# include <math.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

//PARS
t_maap	*init_map(char *argv);
void	check_file(t_maap *data);
void	pars(t_maap *map);
void	ft_free(char **tab);
//RAYS
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

int     wallCheck(t_cube *cube, int	newX, int newY);
void	moveForward(t_cube *cube);
void	moveBack(t_cube *cube);
void	updatePosition(t_cube *cube);

void	keyPress(mlx_key_data_t keydata, void *param);

#endif