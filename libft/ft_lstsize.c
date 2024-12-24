/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:49:41 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:56:22 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node_ptr;
	int		count;

	if (!lst)
		return (0);
	node_ptr = lst;
	count = 1;
	while (node_ptr->next)
	{
		count++;
		node_ptr = node_ptr->next;
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// テスト用のデータ
// 	int data1 = 42;
// 	int data2 = 84;
// 	int data3 = 96;
// 	// 新しいノードを作成
// 	t_list *node1 = (t_list *)malloc(sizeof(t_list));
// 	t_list *node2 = (t_list *)malloc(sizeof(t_list));
// 	t_list *node3 = (t_list *)malloc(sizeof(t_list));
// 	// ノードにデータを設定
// 	node1->content = &data1;
// 	node1->next = NULL;
// 	node2->content = &data2;
// 	node2->next = NULL;
// 	node3->content = &data3;
// 	node3->next = NULL;
// 	// リストの先頭にノードを追加
// 	t_list *list = NULL; // リストの先頭ポインタ
// 	ft_lstadd_front(&list, node1);
// 	ft_lstadd_front(&list, node2);
// 	ft_lstadd_front(&list, node3);
// 	// リストを走査して内容を表示
// 	t_list *current = list;
// 	while (current != NULL)
// 	{
// 		printf("Content: %d\n", *((int *)(current->content)));
// 		current = current->next;
// 	}
// 	printf("size:%d\n", ft_lstsize(node3));
// 	// メモリリークを防ぐためにノードを解放
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }
