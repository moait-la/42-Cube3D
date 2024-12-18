/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:01:54 by moait-la          #+#    #+#             */
/*   Updated: 2023/12/10 22:37:38 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	put_in_str(unsigned long n, int len, char *res)
{
	while (n != 0)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;

	nb = n;
	len = ft_len(nb);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	res[len] = '\0';
	len--;
	put_in_str(nb, len, res);
	return (res);
}
