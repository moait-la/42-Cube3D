/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 04:07:39 by zqouri            #+#    #+#             */
/*   Updated: 2025/01/18 05:58:37 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

t_maap	*init_map(char *argv)
{
	t_maap	*data;

	data = (t_maap *)malloc(sizeof(t_maap));
	if (!data)
	{
		ft_putstr_fd("ERROR malloc\n", 2);
		exit(1);
	}
	data->name_map = ft_strdup(argv);
	data->line = NULL;
	data->map = NULL;
	return (data);
}

void	pars(t_maap *map)
{
	check_file(map);
}
