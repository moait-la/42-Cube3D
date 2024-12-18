/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:39:34 by moait-la          #+#    #+#             */
/*   Updated: 2023/12/04 02:16:22 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !f || ! del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
	{
		free(new_lst);
		return (NULL);
	}
	temp = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (new_lst);
}
