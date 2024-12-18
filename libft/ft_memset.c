/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:18:14 by moait-la          #+#    #+#             */
/*   Updated: 2023/12/10 22:21:57 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*my_b;
	size_t			i;

	my_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		my_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
