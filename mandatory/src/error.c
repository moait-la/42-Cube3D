#include "../include/cube.h"

void	ft_error(char *errorMsj)
{
	ft_putstr_fd(errorMsj, 2);
	exit(1);
}
