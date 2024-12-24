/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:16:05 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:05 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_ptr;
	t_list	*next_ptr;

	if (!lst || !*lst ||!del)
		return ;
	node_ptr = *lst;
	while (node_ptr->next)
	{
		next_ptr = node_ptr->next;
		del(node_ptr->content);
		free (node_ptr);
		node_ptr = next_ptr;
	}
	del(node_ptr->content);
	free (node_ptr);
	*lst = NULL;
}

// #include <stdio.h>

// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	// テスト用のデータ
// 	int *data1 = (int *)malloc(sizeof(int));
// 	int *data2 = (int *)malloc(sizeof(int));
// 	int *data3 = (int *)malloc(sizeof(int));
// 	*data1 = 42;
// 	*data2 = 84;
// 	*data3 = 96;

// 	// 新しいノードを作成
// 	t_list *node1 = (t_list *)malloc(sizeof(t_list));
// 	t_list *node2 = (t_list *)malloc(sizeof(t_list));
// 	t_list *node3 = (t_list *)malloc(sizeof(t_list));
// 	node1->content = data1;
// 	node1->next = node2;
// 	node2->content = data2;
// 	node2->next = node3;
// 	node3->content = data3;
// 	node3->next = NULL;

// 	// ft_lstclear関数を使用してリストを解放
// 	ft_lstclear(&node2, del_content);
// 	printf("List cleared successfully.\n");

// 	return (0);
// }
