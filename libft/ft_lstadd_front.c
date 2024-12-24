/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:45:29 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/21 15:29:02 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	// テスト用のデータ
// 	int data1 = 42;
// 	int data2 = 84;

// 	// 新しいノードを作成
// 	t_list *node1 = (t_list *)malloc(sizeof(t_list));
// 	t_list *node2 = (t_list *)malloc(sizeof(t_list));

// 	// ノードにデータを設定
// 	node1->content = &data1;
// 	node1->next = NULL;
// 	node2->content = &data2;
// 	node2->next = NULL;

// 	// リストの先頭にノードを追加
// 	t_list *list = NULL; // リストの先頭ポインタ
// 	ft_lstadd_front(&list, node1);
// 	ft_lstadd_front(&list, node2);

// 	// リストを走査して内容を表示
// 	t_list *current = list;
// 	int	index = 0;
// 	while (current != NULL)
// 	{
// 		printf("Content%d: %d\n", index, *((int *)(current->content)));
// 		current = current->next;
// 		index++;
// 	}

// 	// メモリリークを防ぐためにノードを解放
// 	free(node1);
// 	free(node2);

// 	return (0);
// }