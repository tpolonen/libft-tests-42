/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:50:46 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/30 18:51:25 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	print_content_assert_lowercase(t_list *elem)
{
	if (elem->content != NULL)
	{
		printf("[%s]\n", (char*)elem->content);
		assert(*(char *)elem->content == 'f');
	}
}

void	test_lstiter(void)
{
	t_list	*head, *mid, *tail;
	char	str1[] = "fortyone", str2[] = "fortytwo", str3[] = "fortyfoo";
	size_t	size = sizeof(char) * (strlen(str1) + 1);

	printf("...ft_lstiter\n");
	head = ft_lstnew(str1, size);
	mid = ft_lstnew(str2, size);
	tail = ft_lstnew(str3, size);
	head->next = mid;
	mid->next = tail;
	ft_lstiter(head, &print_content_assert_lowercase);
	ft_lstdel(&head, &del_content);
}
