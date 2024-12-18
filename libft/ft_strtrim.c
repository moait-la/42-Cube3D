/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:04:40 by moait-la          #+#    #+#             */
/*   Updated: 2023/11/20 04:47:03 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0')
	{
		if (char_check(*s1, set))
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (char_check(s1[size - 1], set))
			size--;
		else
			break ;
	}
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, size + 1);
	return (res);
}
