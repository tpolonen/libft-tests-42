/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:39:40 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/05 14:47:56 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	rand_char(void)
{
	char c = (char) (arc4random() % 256);
	while (!isprint(c))
		c = (char) (arc4random() % 256);
	return (c);
}

char	*rand_str(size_t len)
{
	char*	str;

	str = (char *) malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
		str[--len] = rand_char();
	return (str);
}

void	rand_substrs(char **s1, char **s2, size_t len_pre, size_t len_post)
{
	*s1 = (char *) malloc(sizeof(char) * (len_pre + len_post + 1));
	*s2 = (char *) malloc(sizeof(char) * (len_pre + len_post + 1));
	*s1 = rand_str(len_pre);
	*s2 = strndup(*s1, len_pre);
	*s1 = strncat(*s1, rand_str(len_post), len_post);
	*s2 = strncat(*s2, rand_str(len_post), len_post);
}
