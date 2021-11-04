/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:31:23 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/04 23:54:30 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memset(void)
{
	char	*ptr1;
	char	*ptr2;

	printf("...ft_memset\n");
	ptr1 = (char *) malloc(sizeof(char) * 8);
	ptr2 = (char *) malloc(sizeof(char) * 8);
	ft_memset(ptr1, 'a', sizeof(char) * 8);
	memset(ptr2, 'a', sizeof(char) * 8);
	printf("[%s] vs [%s]\n", ptr1, ptr2);
	assert(memcmp(ptr1, ptr2, sizeof(char) * 8) == 0);
	free(ptr1);
	free(ptr2);
}

void	test_bzero(void)
{
	char	str1[] = "fortytwo";
	char	str2[] = "fortyone";
	size_t 	len;

	printf("...ft_bzero\n");
	len = strlen(str1);
	ft_bzero(str1, len);
	bzero(str2, len);
	assert(memcmp(str1, str2, sizeof(char) * len) == 0);
}

void	test_memcpy(void)
{

}

void	test_memmove(void)
{

}

void	test_memchr(void)
{

}

void	test_memcmp(void)
{

}

void	test_strlen(void)
{

}

void	test_strdup(void)
{

}

void	test_strcpy(void)
{

}

void	test_strncpy(void)
{

}

void	test_strcat(void)
{

}

void	test_strncat(void)
{

}

void	test_strlcat(void)
{

}

void	test_strchr(void)
{

}

void	test_strrchr(void)
{

}

void	test_strstr(void)
{

}

void	test_strnstr(void)
{

}

void	test_strcmp(void)
{

}

void	test_strncmp(void)
{

}

void	test_atoi(void)
{

}

void	test_isalpha(void)
{
	int	c;

	printf("...ft_isalpha\n");
	c = 0;
	while (c < 128)
	{
		assert((ft_isalpha(c) != 0 ? 1 : 0) == (isalpha(c) != 0 ? 1 : 0));
		c++;
	}
}

void	test_isdigit(void)
{
	int	c;

	printf("...ft_isdigit\n");
	c = 0;
	while (c < 128)
	{
		assert((ft_isdigit(c) != 0 ? 1 : 0) == (isdigit(c) != 0 ? 1 : 0));
		c++;
	}
}

void	test_isalnum(void)
{

}

void	test_isascii(void)
{

}

void	test_isprint(void)
{

}

void	test_toupper(void)
{

}

void	test_tolower(void)
{

}
