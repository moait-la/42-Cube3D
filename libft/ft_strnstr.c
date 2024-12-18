/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:31:51 by moait-la          #+#    #+#             */
/*   Updated: 2023/11/26 22:01:09 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	ned_len;

	if (!haystack && needle && len == 0)
		return (NULL);
	ned_len = ft_strlen(needle);
	if (ned_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (needle[k] && haystack[i + k]
			&& needle[k] == haystack[k + i] && (k + i) < len)
		{
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
