/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:31:23 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/08 19:53:13 by tpolonen         ###   ########.fr       */
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
	ptr1 = (char *) malloc(sizeof(char) * 9);
	ptr2 = (char *) malloc(sizeof(char) * 9);
	bzero(ptr1, 9);
	bzero(ptr2, 9);
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

static void	const_test_memmove(int i)
{
	char	str1[] = "meaning of life is fortytwo and here's more chars for string";
	char	str2[] = "meaning of life is fortytwo and here's more chars for string";
	size_t	len = strlen(str1);
	size_t	test_dst;
	size_t	test_src;
	size_t	test_len;

	test_len = randi(len);
	test_dst = randi(len - test_len);
	test_src = randi(len - test_len);
	memmove((str1 + test_dst), (str1 + test_src), test_len);
	ft_memmove((str2 + test_dst), (str2 + test_src), test_len);
	if (memcmp(str1, str2, sizeof(char) * len) != 0)
	{
		printf("failed for test #%d (%zu chars):\n", i, len);
		printf("dst %zu src %zu len %zu\n", test_dst, test_src, test_len);
		printf("memmove:\t[%s]\nft_memmove:\t[%s]\n", str1, str2);
		abort();
	}
}

void	test_memmove(void)
{
	int		tests = 100;
	int		i = 0;

	printf("...ft_memmove\n");
	while (i < tests)
		const_test_memmove(i++);
	i = 0;
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
		cur_len = randi(max_len);
		str = (char *) malloc(sizeof(char) * (cur_len + 1));
		str = rand_str(str, cur_len);
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

static void	rand_strdup(size_t max_len, size_t i)
{
	size_t	len = randi(max_len);
	char	*str, *dup;

	str = (char *) malloc(sizeof(char) * (len + 1));
	rand_str(str, len);
	dup = ft_strdup(str);
	if (strcmp(str, dup) != 0)
	{
		printf("test #%zu failed\nstr: [%s]\ndup: [%s]\n", i, str, dup);
		abort();
	}
}

void	test_strdup(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strdup\n");
	while (i < tests)
		rand_strdup(100, i++);
}

void	test_strcpy(void)
{

}

void	test_strncpy(void)
{

}

static void	rand_strcat(size_t max_len, size_t i)
{
	char	*str1, *str2, *ft_cat, *libc_cat;
	size_t	len1 = randi(max_len);
	size_t	len2 = randi(max_len);

	str1 = (char *) malloc(sizeof(char) * (len1 + 1));
	str2 = (char *) malloc(sizeof(char) * (len2 + 1));
	ft_cat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	libc_cat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	bzero(str1, len1 + 1);
	bzero(str2, len2 + 1);
	bzero(ft_cat, len1 + len2 + 1);
	bzero(libc_cat, len1 + len2 + 1);
	rand_str(str1, len1);
	rand_str(str2, len2);
	ft_cat = ft_strcat(ft_cat, str1);
	ft_cat = ft_strcat(ft_cat, str2);
	libc_cat = strcat(libc_cat, str1);
	libc_cat = strcat(libc_cat, str2);
	if (strcmp(ft_cat, libc_cat) != 0)
	{
		printf("test #%zu failed for strings [%s] + [%s]\nexpected [%s], got [%s]\n",
			   i, str1, str2, libc_cat, ft_cat);
		abort();
	}
	free(str1);
	free(str2);
	free(ft_cat);
	free(libc_cat);
}

void	test_strcat(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strcat\n");
	while (i < tests)
		rand_strcat(50, i++);
}

static void	rand_strncat(size_t max_len, size_t i)
{
	char	*str1, *str2, *ft_cat, *libc_cat;
	size_t	len1 = randi(max_len);
	size_t	len2 = randi(max_len);
	size_t	n = randi(len2);

	str1 = (char *) malloc(sizeof(char) * (len1 + 1));
	str2 = (char *) malloc(sizeof(char) * (len2 + 1));
	ft_cat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	libc_cat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	bzero(str1, len1 + 1);
	bzero(str2, len2 + 1);
	bzero(ft_cat, len1 + len2 + 1);
	bzero(libc_cat, len1 + len2 + 1);
	rand_str(str1, len1);
	rand_str(str2, len2);
	ft_cat = ft_strncat(ft_cat, str1, len1);
	ft_cat = ft_strncat(ft_cat, str2, n);
	libc_cat = strncat(libc_cat, str1, len1);
	libc_cat = strncat(libc_cat, str2, n);
	if (strcmp(ft_cat, libc_cat) != 0)
	{
		printf("test #%zu failed for strings [%s] + [%s] n=%zu\nexpected [%s], got [%s]\n",
			   i, str1, str2, n, libc_cat, ft_cat);
		abort();
	}
	free(str1);
	free(str2);
	free(ft_cat);
	free(libc_cat);
}

void	test_strncat(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strncat\n");
	while (i < tests)
		rand_strncat(50, i++);
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

static void	rand_substrs(char *str1, char *str2, size_t len_pre, size_t len_post)
{
	bzero(str1, len_pre + len_post + 1);
	bzero(str2, len_pre + len_post + 1);
	rand_str(str1, len_pre);
	strncat(str2, str1, len_pre);
	rand_str((str1 + len_pre), len_post);
	rand_str((str2 + len_pre), len_post);
}

static void	strcmp_printout(char *str1, char *str2)
{
	printf("[%s] vs [%s]\ngot %d, should have been %d\nKO D:\n", str1, str2, 
			ft_strcmp(str1, str2), strcmp(str1, str2));
}

static void	strcmp_same(size_t max_len)
{
	size_t len_pre = randi(max_len);
	char *str1, *str2;

	str1 = (char *) malloc (sizeof(char) * (len_pre + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + 1));
	rand_substrs(str1, str2, len_pre, 0);
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
	{
		strcmp_printout(str1, str2);
		abort();
	}
	free(str1);
	free(str2);
}

static void	strcmp_same_len(size_t max_len_pre, size_t max_len_post)
{
	size_t len_pre = randi(max_len_pre);
	size_t len_post = randi(max_len_post);
	char *str1, *str2;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
	{
		strcmp_printout(str1, str2);
		abort();
	}
	free(str1);
	free(str2);
}

static void strcmp_diff_len(size_t max_len_pre, size_t max_len_post)
{
	size_t len_pre = randi(max_len_pre);
	size_t len_post = randi(max_len_post);
	char *str1, *str2;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	*(str2 + randi(len_pre) + randi(len_post)) = '\0';
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
	{
		strcmp_printout(str1, str2);
		abort();
	}
	free(str1);
	free(str2);
}

void	test_strcmp(void)
{
	size_t	tests = 100;
	size_t	i = 0;

	printf("...ft_strcmp\n");
	printf("comparing similar strings\n");
	while (i < tests)
	{
		strcmp_same(100);
		i++;
	}
	i = 0;

	printf("comparing same length strings\n");
	while (i < tests)
	{
		strcmp_same_len(50, 50);
		i++;
	}
	i = 0;

	printf("comparing different length strings\n");
	while (i < tests)
	{
		strcmp_diff_len(50, 50);
		i++;
	}
}

static void	strncmp_printout(char *str1, char *str2, size_t n)
{
	printf("[%s] vs [%s], n=%zu\ngot %d, should have been %d\nKO D:\n", str1, str2, n, 
			ft_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

static void	strncmp_same(size_t max_len)
{
	size_t 	len_pre = randi(max_len);
	size_t	n = randi(len_pre);
	char 	*str1, *str2;

	str1 = (char *) malloc (sizeof(char) * (len_pre + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + 1));
	rand_substrs(str1, str2, len_pre, 0);
	if (ft_strncmp(str1, str2, n) != strncmp(str1, str2, n))
	{
		strncmp_printout(str1, str2, n);
		abort();
	}
	free(str1);
	free(str2);
}

static void	strncmp_same_len(size_t max_len_pre, size_t max_len_post)
{
	size_t	len_pre = randi(max_len_pre);
	size_t	len_post = randi(max_len_post);
	size_t	n = randi(len_pre + len_post);
	char	*str1, *str2;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	if (ft_strncmp(str1, str2, n) != strncmp(str1, str2, n))
	{
		strncmp_printout(str1, str2, n);
		abort();
	}
	free(str1);
	free(str2);
}

static void strncmp_diff_len(size_t max_len_pre, size_t max_len_post)
{
	size_t	len_pre = randi(max_len_pre);
	size_t	len_post = randi(max_len_post);
	size_t	n = randi(len_pre + len_post);
	char	*str1, *str2;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	*(str2 + randi(len_pre) + randi(len_post)) = '\0';
	if (ft_strncmp(str1, str2, n) != strncmp(str1, str2, n))
	{
		strncmp_printout(str1, str2, n);
		abort();
	}
	free(str1);
	free(str2);
}
void	test_strncmp(void)
{
	size_t	tests = 100;
	size_t	i = 0;

	printf("...ft_strncmp\n");
	printf("comparing similar strings\n");
	while (i < tests)
	{
		strncmp_same(100);
		i++;
	}
	i = 0;

	printf("comparing same length strings\n");
	while (i < tests)
	{
		strncmp_same_len(50, 50);
		i++;
	}
	i = 0;

	printf("comparing different length strings\n");
	while (i < tests)
	{
		strncmp_diff_len(50, 50);
		i++;
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
