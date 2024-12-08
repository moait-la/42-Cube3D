#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14

const int NUM_COLOM = 15;
const int NUM_ROWS = 16;
const int SQUARE_SIZE = 100;
const int WIDTH = NUM_COLOM * SQUARE_SIZE;
const int HEIGHT = NUM_ROWS * SQUARE_SIZE;             
const int FOV = 60; //from degrees to raidians                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
const int NUM_RAYS = WIDTH;
const float MINIMAP_SIZE = 0.1;

typedef struct s_ray
{
    float distance;
    float ray_angel;
    float xIntersaction;
    float yIntersaction;
    int wall_hit_horizontal;
    int wall_hit_vertical;
    int horizontalHitX;
    int horizontalHitY;
    int verticalHitX;
    int verticalHitY;
    int closestHit;
    int rayFacingUP;
    int rayFacingLeft;
} t_ray;

typedef struct s_data
{
    void    *mlx;
    void    *mlx_window;
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    // player data
    float x;
    float y;
    int degree;
    int length; // line length
    int move_speed;
    // click indetifiers
    int rotate_right;
    int rotate_left;
    int move_front;
    int move_back;
    //rays
    float ray_angle;
    // map gird
    int map[NUM_ROWS][NUM_COLOM];
    // rays
    t_ray ray[NUM_RAYS];
} t_data;

void    init_data(t_data *data)
{
    data->x = WIDTH/2;
    data->y = HEIGHT/2 - 15;
    data->degree = 90;
    data->length = 700;
    data->move_speed = 8;
    data->rotate_right = 1;
    data->rotate_left = 1;
    data->move_back = 1;
    data->move_front = 1;
}

int wall_check(t_data *data, int new_x, int new_y)
{
    int grid_position_x = floor(new_x / SQUARE_SIZE);
    int grid_position_y = floor(new_y / SQUARE_SIZE);

    if (data->map[grid_position_y][grid_position_x])
        return (1);
    return (0);
}

int	keys_input(int keycode, void *param)
{
    t_data *data = param;
    if (keycode == 124) // right arrow
        data->rotate_right = 0;
     if (keycode == 123) // left arrow
        data->rotate_left = 0;
     if (keycode == 126) // top arrow
        data->move_front = 0;
     if (keycode == 125) // down arrow
        data->move_back = 0;
    return 0;
}

int key_release(int keycode, void *param)
{
    t_data *data = param;
    if (keycode == 124)
         data->rotate_right = 1;
    else if (keycode == 123)
         data->rotate_left = 1;
    else if (keycode == 126)
        data->move_front = 1;
    else if (keycode == 125)
        data->move_back = 1;
    return 0;
}

float calculate_distance(float x1, float y1, float x2, float y2)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    return sqrt((delta_x * delta_x) + (delta_y * delta_y));
}

////////////////////////////////////////////////////////// render rays
//////////////////////////////////////////////////////////

float normalize(float angle)
{
    angle = fmod(angle, 2 * PI); // Use modulo for floating-point
    if (angle < 0)
        angle = angle + (2 * PI); // Ensure angle is in [0, 2PI]
    return angle;
}

int rayFacingDirection(float angle, int mybool)
{
    if (!mybool) // checking if ray facing up med codes yes he does as isaid yes he does
        if (angle >=  PI && angle < PI * 2)
            return 0;
    if (mybool == 1) // checking if ray is facing down
        if (angle < PI && angle > 0)
            return 0;
    if (mybool == 2)
        if (angle > 270 * (PI/180) || angle < 90 * (PI/180))
            return 0;
    if (mybool == 3)
        if (angle < 270 * (PI/180) && angle > 90 * (PI/180))
            return 0;
   return 1;
}

