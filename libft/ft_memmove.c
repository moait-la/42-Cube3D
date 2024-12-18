/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:46 by moait-la          #+#    #+#             */
/*   Updated: 2023/11/23 13:22:42 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	d = dst + len - 1;
	s = src + len - 1;
	if (dst > src)
	{
		while (len > 0)
		{
			*d = *s;
			s--;
			len--;
			d--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
