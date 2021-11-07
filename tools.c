/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:39:40 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/07 19:15:17 by tpolonen         ###   ########.fr       */
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
	size_t	i = 0;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
		str[i++] = rand_char();
	str[i] = '\0';
	return (str);
}

int		rand_substrs(char **s1, char **s2, size_t len_pre, size_t len_post)
{
	char*	prefix;
	char*	postfix1;
	char*	postfix2;

	*s1 = (char *)malloc(sizeof(char) * (len_pre + len_post + 1));
	*s2 = (char *)malloc(sizeof(char) * (len_pre + len_post + 1));
	if (*s1 == NULL || *s2 == NULL)
		return (0);
	prefix = rand_str(len_pre);
	if (!prefix)
		return (0);
	*s1 = strncat(*s1, prefix, len_pre);
	*s2 = strncat(*s2, prefix, len_pre);
	postfix1 = rand_str(len_post);
	postfix2 = rand_str(len_post);
	if (!postfix1 || !postfix2)
		return (0);
	*s1 = strncat(*s1, postfix1, len_post);
	*s2 = strncat(*s2, postfix2, len_post);
	free(prefix);
	free(postfix1);
	free(postfix2);
	return (1);
}
