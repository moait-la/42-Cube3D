/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:59:28 by moait-la          #+#    #+#             */
/*   Updated: 2023/11/27 15:13:41 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t buffer_size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;

	if (dst == NULL && buffer_size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	if (buffer_size <= dest_len || buffer_size == 0)
	{
		return (src_len + buffer_size);
	}
	i = 0;
	while (src[i] && (dest_len + i) < (buffer_size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (total_len);
}
