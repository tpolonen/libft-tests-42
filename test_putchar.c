/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:19 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:00:28 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

void	test_putchar(void)
{
	FILE	*fd;
	char	*c;

	printf("...ft_putchar\n");
	c = (char *) malloc(sizeof(char));
	fd = freopen(FPATH, "w", stdout);
	ft_putchar('!');
	fclose(fd);
	fd = fopen(FPATH, "r");
	*c = (char) fgetc(fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%c]\n", *c);
	assert(*c == '!');
	remove(FPATH);
	free(c);
}


