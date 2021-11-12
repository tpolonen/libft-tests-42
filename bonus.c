/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:56:10 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/12 13:49:58 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

static void	del_content(void *content, size_t size)
{
	bzero(content, size);
	free(content);
}

void	test_lstnew(void)
{
	t_list	*list;
	char	str[] = "fortytwo";
	size_t	size = sizeof(char) * (strlen(str) + 1);

	printf("...ft_lstnew\n");
	list = ft_lstnew(str, size);
	printf("list->content: [%s]\n", list->content);
	del_content(list->content, size);
	free(list);
}

void	test_lstdelone(void)
{
	t_list	*list;
	char	str[] = "fortytwo";
	size_t	size = sizeof(char) * (strlen(str) + 1);

	printf("...lstdelone\n");
	list = ft_lstnew(str, size);
	ft_lstdelone(&list, &del_content);
	assert(list == NULL);
}

void	test_lstdel(void)
{
	t_list	*head, *mid, *tail;
	char	str1[] = "fortyone", str2[] = "fortytwo", str3[] = "fortyfoo";
	size_t	size = sizeof(char) * (strlen(str1) + 1);

	printf("...lstdel\n");
	head = ft_lstnew(str1, size);
	mid = ft_lstnew(str2, size);
	tail = ft_lstnew(str3, size);
	head->next = mid;
	mid->next = tail;
	ft_lstdel(&mid, &del_content);
	assert(mid == NULL);
	ft_lstdelone(&head, &del_content);
}

void	test_lstadd(void)
{

}

void	test_lstiter(void)
{

}

void	test_lstmap(void)
{

}
