/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:46:47 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/30 18:49:49 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

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
