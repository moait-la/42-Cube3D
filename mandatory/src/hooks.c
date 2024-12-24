#include "../include/cube.h"

void	keyPress(mlx_key_data_t keydata, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->moveForward = true;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->moveBack = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->rotateRight = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->rotateLeft = true;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->moveForward = false;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->moveBack = false;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->rotateRight = false;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->rotateLeft = false;
}