void draw_x_sign(t_data *data, int x, int y, int size, int color)
{
    for (int i = -size; i <= size; i++)
    {
        // Diagonal from top-left to bottom-right
        int x_offset = x + i;
        int y_offset = y + i;
        if (x_offset >= 0 && y_offset >= 0 && x_offset < WIDTH && y_offset < HEIGHT)
        {
            int offset = ((int)(y_offset * MINIMAP_SIZE) * data->line_length) + ((int)(x_offset * MINIMAP_SIZE) * (data->bpp / 8));
            char *dst = data->addr + offset;
            *(int *)dst = color;
        }

        // Diagonal from top-right to bottom-left
        x_offset = x + i;
        y_offset = y - i;
        if (x_offset >= 0 && y_offset >= 0 && x_offset < WIDTH && y_offset < HEIGHT)
        {
            int offset = ((int)(y_offset * MINIMAP_SIZE) * data->line_length) + ((int)(x_offset * MINIMAP_SIZE) * (data->bpp / 8));
            char *dst = data->addr + offset;
            *(int *)dst = color;
        }
    }
}



void render_ray(t_data *data, int colom) // finding v and h intersactions
{
    float angle_in_radians = data->ray_angle;

    float distanceToPoint;
    float end_x;
    float end_y;
    if (!data->ray[colom].wall_hit_horizontal && !data->ray[colom].wall_hit_vertical)
    {
        float distanceToHP = calculate_distance(
            data->x,
            data->y,
            data->ray[colom].horizontalHitX,
            data->ray[colom].horizontalHitY);
        float distanceToVp = calculate_distance(
            data->x,
            data->y,
            data->ray[colom].verticalHitX,
            data->ray[colom].verticalHitY);
        if (distanceToHP >= distanceToVp) 
        {
            end_x = data->ray[colom].verticalHitX;
            end_y = data->ray[colom].verticalHitY;
            data->ray[colom].distance = distanceToVp;
            data->ray[colom].closestHit = 2;
        }
        else //if (distanceToVp < distanceToHP) // need to give also the direction
        {
            end_x = data->ray[colom].horizontalHitX;
            end_y = data->ray[colom].horizontalHitY;
            data->ray[colom].distance = distanceToHP;
            data->ray[colom].closestHit = 1;
        }
    }
    else if (!data->ray[colom].wall_hit_horizontal)
    {
         float distanceToHP = calculate_distance(
            data->x,
            data->y,
            data->ray[colom].horizontalHitX,
            data->ray[colom].horizontalHitY);
        end_x = data->ray[colom].horizontalHitX;
        end_y = data->ray[colom].horizontalHitY;
        data->ray[colom].distance = distanceToHP;
         data->ray[colom].closestHit = 1;
    }
    else if (!data->ray[colom].wall_hit_vertical)
    {
        float distanceToVp = calculate_distance(
            data->x, 
            data->y,
            data->ray[colom].verticalHitX,
            data->ray[colom].verticalHitY);
        end_x = data->ray[colom].verticalHitX;
        end_y = data->ray[colom].verticalHitY;
        data->ray[colom].distance = distanceToVp;
         data->ray[colom].closestHit = 2;
    }
    
    float deltax = end_x - data->x;
    float deltay = end_y - data->y;

    int steps;
    if (fabsf(deltax) > fabsf(deltay))
        steps = fabsf(deltax);
    else
        steps = fabsf(deltay);
 
    float x_inc = deltax / steps;
    float y_inc = deltay / steps;

    int i = 0;
    float tmpx = data->x;
    float tmpy = data->y;

    while (i < steps)
    {
        int offset = (((int)(tmpy * MINIMAP_SIZE) * data->line_length) + ((int)(tmpx * MINIMAP_SIZE) * (data->bpp/8)));
        char *dst = data->addr + offset;
        *(int *)dst = 0x00FFFF;
        i++;
        tmpx += x_inc;
        tmpy += y_inc;
    }

    // Store the distance and type of wall hit (vertical/horizontal) in ray data
    // data->ray[colom].distance = calculate_distance(data->x, data->y, tmpx, tmpy);
}


