#ifndef STRUCT_H
#define STRUCT_H

#include "./cube.h"
#include "../../MLX42/include/MLX42/MLX42.h"
// #include "/Users/zqouri/Desktop/42-Cube3D/MLX42/include/MLX42/MLX42.h"
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

typedef struct s_player
{
    float       degree;
    float       x;
    float       y;
    int         speed;

    bool	moveForward;
    bool	moveBack;
    bool	rotateRight;
    bool	rotateLeft;
} 	t_player;

typedef enum s_hit
{
    VERTICAL,
    HORIZONTAL,
    UNKNOWN
}   t_hit;

typedef struct s_ray
{
    float   distance;
    float   rayAngle;
    float   xInter; // Intersaction
    float   yInter;
    bool	hitHori;
    bool	hitVert;

    bool	facingUp;
    bool	facingDown;
    bool	facingRight;
    bool	facingLeft;
    t_hit   closestHit;
    t_point	*horizHitP;
    t_point	*vertiHitP;
}   t_ray;

typedef struct s_cube
{
    mlx_t       *window;
    mlx_image_t *img;
    t_map       *map;
	t_texture   *texture;
    t_player    *player;
    t_ray       *ray;
    long        lastFameUpdate;
}	t_cube;

//MAPS
typedef struct s_maap
{
	int		fd;
	int		h_map;
	int		w_map;
	char	*name_map;
	char	*line;
	char	**map;

}	t_maap;

#endif