/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:47:21 by zqouri            #+#    #+#             */
/*   Updated: 2024/12/29 04:06:44 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	check_extention(t_map *data)
{
	int	i;

	i = 0;
	while (data->name_map[i])
		i++;
	i = i - 4;
	if (ft_strncmp(&(data->name_map[i]), ".cub", ft_strlen(".cub")) != 0)
		clear_map("ERROR: Invalid extention\n", data);
}

void	check_file(t_map *data)
{
	data->fd = open(data->name_map, O_RDWR, 0666);
	if (data->fd == -1)
		clear_map("ERROR: NO such Directory or file\n", data);
	check_extention(data);
}
