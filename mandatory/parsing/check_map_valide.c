/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valide.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 04:07:50 by zqouri            #+#    #+#             */
/*   Updated: 2025/01/18 08:16:23 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void    get_map(t_maap *data)
{
    char    *line;
    int     i;
    int     j;

    i = 0;
    while (get_next_line(data->fd, &line) > 0)
    {
        j = 0;
        while (line[j])
        {
            if (line[j] == '1')
                data->map[i][j] = 1;
            else if (line[j] == ' ')
                data->map[i][j] = 0;
            else
                data->map[i][j] = 2;
            j++;
        }
        i++;
        free(line);
    }
    j = 0;
    while (line[j])
    {
        if (line[j] == '1')
            data->map[i][j] = 1;
        else if (line[j] == ' ')
            data->map[i][j] = 0;
        else
            data->map[i][j] = 2;
        j++;
    }
    free(line);
}
