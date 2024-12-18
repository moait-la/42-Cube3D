/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:05:46 by moait-la          #+#    #+#             */
/*   Updated: 2023/11/30 16:31:52 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size != 0 && count > SIZE_T_MAX / size)
		return (NULL);
	res = (void *)malloc(count * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
