/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:39:40 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/08 15:58:29 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	rand_char(void)
{
	char c = (char) (arc4random_uniform(128));
	while (!isalnum(c))
		c = (char) (arc4random_uniform(128));
	return (c);
}

char	*rand_str(char *str, size_t len)
{
	size_t	i = 0;

	while (i < len)
		str[i++] = rand_char();
	str[i] = '\0';
	return (str);
}

char	*rrand_str(char *str, size_t max_len)
{
	size_t	len = (arc4random_uniform(max_len));

	return (rand_str(str, len));
}

size_t	randi(size_t max)
{
	return (arc4random_uniform(max));
}