void    VerticalInter(t_data *data, int colom)
{
    int isFacingUp    = rayFacingDirection(data->ray[colom].ray_angel, 0);
    int isFacingDown  = !isFacingUp;
    int isFacingRight = rayFacingDirection(data->ray[colom].ray_angel, 2);
    int isFacingLeft  = !isFacingRight;

    // find first horizontal intersactions
    data->ray[colom].xIntersaction = floor(data->x / SQUARE_SIZE) * SQUARE_SIZE;
    // data->ray[colom].yIntersaction = floor(data->y - ( data->y / SQUARE_SIZE ) * SQUARE_SIZE);
    if (!isFacingRight)
        data->ray[colom].xIntersaction += SQUARE_SIZE;
    data->ray[colom].yIntersaction = data->y + (data->ray[colom].xIntersaction - data->x) * tan(data->ray[colom].ray_angel);

    // find xstep ystep
    float xstep = SQUARE_SIZE;
    // // based on our direection we add or substract ystep 
    if (!isFacingLeft && xstep > 0)
        xstep *= -1;
    float ystep = SQUARE_SIZE * tan(data->ray[colom].ray_angel);
    // based on our direection we add or substract xstep also xstep can be negative 
    if (!isFacingDown && ystep < 0) // cause he can be negative
        ystep *= -1;
    else if (!isFacingUp && ystep > 0)
        ystep *= -1;

    // draw_x_sign(data, data->ray[colom].xIntersaction, data->ray[colom].yIntersaction, 5, 0xFF0000);
    // incre b ystep and ztep tanl9aw wall
    float positionX = data->ray[colom].xIntersaction;
    float positionY = data->ray[colom].yIntersaction;
    // if (!isFacingLeft)
    //     positionX--;
    while (positionX >= 0 && positionX < WIDTH && positionY >= 0 && positionY < HEIGHT)
    {
        if (!isFacingLeft)
            positionX--;
      if (wall_check(data, positionX, positionY))
       {
        if (!isFacingLeft)
            positionX--;
            data->ray[colom].wall_hit_vertical = 0;
            data->ray[colom].verticalHitX = positionX;
            data->ray[colom].verticalHitY = positionY;
            // draw_x_sign(data, positionX, positionY, 5, 0x0000FF);
            break;
       }
       if (!isFacingLeft)
            positionX++;
       positionX += xstep;
       positionY += ystep;
    }

    return ;
}

void    HorizontalInter(t_data *data, int colom)
{
    int isFacingUp    = rayFacingDirection(data->ray[colom].ray_angel, 0);
    int isFacingDown  = !isFacingUp;
    data->ray[colom].rayFacingUP = !isFacingDown;
    int isFacingRight = rayFacingDirection(data->ray[colom].ray_angel, 2);
    int isFacingLeft  = !isFacingRight;
    data->ray[colom].rayFacingLeft = !isFacingLeft;

    // find first horizontal intersactions
    data->ray[colom].yIntersaction = floor(data->y / SQUARE_SIZE) * SQUARE_SIZE;
    // data->ray[colom].yIntersaction = floor(data->y - ( data->y / SQUARE_SIZE ) * SQUARE_SIZE);
    if (!isFacingDown)
        data->ray[colom].yIntersaction += SQUARE_SIZE;
    data->ray[colom].xIntersaction = data->x + (data->ray[colom].yIntersaction - data->y) / tan(data->ray[colom].ray_angel);

    // draw_x_sign(data, data->ray[colom].xIntersaction, data->ray[colom].yIntersaction, 5, 0x000000);
    // find xstep ystep
    float ystep = SQUARE_SIZE;
    // // based on our direection we add or substract ystep
    if (!isFacingUp && ystep > 0)
        ystep *= -1; 
    float xstep = ystep / tan(data->ray[colom].ray_angel);
    // based on our direection we add or substract xstep also xstep can be negative
    
    if (!isFacingRight && xstep < 0)
        xstep *= -1;
    else if (!isFacingLeft && xstep > 0)
        xstep *= -1;

    // zid b ystep and ztep tanl9aw wall
    float positionX = data->ray[colom].xIntersaction;
    float positionY = data->ray[colom].yIntersaction;
    
    while (positionX > 0 && positionX < WIDTH && positionY > 0 && positionY < HEIGHT)
    {
        if (!isFacingUp)
            positionY--;
       if (wall_check(data, positionX, positionY))
       {
            if (!isFacingUp)
                positionY--;
            data->ray[colom].wall_hit_horizontal = 0;
            data->ray[colom].horizontalHitX = positionX;
            data->ray[colom].horizontalHitY = positionY;
            // draw_x_sign(data, positionX, positionY, 5, 0xFF0000);
            break;
       }
       if (!isFacingUp)
            positionY++;
       positionX += xstep;
       positionY += ystep;
    }
    return ;
}


