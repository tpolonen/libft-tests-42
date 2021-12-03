/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:45:01 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/30 18:46:14 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

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
