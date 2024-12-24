/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:13:07 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:55:18 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// テスト用のデータ
// 	int data = 42;
// 	// ft_lstnewを使って新しいノードを作成
// 	t_list *node = ft_lstnew(&data);
// 	// ノードが正しく作成されたかどうかを確認
// 	if (node)
// 	{
// 		printf("New node created successfully.\n");
// 		printf("Content of the node: %d\n", *((int *)(node->content)));
// 		printf("Next pointer: %p\n", (void *)(node->next));
// 		// メモリリークを防ぐためにノードを解放
// 		free(node);
// 	}
// 	else
// 	{
// 		printf("Failed to create new node.\n");
// 	}
// 	return (0);
// }
