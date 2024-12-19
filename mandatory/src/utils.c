#include "../include/cube.h"

void	initStartingValues(t_cube *cube)
{
	cube->player->position->x = WIDTH/2;
	cube->player->position->y = HEIGHT/2;
	cube->player->degree = 0;
	cube->player->speed = 5;
}

void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		ft_error("Error Malloc failed\n");
	return (ptr);
}

void	allocations(t_cube *cube)
{
	cube->map = (t_map *)ft_malloc(sizeof(t_map));
	cube->player = (t_player *)ft_malloc(sizeof(t_player));
	cube->player->position = (t_point *)ft_malloc(sizeof(t_point));
}
