/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:03 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/02 19:01:12 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

void	test_putendl(void)
{
	FILE	*fd;
	char	*buf;
	char	str[] = "Don't Panic!";

	printf("...ft_putendl\n");
	buf = (char *) malloc(sizeof(char) * (strlen(str) + 2));
	fd = freopen(FPATH, "w", stdout);
	ft_putendl(str);
	fclose(fd);
	fd = fopen(FPATH, "r");
	fread(buf, strlen(str) + 2, 1, fd);
	fclose(fd);
	freopen("/dev/tty", "w", stdout);
	printf("[%s]\n", buf);
	assert(strncmp(buf, str, strlen(str)) == 0);
	assert(buf[strlen(str)] == '\n');
	remove(FPATH);
	free(buf);
}
