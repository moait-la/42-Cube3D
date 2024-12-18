/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:55:49 by moait-la          #+#    #+#             */
/*   Updated: 2023/12/10 22:31:11 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

static char	*ft_skip_zero(const char *str)
{
	while (*str && *str == '0')
		str++;
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long long	total;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	total = 0;
	i = 0;
	str = ft_skip_zero(str);
	while (ft_isdigit(*str))
	{
		total = (total * 10) + *str - '0';
		str++;
		i++;
	}
	if (total > LONG_MAX || i >= 20)
		return (ft_max(sign));
	return (total * sign);
}
