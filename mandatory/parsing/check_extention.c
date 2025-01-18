/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:47:21 by zqouri            #+#    #+#             */
/*   Updated: 2025/01/18 05:54:06 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	clear_map(char *error, t_maap *data)
{
	if (error)
		ft_putstr_fd(error, 2);
	if (data)
	{
		if (data->line)
			free(data->line);
		if (data->map)
			ft_free(data->map);
	}
	exit(1);
}

void	check_extention(t_maap *data)
{
	int	i;

	i = 0;
	while (data->name_map[i])
		i++;
	i = i - 4;
	if (ft_strncmp(&(data->name_map[i]), ".cub", ft_strlen(".cub")) != 0)
		clear_map("ERROR: Invalid extention\n", data);
}

void	check_file(t_maap *data)
{
	data->fd = open(data->name_map, O_RDWR, 0666);
	if (data->fd == -1)
		clear_map("ERROR: NO such Directory or file\n", data);
	check_extention(data);
}
