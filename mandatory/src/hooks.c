#include "../include/cube.h"

void	keyPress(mlx_key_data_t keydata, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->movment->moveForward = true;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->movment->moveBack = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->movment->rotateRight = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->movment->rotateLeft = true;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->moveForward = false;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->moveBack = false;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->rotateRight = false;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->movment->rotateLeft = false;
}