void    castrays(t_data *data)
{
    float first_ray_angle_rad = (data->degree - FOV/2) * (PI / 180); // Degree - FOV/2
    // data->ray_angle = first_ray_angle_rad;
    data->ray_angle = normalize(first_ray_angle_rad);
    float angle_increment = (FOV * PI/180) / (float)WIDTH; // casted to float so the result is not 0 as FOV is small    
    for (int colom = 0; colom < NUM_RAYS; colom++)
    {
        // need to be added to init data
        data->ray[colom].wall_hit_horizontal = 1;
        data->ray[colom].wall_hit_vertical = 1;
        data->ray[colom].closestHit = 0; // 1 for Horizontal 2 for Vertical

        // render_ray(data, colom);
        data->ray[colom].ray_angel = data->ray_angle;
        VerticalInter(data, colom);
        HorizontalInter(data, colom); // started from here
        data->ray_angle += angle_increment;
        render_ray(data, colom);
    }
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void    render_map_grid(t_data data)
{
    int x = 0;
    int y = 0;
    int colom = -1;
    int row = -1;

    while (++row < NUM_ROWS)
    {
        colom = -1;
        while (++colom < NUM_COLOM)
        {
            int y = -1;
            while (++y < SQUARE_SIZE * MINIMAP_SIZE)
            {
                int x = -1;
                while (++x < SQUARE_SIZE * MINIMAP_SIZE)
                {
                    int pixel_x = (colom * SQUARE_SIZE * MINIMAP_SIZE) + x;
                    int pixel_y = (row * SQUARE_SIZE * MINIMAP_SIZE) + y;
                    // printf("%d\n", );
                    int offset = (pixel_y * data.line_length) + (pixel_x * (data.bpp/8));
                    char *dst = data.addr + offset;
                    int map_value = data.map[row][colom];
                    // if ((y > 0 && x == 0) || (x > 0 && y == 0)) // here i draw stroke |- this how its drawed 
                    //         *(int *)dst = 0x000000;
                    if (map_value == 1)
                        *(int *)dst =  0x4B4B4B;
                    else if (map_value == 0)
                        *(int *)dst =  0xFFFFFF;
                    else if (map_value == 2)
                        *(int *)dst =  0xFF0000;
                }
            }
        }
   }
}

void    render_player(t_data data)
{
   int player_size = 3;
   int k = -3 * MINIMAP_SIZE;
   while (k < player_size)
   {
    int f = -3 * MINIMAP_SIZE;
    while (f < player_size)
    {
        int offset = ((((int)(data.y * MINIMAP_SIZE) + k )* data.line_length) + ((int)(data.x * MINIMAP_SIZE) + f) * (data.bpp/8));
        char *dst = data.addr + offset;
        *(int *)dst = 0xFF0000;
        f++;
    }
    k++;
   }
}

void set_coordinates(t_data *data)
{
    if (!data->rotate_right)
        data->degree += 3; // roatation speed
    else if (!data->rotate_left)
        data->degree -= 3;
    if (!data->move_front)
    {
        float angle_in_radians = data->degree * (PI/180);
        float new_x = data->x + (cos(angle_in_radians) * data->move_speed);
        float new_y = data->y + (sin(angle_in_radians) * data->move_speed);
        if (!wall_check(data, new_x, new_y))
        {
            data->x += (cos(angle_in_radians) * data->move_speed);
            data->y += (sin(angle_in_radians) * data->move_speed);
        }
    }
    else if (!data->move_back)
    {
        float angle_in_radians = data->degree * (PI/180);
        float new_x = data->x - (cos(angle_in_radians) * data->move_speed);
        float new_y = data->y - (sin(angle_in_radians) * data->move_speed);
        if (!wall_check(data, new_x, new_y))
        {
            data->x -= (cos(angle_in_radians) * data->move_speed);
            data->y -= (sin(angle_in_radians) * data->move_speed);
        }
    }
}

void    render_3dscene(t_data data)
{
    int i = -1;
    while (++i < NUM_RAYS)
    {
        float perpDistance = data.ray[i].distance * cos(data.ray[i].ray_angel - (data.degree * (PI/180)));
        // float distanceProjPlane = (WIDTH / 2) / tan(HEIGHT / 2);
        float distanceProjPlane = (WIDTH / 2) / tan((FOV * PI / 180) / 2);
        float projectedWallHeight = (SQUARE_SIZE / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (HEIGHT / 2) - (wallStripHeight / 2);

        int wallBottomPixel = (HEIGHT / 2) + (wallStripHeight / 2);
        if (wallTopPixel < 0)
            wallTopPixel = 0;
        if (wallBottomPixel >= HEIGHT)
            wallBottomPixel = HEIGHT - 2;
        int k = wallTopPixel;
        while (k < wallBottomPixel)
        {
            int offset = (((int)k * data.line_length) + ((int)i * (data.bpp/8)));
            char *dst = data.addr + offset;
            if (data.ray[i].closestHit == 1)
                *(int *)dst = 0xFFFFFF;
            else
                *(int *)dst = 0xD3D3D3;
            k++;
        }
    }
}

void    renderSky(t_data *data)
{
    int i = -1;
    while (++i < WIDTH)
    {
        int j = -1;
        while (++j < HEIGHT / 2)
        {
            int offset = (((int)j * data->line_length) + ((int)i * (data->bpp/8)));
            char *dst = data->addr + offset;
            *(int *)dst = 0x87CEEB;
        }
    }
    
}

void    renderGround(t_data *data)
{
    int i = -1;
    while (++i < WIDTH)
    {
        int j = HEIGHT / 2;
        while (++j < HEIGHT )
        {
            int offset = (((int)j * data->line_length) + ((int)i * (data->bpp/8)));
            char *dst = data->addr + offset;
            *(int *)dst = 0x8D2B48C;
        }
    }
}

void clear_buffer(t_data *data, int color)
{
    int *buffer = (int *)data->addr;
    for (int i = 0; i < (WIDTH * HEIGHT); i++)
        buffer[i] = color;
}

int render(void *param)
{
    t_data *data = param;

    clear_buffer(data, 0x000000);
    renderSky(data);
    renderGround(data);
    set_coordinates(data); // Update position/rotation based on key presses
    // render_line(*data);
    render_3dscene(*data);
    render_map_grid(*data);
    render_player(*data);
    castrays(data);
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->mlx_img, 0, 0);

    return 0; // Return 0 so the loop continues
}

int mouse_move_handler(int x, int y, void *param)
{
    (void)param; // Unused parameter
    printf("Mouse moved to: X = %d, Y = %d\n", x, y);
    return (0);
}

int main()
{
    t_data data;

   
    int map[NUM_ROWS][NUM_COLOM] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int i = -1;
    while (++i < NUM_ROWS)
    {
       int j = -1;
       while (++j < NUM_COLOM)
        data.map[i][j] = map[i][j];
    }
    
    data.mlx = mlx_init();
    data.mlx_window = mlx_new_window(data.mlx, WIDTH, HEIGHT,"window");
    data.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr =  mlx_get_data_addr(data.mlx_img, &data.bpp, &data.line_length, &data.endian);

    init_data(&data);
    // render_map_grid(data);
    // castrays(&data);
    // render_player(data);
    // render_3dscene(data);
    render(&data);

    // mlx_hook(data.mlx_window, 6, 0, mouse_move_handler, NULL);


    mlx_hook(data.mlx_window, 2, 0, keys_input, &data);
    mlx_hook(data.mlx_window, 3, 0, key_release, &data);
    mlx_loop_hook(data.mlx, render, &data);
    mlx_loop(data.mlx);
    return (0);
}


/*
1. check for H intersactions
2. check for V intersactions
3. compare the distances and choose the closest one 

1. find first point intersaction 

*/