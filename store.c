// void render_ray(t_data *data, int colom)
// {
//     // float angle_in_radians = data.degree * (PI/180);
//     float angle_in_radians = data->ray_angle;

//     float end_x = data->x + (cos(angle_in_radians) * data->length);
//     float end_y = data->y + (sin(angle_in_radians) * data->length);

//     float deltax = end_x - data->x;
//     float deltay = end_y - data->y;

//     int steps;
//     if (fabsf(deltax) > fabsf(deltay))
//         steps = fabsf(deltax);
//     else
//         steps = fabsf(deltay);
    
//     float x_inc = deltax/steps;
//     float y_inc = deltay/steps;

//     int i = 0;
//     float tmpx = data->x;
//     float tmpy = data->y;
//     while (i <= steps)
//     {
//         if (wall_check(data, tmpx, tmpy))
//         {
//             tmpx -= 1;
//             tmpy -= 1;
//             break ;
//         }
//         int offset = (((int)(tmpy * MINIMAP_SIZE) * data->line_length) + ((int)(tmpx * MINIMAP_SIZE) * (data->bpp/8)));
//         char *dst = data->addr + offset;
//         *(int *)dst = 0x00FFFF;
//         i++;
//         tmpx += x_inc;
//         tmpy += y_inc;
//     }
//     data->ray[colom].distance = calculate_distance(data->x, data->y, tmpx, tmpy);
//     data->ray[colom].ray_angel = data->ray_angle;
// }