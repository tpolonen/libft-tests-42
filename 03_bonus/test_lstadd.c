/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:50:02 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/30 18:50:26 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

void	test_lstadd(void)
{
	t_list	*head, *mid, *tail, *top;
	char	str1[] = "fortyone", str2[] = "fortytwo", str3[] = "fortyfoo";
	char	str4[] = "fortybar";
	size_t	size = sizeof(char) * (strlen(str1) + 1);

	printf("...lstadd\n");
	head = ft_lstnew(str1, size);
	mid = ft_lstnew(str2, size);
	tail = ft_lstnew(str3, size);
	top = ft_lstnew(str4, size);
	head->next = mid;
	mid->next = tail;
	ft_lstadd(&head, top);
	assert(head == top);
	assert(strcmp(str1, (char *) top->next->content) == 0);
	assert(top->next->next == mid);
	assert(top->next->next->next == tail);
	ft_lstdel(&top, &del_content);
}
