/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:56:10 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/23 18:44:11 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

static void	del_content(void *content, size_t size)
{
	if (content != NULL)
	{
		printf("deleting list content [%s]\n", (char *) content);
		bzero(content, size);
		free(content);
	}
	else printf("deleting list with no content\n");
}

void	test_lstnew(void)
{
	t_list	*list;
	char	str[] = "fortytwo";
	size_t	size = sizeof(char) * (strlen(str) + 1);

	printf("...ft_lstnew\n");
	list = ft_lstnew(str, size);
	printf("list->content: [%s]\n", list->content);
	assert(list->content_size == size);
	del_content(list->content, size);
	free(list);
	list = ft_lstnew(NULL, 42);
	assert(list->content_size == 0);
	del_content(list->content, 42);
	free(list);
}

void	test_lstdelone(void)
{
	t_list	*head, *tail;
	char	str1[] = "fortyone", str2[] = "fortytwo";
	size_t	size = sizeof(char) * (strlen(str1) + 1);

	printf("...lstdelone\n");
	head = ft_lstnew(str1, size);
	tail = ft_lstnew(str2, size);
	ft_lstdelone(&head, &del_content);
	assert(head == NULL);
	assert(strcmp((char *) tail->content, "fortytwo") == 0);
	ft_lstdelone(&tail, &del_content);
}

void	test_lstdel(void)
{
	t_list	*head, *mid, *tail;
	char	str1[] = "fortyone", str2[] = "fortytwo", str3[] = "fortyfoo";
	void	*tailcheck;
	size_t	size = sizeof(char) * (strlen(str1) + 1);

	printf("...ft_lstdel\n");
	head = ft_lstnew(str1, size);
	mid = ft_lstnew(str2, size);
	tail = ft_lstnew(str3, size);
	head->next = mid;
	mid->next = tail;
	tailcheck = tail->content;
	printf("tail->content before lstdel:\t[");
	print_mem(tailcheck, size);
	printf("]\n");
	ft_lstdel(&mid, &del_content);
	assert(mid == NULL);
	printf("tail->content after lstdel:\t[");
	print_mem(tailcheck, size);
	printf("]\n");
	ft_lstdelone(&head, &del_content);
}

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

static void	print_content_assert_uppercase(t_list *elem)
{
	if (elem->content != NULL)
	{
		printf("[%s]\n", (char*)elem->content);
		assert(*(char *)elem->content == 'F');
	}
}

static t_list	*uppercase_content(t_list *elem)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);

	new->next = NULL;
	new->content_size = elem->content_size;

	if (elem->content != NULL)
	{
		char	*new_content, *nc;
		char	*oc = (char *) elem->content;
		
		new_content = (char *) malloc(elem->content_size);
		bzero(new_content, elem->content_size);
		if (!new_content)
		{
			free(new);
			return (NULL);
		}
		nc = new_content;
		while (*oc)
		{
			*nc = (char) toupper(*oc);
			nc++;
			oc++;
		}
		new->content = new_content;
		return (new);
	}
	else return (NULL);
}

void	test_lstmap(void)
{
	t_list	*head, *mid, *tail, *copy;
	char	str1[] = "fortyone", str2[] = "fortytwo", str3[] = "fortyfoo";
	size_t	size = sizeof(char) * (strlen(str1) + 1);

	printf("...ft_lstmap\n");
	head = ft_lstnew(str1, size);
	mid = ft_lstnew(str2, size);
	tail = ft_lstnew(str3, size);
	head->next = mid;
	mid->next = tail;
	copy = ft_lstmap(head, &uppercase_content);
	ft_lstiter(copy, &print_content_assert_uppercase);
	ft_lstdel(&head, &del_content);
	ft_lstdel(&copy, &del_content);
}
