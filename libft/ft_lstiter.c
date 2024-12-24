/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:57:35 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/21 19:27:48 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node_ptr;

	node_ptr = lst;
	if (!lst || !f)
		return ;
	while (node_ptr->next)
	{
		f(node_ptr->content);
		node_ptr = node_ptr->next;
	}
	f(node_ptr->content);
}
