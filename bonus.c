/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:56:10 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/12 11:33:06 by tpolonen         ###   ########.fr       */
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

}

void	test_lstdel(void)
{

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
