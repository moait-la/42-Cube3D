#include "../include/cube.h"

void	ft_error(char *errorMsj)
{
	ft_putstr_fd(errorMsj, 2);
	// i need to free all resourses allocations fot mlx here ::TODO
	exit(1);
}
