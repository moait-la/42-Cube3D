#ifndef STRUCT_H
#define STRUCT_H

#include "./cube.h"
#include "macros.h"
#include "struct.h"
#include "/Users/moait-la/Desktop/MLX42/include/MLX42/MLX42.h"
#include "../../libft/libft.h"
#include <stdbool.h>

typedef struct s_texture
{
    mlx_texture_t	*no;
    mlx_texture_t	*ea;
    mlx_texture_t	*we;
    mlx_texture_t	*so;
}	t_texture;

typedef struct s_map
{
	int	map[NUM_ROWS][NUM_COLOM];
    int sqaureFactorX;
    int sqaureFactorY;
}	t_map;

typedef struct s_point
{
    float	x;
    float	y;
}	t_point;

typedef struct s_movment
{
    bool	moveFront;
    bool	moveBack;
    bool	moveRight;
    bool	moveLeft;
    bool	rotateRight;
    bool	rotateLeft;
} t_movment;

typedef struct s_player
{
    float       degree;
    int         speed;
    t_point     *position;
    t_movment   *movment;
} 	t_player;


typedef struct s_direction
{
    bool	facingUp;
    bool	facingDown;
    bool	facingRight;
    bool	facingLeft;
}	t_direction;

typedef struct s_ray
{
    float   distance;
    float   ray_angle;
    float   xInter; // Intersaction
    float   yInter;
    bool	hitHoriz;
    bool	hitVerti;
    t_point	*horizHit;
    t_point	*vertiHit;
}   t_ray;

typedef struct s_cube
{
    mlx_t       *window;
    mlx_image_t *img;
    t_map       *map;
	t_texture   *texture;
    t_player    *player;
    long        lastFameUpdate;
}	t_cube;

#endif