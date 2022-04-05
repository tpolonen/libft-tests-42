/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:46:18 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/30 18:46:34 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

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
