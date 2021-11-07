/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:31:23 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/07 19:18:37 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memset(void)
{
	char	*ptr1;
	char	*ptr2;
	char	c;

	printf("...ft_memset\n");
	ptr1 = (char *) malloc(sizeof(char) * 8);
	ptr2 = (char *) malloc(sizeof(char) * 8);
	c = rand_char();
	ft_memset(ptr1, c, sizeof(char) * 8);
	memset(ptr2, c, sizeof(char) * 8);
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
	char	str1[] = "fortytwoaaaaa";
	char	str2[] = "aaaaaaaaaaaaa";
	size_t 	len;

	printf("...ft_memcpy\n");
	len = 8;
	ft_memcpy(str2, str1, len);
	printf("[%s]\n", str2);
	assert(memcmp(str1, str2, sizeof(char) * len + 2) == 0);
}

static void rand_memmove(size_t len, int i)
{
	size_t	test_src;
	size_t	test_dst;
	size_t	test_len;
	char*	str_rand;
	char*	str1;
	char*	str2;

	str_rand = rand_str(len);
	str1 = strdup(str_rand);
	str2 = strdup(str_rand);
	if (str1 == NULL || str2 == NULL)
	{
		printf("error allocating memory: [%s]\n", strerror(errno));
		abort();
	}
	test_len = arc4random_uniform(len);
	test_src = arc4random_uniform(len - test_len);
	test_dst = arc4random_uniform(len - test_len);
	memmove((str1 + test_dst), (str1 + test_src), test_len);
	ft_memmove((str2 + test_dst), (str2 + test_src), test_len);
	if (memcmp(str1, str2, sizeof(char) * len) != 0)
	{
		printf("failed for test #%d (%zu chars):\n", i, len);
		printf("src %zu dst %zu, len %zu\n", test_src, test_dst, test_len);
		printf("original:\t[%s]\nmemmove:\t[%s]\nft_memmove:\t[%s]\n", str_rand, str1, str2);
		abort();
	}
	free(str_rand);
	free(str1);
	free(str2);
}

void	test_memmove(void)
{
	int		tests = 100;
	int		i = 0;
	size_t	max_len = 100;

	printf("...ft_memmove\n");
	while (i < tests)
		rand_memmove(arc4random_uniform(max_len), i++);
}

void	test_memchr(void)
{

}

void	test_memcmp(void)
{

}

void	test_strlen(void)
{
	int		tests = 100;
	size_t	max_len = 1000;
	size_t	cur_len;
	char	*str;

	printf("...ft_strlen\n");
	while (tests > 0)
	{
		cur_len = arc4random() % max_len;
		str = (char *) malloc(sizeof(char) * (cur_len + 1));
		str = rand_str(cur_len);
		if (ft_strlen(str) != strlen(str))
		{
			printf("failed for str [%s]\n", str);
			free(str);
			abort();
		}
		free(str);
		tests--;
	}
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

static void	rand_strcmp(size_t len, size_t same_chars, int i)
{
	char	*str1;
	char	*str2;

	if (!rand_substrs(&str1, &str2, same_chars, len - same_chars))
	{
		fprintf(stderr, "rand_substrs failed\n");
		abort();
	}
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
	{
		printf("test %d: failed for [%s] vs [%s]\n", i, str1, str2);
	}
	free(str1);
	free(str2);
}	

void	test_strcmp(void)
{
	int		tests = 100;
	int		i = 0;
	size_t	len = 24;
	size_t	same_chars = 12;
		
	printf("...ft_strcmp\n");
	while (i < tests)
		rand_strcmp(len, same_chars, i++);
}

static void	rand_strncmp(size_t len, size_t same_chars)
{
	char	*str1;
	char	*str2;
	size_t	i;

	rand_substrs(&str1, &str2, same_chars, len - same_chars);
	i = arc4random() % len;
	if (ft_strncmp(str1, str2, i) != strncmp(str1, str2, i))
	{
		printf("failed for [%s] vs [%s], i=%zu\n", str1, str2, i);
		abort();
	}
	free(str1);
	free(str2);
}	


void	test_strncmp(void)
{
	int		tests = 100;
	size_t	len = 24;
	size_t	same_chars = 12;
		
	printf("...ft_strncmp\n");
	while (tests > 0)
	{
		rand_strncmp(len, same_chars);
		tests--;
	}
}

void	test_atoi(void)
{

}

static void	validate_chartest(int (*ft_func)(int), int (*lib_func)(int))
{
	int c;

	c = 0;
	while (c <= CHAR_MAX)
	{
		if ((ft_func(c) != 0 ? 1 : 0) != (lib_func(c) != 0 ? 1 : 0))
		{
			printf("failed for c=%d [%c]\n", c, c);
			abort();
		}
		c++;
	}
}

void	test_isalpha(void)
{
	printf("...ft_isalpha\n");
	validate_chartest(&ft_isalpha, &isalpha);
}

void	test_isdigit(void)
{
	printf("...ft_isdigit\n");
	validate_chartest(&ft_isdigit, &isdigit);
}

void	test_isalnum(void)
{
	printf("...ft_isalnum\n");
	validate_chartest(&ft_isalnum, &isalnum);
}

void	test_isascii(void)
{
	printf("...ft_isascii\n");
	validate_chartest(&ft_isascii, &isascii);
}

void	test_isprint(void)
{
	printf("...ft_isprint\n");
	validate_chartest(&ft_isprint, &isprint);
}

static void	validate_charconv(int (*ft_func)(int), int (*lib_func)(int))
{
	int c;

	c = 0;
	while (c <= CHAR_MAX)
	{
		if (ft_func(c) != lib_func(c))
		{
			printf("failed for c=%d [%c]\n", c, c);
			abort();
		}
		c++;
	}
}

void	test_toupper(void)
{
	printf("...ft_toupper\n");
	validate_charconv(&ft_toupper, &toupper);
}

void	test_tolower(void)
{
	printf("...ft_tolower\n");
	validate_charconv(&ft_tolower, &tolower);
}
