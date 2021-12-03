/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:51:40 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/30 18:52:09 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

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
