/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:25:28 by moait-la          #+#    #+#             */
/*   Updated: 2023/12/04 02:05:15 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	if (n == 0)
		return (0);
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && (*s_1 == *s_2))
	{
		s_1++;
		s_2++;
		i++;
	}
	return ((int)(*s_1 - *s_2));
}
