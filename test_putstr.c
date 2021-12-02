/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:34 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/01 19:07:56 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

void	test_putstr(void)
{
	FILE	*fd;
	char	*buf;
	char	str[] = "The ships hung in the sky in much the same way that bricks don't.";

	printf("...ft_putstr\n");
	buf = (char *) malloc(sizeof(char) * (strlen(str) + 1));
	fd = freopen(FPATH, "w", stdout);
	ft_putstr(str);
	fclose(fd);
	fd = fopen(FPATH, "r");
	fread(buf, strlen(str) + 1, 1, fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strcmp(buf, str) == 0);
	remove(FPATH);
}
