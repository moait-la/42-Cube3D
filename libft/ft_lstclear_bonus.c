/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:48:26 by moait-la          #+#    #+#             */
/*   Updated: 2023/11/29 18:50:37 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*store;

	if (!del || !lst || !*lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		store = temp->next;
		del(temp->content);
		free(temp);
		temp = store;
	}
	*lst = NULL;
}
