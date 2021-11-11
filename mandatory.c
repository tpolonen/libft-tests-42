/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:31:23 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/11 20:18:13 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	test_memset(void)
{
	char	*ptr1 = NULL;
	char	*ptr2 = NULL;
	char	c = rand_char();

	printf("...ft_memset\n");
	#ifdef NULLCHECK
		memset(NULL, c, (0));
		printf("nullcheck ");
		ft_memset(NULL, c, (0));
		printf("OK\n");
	#endif
	ptr1 = (char *) malloc(sizeof(char) * 9);
	ptr2 = (char *) malloc(sizeof(char) * 9);
	bzero(ptr1, 9);
	bzero(ptr2, 9);
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
	size_t 	len = strlen(str1);

	printf("...ft_bzero\n");
	#ifdef NULLCHECK
		bzero(NULL, (0));
		printf("nullcheck ");
		ft_bzero(NULL, (0));
		printf("OK\n");
	#endif
	ft_bzero(str1, len);
	bzero(str2, len);
	assert(memcmp(str1, str2, sizeof(char) * len) == 0);
}

void	test_memcpy(void)
{
	char	str1[] = "fortytwoaaaaa";
	char	str2[] = "aaaaaaaaaaaaa";
	size_t 	len = 8;

	printf("...ft_memcpy\n");
	#ifdef NULLCHECK
		memcpy(NULL, str1, 0);
		memcpy(str2, NULL, 0);
		memcpy(NULL, NULL, len);
		printf("nullcheck ");
		ft_memcpy(NULL, str1, 0);
		ft_memcpy(str2, NULL, 0);
		ft_memcpy(NULL, NULL, len);
		printf("OK\n");
	#endif
	ft_memcpy(str2, str1, len);
	printf("[%s]\n", str2);
	assert(memcmp(str1, str2, sizeof(char) * len + 2) == 0);
}

static void	rand_memccpy(size_t max_len, size_t i, char c)
{
	void	*src, *ptr1, *ptr2;
	size_t	len = randi(max_len);

	src = malloc(len);
	ptr1 = malloc(len);
	ptr2 = malloc(len);
	memset(src, rand_char(), len);
	if (isprint(c))
		memset(src + randi(len), c, 1);
	bzero(ptr1, len);
	bzero(ptr2, len);
	memccpy(ptr1, src, c, len);
	ft_memccpy(ptr2, src, c, len);
	if (memcmp(ptr1, ptr2, len) != 0)
	{
		printf("test #%zu failed ", i);
		if (isprint(c)) printf("(c=%c)", c);
		printf("\nsrc\t[");
		print_mem(src, len);
		printf("]\nlibc\t[");
		print_mem(ptr1, len);
		printf("]\nlibft\t[");
		print_mem(ptr2, len);
		printf("]\n");
		abort();
	}
	free(src);
	free(ptr1);
	free(ptr2);
}

void	test_memccpy(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_memccpy\n");
	rand_memccpy(0, i++, '\n');
	printf("copying with present char\n");
	while (i < tests)
		rand_memccpy(100, i++, rand_char());
	i = 0;
	printf("copying with missing char\n");
	while (i < tests)
		rand_memccpy(100, i++, '\n');
}

static void	const_memmove(int i)
{
	char	str1[] = "meaning of life is fortytwo and here's more chars for string";
	char	str2[] = "meaning of life is fortytwo and here's more chars for string";
	size_t	len = 0;
	size_t	test_dst;
	size_t	test_src;
	size_t	test_len;

	if (i > 0)
		len = strlen(str1);
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
	#ifdef NULLCHECK
		char nullcheck[] = "fortytwo";
		memmove(NULL, NULL, 1);
		memmove(NULL, nullcheck, 0);
		memmove(nullcheck, NULL, 0);
		printf("nullcheck ");
		ft_memmove(NULL, NULL, 1);
		ft_memmove(NULL, nullcheck, 0);
		ft_memmove(nullcheck, NULL, 0);
		printf("OK\n");
	#endif
	while (i < tests)
		const_memmove(i++);
	i = 0;
}

static void	found_memchr(size_t max_size, size_t i)
{
	size_t	size = randi(max_size);
	void	*ptr;
	char	seek = rand_char();
	
	ptr = malloc(size);
	memset(ptr, rand_char(), size);
	memset(ptr + randi(size), seek, 1);
	if (ft_memchr(ptr, seek, size) != memchr(ptr, seek, size))
	{
		printf("test #%zu failed (c=%c)\nptr: [", i, seek);
		print_mem(ptr, size);
		printf("]\n");
		printf("libc:\t%p\nlibft:\t%p\n", memchr(ptr, seek, size), ft_memchr(ptr, seek, size));
		abort();
	}
	free(ptr);
}

static void	not_found_memchr(size_t max_size, size_t i)
{
	size_t	size = randi(max_size);
	void	*ptr;
	
	ptr = malloc(size);
	memset(ptr, rand_char(), size);
	if (ft_memchr(ptr, '\t', size) != memchr(ptr, '\t', size))
	{
		printf("test #%zu failed\nptr: [", i);
		print_mem(ptr, size);
		printf("]\n");
		printf("libc:\t%p\nlibft:\t%p\n", memchr(ptr, '\t', size), ft_memchr(ptr, '\t', size));
		abort();
	}
	free(ptr);
}

void	test_memchr(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_memchr\n");
	found_memchr(0, i++);
	printf("seeking present char\n");
	while (i < tests)
		found_memchr(100, i++);
	i = 0;
	printf("seeking missing char\n");
	while (i < tests)
		not_found_memchr(100, i++);
}

static void	same_memcmp(size_t max_size, size_t i)
{
	size_t	size = randi(max_size), j = 0;
	void	*ptr1, *ptr2;
	int		ft_result, libc_result;

	ptr1 = malloc(size);
	ptr2 = malloc(size);
	while (j < size)
		memset(ptr1 + j++, rand_char(), 1);
	memcpy(ptr2, ptr1, size);
	if ((ft_result = ft_memcmp(ptr1, ptr2, size)) != (libc_result = memcmp(ptr1, ptr2, size)))
	{
		printf("test #%zu failed:\nptr1: [", i);
		print_mem(ptr1, size);
		printf("]\nptr2: [");
		print_mem(ptr2, size);
		printf("]\ngot %d, expected %d\n", ft_result, libc_result);
		if (!signtest(ft_result, libc_result))
			abort();
		else printf("same sign though, continuing\n");
	}
	free(ptr1);
	free(ptr2);
}

static void	diff_memcmp(size_t max_size_pre, size_t max_size_post, size_t i)
{
	size_t 	size_pre = randi(max_size_pre);
	size_t 	size_post = randi(max_size_post);
	size_t	size = size_pre + size_post;
	size_t	j = 0;
	void	*ptr1, *ptr2;
	int		ft_result, libc_result;

	ptr1 = malloc(size_pre + size_post);
	ptr2 = malloc(size_pre + size_post);
	while (j < size_pre)
		memset(ptr1 + j++, rand_char(), 1);
	memcpy(ptr2, ptr1, size_pre);
	while (j < size)
	{
		memset(ptr1 + j, rand_char(), 1);
		memset(ptr2 + j, rand_char(), 1);
		j++;
	}
	if ((ft_result = ft_memcmp(ptr1, ptr2, size)) != (libc_result = memcmp(ptr1, ptr2, size)))
	{
		printf("test #%zu failed (size_pre=%zu, size_post=%zu, size=%zu)\nptr1: [", i, size_pre, size_post, size);
		print_mem(ptr1, size);
		printf("]\nptr2: [");
		print_mem(ptr2, size);
		printf("]\ngot %d, expected %d\n", ft_memcmp(ptr1, ptr2, size), memcmp(ptr1, ptr2, size));
		if (!signtest(ft_result, libc_result))
			abort();
		else printf("same sign though, continuing\n");
	}
	free(ptr1);
	free(ptr2);
}

void	test_memcmp(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_memcmp\n");
	printf("comparing similar pointers\n");
	same_memcmp(0, i++);
	while (i < tests)
		same_memcmp(100, i++);
	i = 0;
	printf("comparing differing pointers\n");
	while (i < tests)
		diff_memcmp(100,50, i++);
}

static void	rand_strlen(size_t max_len, size_t i)
{
	char	*str;
	size_t	cur_len = randi(max_len);

	str = (char *) malloc(sizeof(char) * (cur_len + 1));
	str = rand_str(str, cur_len);
	if (ft_strlen(str) != strlen(str))
	{
		printf("test #%zu: failed for str [%s]\n", i, str);
		abort();
	}
	free(str);
}

void	test_strlen(void)
{
	size_t	tests = 100;
	size_t	i = 0;
	size_t	max_len = 1000;

	printf("...ft_strlen\n");
/* 
 * These tests were removed because libbsd's strlen(NULL) will cause segfault.
 * However, consider adding check to your ft_strlen.
 * 
 * strlen(NULL);
 * ft_strlen(NULL);
 */
	rand_strlen(0, i++);
	while (i < tests)
		rand_strlen(max_len, i++);
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
	free(str);
	free(dup);
}

void	test_strdup(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strdup\n");
	rand_strdup(0, i++);
	while (i < tests)
		rand_strdup(100, i++);
}

static void	rand_strcpy(size_t max_len, size_t i)
{
	size_t	len = randi(max_len);
	char	*str, *cpy;

	str = (char *) malloc(sizeof(char) * (len + 1));
	cpy = (char *) malloc(sizeof(char) * (len + 1));
	bzero(cpy, len + 1);
	rand_str(str, len);
	ft_strcpy(cpy, str);
	if (strcmp(str, cpy) != 0)
	{
		printf("test #%zu failed\nstr: [%s]\ncpy: [%s]\n", i, str, cpy);
		abort();
	}
	free(str);
	free(cpy);
}

void	test_strcpy(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strcpy\n");
	rand_strcpy(0, i++);
	while (i < tests)
		rand_strcpy(100, i++);
}

static void	rand_strncpy(size_t max_len, size_t i)
{
	size_t	len = randi(max_len);
	size_t	n = randi(len + 1);
	char	*str, *cpy;

	str = (char *) malloc(sizeof(char) * (len + 1));
	cpy = (char *) malloc(sizeof(char) * (len + 1));
	rand_str(str, len);
	bzero(cpy, len + 1);
	ft_strncpy(cpy, str, n);
	if (memcmp(str, cpy, n) != 0)
	{
		printf("test #%zu failed (len=%zu)\nstr: [%s]\ncpy: [%s]\n", i, n, str, cpy);
		abort();
	}
	free(str);
	free(cpy);
}

void	test_strncpy(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strncpy\n");
	rand_strncpy(0, i++);
	while (i < tests)
		rand_strncpy(100, i++);
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
	rand_strcat(0, i++);
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
	rand_strncat(0, i++);
	while (i < tests)
		rand_strncat(50, i++);
}

static void	rand_strlcat(size_t max_len, size_t i)
{
	char	*src, *ft_cat, *libc_cat;
	size_t	src_len = randi(max_len);
	size_t	root_len = randi(max_len) + 1;
	size_t	dest_len = root_len + randi(src_len) + 1;
	size_t	libc_total, ft_total;

	src = (char *) malloc(sizeof(char) * (src_len + 1));
	rand_str(src, src_len);
	ft_cat = (char *) malloc(sizeof(char) * (dest_len + 1));
	libc_cat = (char *) malloc(sizeof(char) * (dest_len + 1));
	bzero(ft_cat, dest_len);
	bzero(libc_cat, dest_len);
	rand_str(ft_cat, root_len);
	strncat(libc_cat, ft_cat, root_len);
	ft_total = ft_strlcat(ft_cat, src, dest_len + 1);
	libc_total = strlcat(libc_cat, src, dest_len + 1);
	if (ft_total != libc_total || strcmp(ft_cat, libc_cat) != 0)
	{
		printf("test #%zu failed (dstsize=%zu, src len=%zu)\n", i, dest_len + 1, strlen(src));
		printf("strlcat returned %zu, ft_strlcat %zu\n", libc_total, ft_total);
		printf("src\t[%s]\nlibc\t[%s]\nlibft\t[%s]\n", src, libc_cat, ft_cat);
		abort();
	}
	free(src);
	free(ft_cat);
	free(libc_cat);
}

void	test_strlcat(void)
{
	size_t tests = 100, i = 0;

	printf("...ft_strlcat\n");
	#ifndef LINUX
		rand_strlcat(0, i++);
	#endif
	while (i < tests)
		rand_strlcat(75, i++);
}

static void	found_strchr(size_t max_len, char seek, size_t i)
{
	size_t	len = randi(max_len);
	char	*str;

	str = (char *) malloc(sizeof(char) * len + 1);
	rand_str(str, len);
	str[randi(len)] = seek;
	if (ft_strchr(str, seek) != strchr(str, seek))
	{
		printf("test #%zu failed (c=%c)\n", i, seek);
		printf("str: [%s]\nlibc:\t%p\nlibft:\t%p\n", str, strchr(str, seek), ft_strchr(str, seek));
		abort();
	}
	free(str);
}

static void	not_found_strchr(size_t max_len, char seek, size_t i)
{
	size_t	len = randi(max_len);
	char	*str;

	str = (char *) malloc(sizeof(char) * len + 1);
	rand_str(str, len);
	if (ft_strchr(str, seek) != strchr(str, seek))
	{
		printf("test #%zu failed\n", i);
		printf("str: [%s]\nlibc:\t%p\nlibft:\t%p\n", str, strchr(str, seek), ft_strchr(str, seek));
		abort();
	}
	free(str);
}

void	test_strchr(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strchr\n");
	not_found_strchr(0, 'a', i++);
	printf("seeking present char\n");
	while (i < tests)
		found_strchr(100, rand_char(), i++);
	i = 0;
	printf("seeking missing char\n");
	while (i < tests)
		not_found_strchr(100, '\t', i++);
	i = 0;
	printf("seeking terminator\n");
	while (i < tests)
		not_found_strchr(100, '\0', i++);
}

static void	found_strrchr(size_t max_len, char seek, size_t i)
{
	size_t	len = randi(max_len);
	size_t	hits = 3;
	char	*str;

	str = (char *) malloc(sizeof(char) * len + 1);
	rand_str(str, len);
	while (hits > 0)
	{
		str[randi(len)] = seek;
		hits--;
	}
	if (ft_strrchr(str, seek) != strrchr(str, seek))
	{
		printf("test #%zu failed (c=%c)\n", i, seek);
		printf("str: [%s]\nlibc:\t%p\nlibft:\t%p\n", str, strrchr(str, seek), ft_strrchr(str, seek));
		abort();
	}
	free(str);
}

static void	not_found_strrchr(size_t max_len, char seek, size_t i)
{
	size_t	len = randi(max_len);
	char	*str;

	str = (char *) malloc(sizeof(char) * len + 1);
	rand_str(str, len);
	if (ft_strrchr(str, seek) != strrchr(str, seek))
	{
		printf("test #%zu failed\n", i);
		printf("str: [%s]\nlibc:\t%p\nlibft:\t%p\n", str, strrchr(str, seek), ft_strrchr(str, seek));
		abort();
	}
	free(str);
}

void	test_strrchr(void)
{
	size_t	tests = 100, i = 0;

	printf("...ft_strrchr\n");
	not_found_strrchr(0, 'a', i++);
	printf("seeking present char\n");
	while (i < tests)
		found_strrchr(100, rand_char(), i++);
	i = 0;
	printf("seeking missing char\n");
	while (i < tests)
		not_found_strrchr(100, '\t', i++);
	i = 0;
	printf("seeking terminator\n");
	while (i < tests)
		not_found_strrchr(100, '\0', i++);
}

static void	found_strstr(size_t max_haystack, size_t i)
{
	size_t	haystack_len = randi(max_haystack);
	size_t	needle_len = randi(haystack_len);
	char	*haystack, *needle;

	haystack = (char *) malloc(sizeof(char) * (haystack_len + 1));
	needle = (char *) malloc(sizeof(char) * (needle_len + 1));
	rand_str(haystack, haystack_len);
	rand_str(needle, needle_len);
	memcpy(haystack + (randi(haystack_len - needle_len)), needle, needle_len);
	if (ft_strstr(haystack, needle) != strstr(haystack, needle))
	{
		printf("test #%zu failed\nhystck:\t[%s]\nneedle:\t[%s]\n",
				i, haystack, needle);
		printf("libc:\t%p\nlibft:\t%p\n", strstr(haystack, needle),
				ft_strstr(haystack, needle));
		abort();
	}
	free(haystack);
	free(needle);
}

static void	not_found_strstr(size_t max_haystack, size_t i)
{
	size_t	haystack_len = randi(max_haystack);
	size_t	needle_len = randi(haystack_len);
	char	*haystack, *needle;

	haystack = (char *) malloc(sizeof(char) * (haystack_len + 1));
	needle = (char *) malloc(sizeof(char) * (needle_len + 1));
	rand_str(haystack, haystack_len);
	rand_str(needle, needle_len);
	if (ft_strstr(haystack, needle) != strstr(haystack, needle))
	{
		printf("test #%zu failed\nhystck:\t[%s]\nneedle:\t[%s]\n",
				i, haystack, needle);
		printf("libc:\t%p\nlibft:\t%p\n", strstr(haystack, needle),
				ft_strstr(haystack, needle));
		abort();
	}
	free(haystack);
	free(needle);
}

void	test_strstr(void)
{
	size_t	tests = 100, i = 0;
	printf("...ft_strstr\n");
	found_strstr(0, i++);
	printf("seeking present needle\n");
	while (i < tests)
		found_strstr(30, i++);
	i = 0;
	printf("seeking missing needle\n");
	while (i < tests)
		not_found_strstr(50, i++);

}

static void	found_strnstr(size_t max_haystack, size_t needle_len, size_t i)
{
	size_t	haystack_len = needle_len + randi(max_haystack - needle_len);
	size_t	len = haystack_len/2 + randi(haystack_len/2 + 1);
	char	*haystack, *needle;

	haystack = (char *) malloc(sizeof(char) * (haystack_len + 1));
	needle = (char *) malloc(sizeof(char) * (needle_len + 1));
	rand_str(haystack, haystack_len);
	rand_str(needle, needle_len);
	memcpy(haystack + (randi(haystack_len - needle_len)), needle, needle_len);
	if (ft_strnstr(haystack, needle, len) != strnstr(haystack, needle, len))
	{
		printf("test #%zu failed (len=%zu)\nhystck:\t[%s]\nneedle:\t[%s]\n",
				i, len, haystack, needle);
		printf("libc:\t%p\nlibft:\t%p\n", strnstr(haystack, needle, len),
				ft_strnstr(haystack, needle, len));
		abort();
	}
	free(haystack);
	free(needle);
}

static void	not_found_strnstr(size_t max_haystack, size_t needle_len, size_t i)
{
	size_t	haystack_len = needle_len + randi(max_haystack - needle_len);
	size_t	len = haystack_len/2 + randi(haystack_len/2 + 1);
	char	*haystack, *needle;

	haystack = (char *) malloc(sizeof(char) * (haystack_len + 1));
	needle = (char *) malloc(sizeof(char) * (needle_len + 1));
	rand_str(haystack, haystack_len);
	rand_str(needle, needle_len);
	if (ft_strnstr(haystack, needle, len) != strnstr(haystack, needle, len))
	{
		printf("test #%zu failed (len=%zu)\nhystck:\t[%s]\nneedle:\t[%s]\n",
				i, len, haystack, needle);
		printf("libc:\t%p\nlibft:\t%p\n", strnstr(haystack, needle, len),
				ft_strnstr(haystack, needle, len));
		abort();
	}
	free(haystack);
	free(needle);
}

void	test_strnstr(void)
{
	size_t	tests = 100, i = 0;
	printf("...ft_strnstr\n");
	found_strnstr(0, 0, i++);
	printf("seeking present needle\n");
	while (i < tests)
		found_strnstr(40, 8, i++);
	i = 0;
	printf("seeking missing needle\n");
	while (i < tests)
		not_found_strnstr(50, 15, i++);
}

static void	strcmp_printout(char *str1, char *str2)
{
	printf("[%s] vs [%s]\ngot %d, expected %d\nKO D:\n", str1, str2, 
			ft_strcmp(str1, str2), strcmp(str1, str2));
}

static void	strcmp_same(size_t max_len)
{
	size_t len_pre = randi(max_len);
	char *str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len_pre + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + 1));
	rand_substrs(str1, str2, len_pre, 0);
	if ((ft_result = ft_strcmp(str1, str2)) != (libc_result = strcmp(str1, str2)))
	{
		strcmp_printout(str1, str2);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
	}
	free(str1);
	free(str2);
}

static void	strcmp_same_len(size_t max_len_pre, size_t max_len_post)
{
	size_t len_pre = randi(max_len_pre);
	size_t len_post = randi(max_len_post);
	char *str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	if ((ft_result = ft_strcmp(str1, str2)) != (libc_result = strcmp(str1, str2)))
	{
		strcmp_printout(str1, str2);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
	}
	free(str1);
	free(str2);
}

static void strcmp_diff_len(size_t max_len)
{
	size_t len = randi(max_len);
	char *str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len + 1));
	str2 = (char *) malloc (sizeof(char) * (len + 1));
	rand_substrs(str1, str2, len, 0);
	if (randi(2) == 0)
		*(str1 + randi(len)) = '\0';
	else
		*(str2 + randi(len)) = '\0';
	if ((ft_result = ft_strcmp(str1, str2)) != (libc_result = strcmp(str1, str2)))
	{
		strcmp_printout(str1, str2);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
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
	strcmp_same(0);
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
		strcmp_diff_len(100);
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
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len_pre + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + 1));
	rand_substrs(str1, str2, len_pre, 0);
	if ((ft_result = ft_strncmp(str1, str2, n)) != (libc_result = strncmp(str1, str2, n)))
	{
		strncmp_printout(str1, str2, n);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
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
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	str2 = (char *) malloc (sizeof(char) * (len_pre + len_post + 1));
	rand_substrs(str1, str2, len_pre, len_post);
	if ((ft_result = ft_strncmp(str1, str2, n)) != (libc_result = strncmp(str1, str2, n)))
	{
		strncmp_printout(str1, str2, n);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
	}
	free(str1);
	free(str2);
}

static void strncmp_diff_len(size_t max_len)
{
	size_t	len = randi(max_len);
	size_t	n = randi(len);
	char	*str1, *str2;
	int	ft_result, libc_result;

	str1 = (char *) malloc (sizeof(char) * (len + 1));
	str2 = (char *) malloc (sizeof(char) * (len + 1));
	rand_substrs(str1, str2, len, 0);
	if (randi(2) == 0)
		*(str1 + randi(len)) = '\0';
	else
		*(str2 + randi(len)) = '\0';
	if ((ft_result = ft_strncmp(str1, str2, n)) != (libc_result = strncmp(str1, str2, n)))
	{
		strncmp_printout(str1, str2, n);
		if (signtest(ft_result, libc_result))
			printf("same sign though, continuing\n");
		else abort();
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
		strncmp_diff_len(100);
		i++;
	}
}

void	valid_atoi(size_t max_spaces, size_t i)
{
	size_t	spaces = randi(max_spaces) + 1;
	char	*str, *s1;
	int		n = randi(INT_MAX);

	str = (char *) malloc(sizeof(char) * (spaces + 12));
	s1 = str;
	while (spaces)
	{
		if (randi(2))
			*s1++ = (char) (randi(5) + 9);
		else
			*s1++ = ' ';
		spaces--;
	}
	if (randi(10) > 6)
	{
		if (randi(2))
			*s1++ = '-';
		else
			*s1++ = '+';
	}
	sprintf(s1, "%d", n);
	*(s1 + randi(strlen(s1))) = rand_char();
	if (ft_atoi(str) != atoi(str))
	{
		printf("test #%zu failed\nstr: [%s]\ngot %d, expected %d\n", 
				i, str, ft_atoi(str), atoi(str));
		abort();
	}
	free(str);
}

void	bad_atoi(size_t max_spaces, size_t i)
{
	size_t	spaces = randi(max_spaces) + 1;
	size_t	len = spaces + 20;
	char	*str, *s1;
	int		n = randi(INT_MAX);

	str = (char *) malloc(sizeof(char) * (len));
	bzero(str, len);
	s1 = str;
	while (spaces > randi(4))
	{
		if (randi(3))
			*s1++ = ' ';
		else
			*s1++ = (char) randi(14);
		spaces--;
	}
	while (spaces > 0)
	{
		if (randi(2))
			*s1++ = '-';
		else
			*s1++ = '+';
		spaces--;
	}
	sprintf(s1, "%d", n);
	while (randi(4))
		*(str + randi(strlen(str))) = rand_char();
	if (ft_atoi(str) != atoi(str))
	{
		printf("test #%zu failed\nstr: [%s]\ngot %d, expected %d\n", 
				i, str, ft_atoi(str), atoi(str));
		abort();
	}
	free(str);
}

void	test_atoi(void)
{
	size_t	tests = 100, max_spaces = 10, i = 0;
	char	str1[] = " 42";
	char	str2[] = " -42";
	char	str3[] = " 0";
	char	str4[] = " 2147483647";
	char	str5[] = " -2147483648";

	printf("...ft_atoi\n");
	valid_atoi(10, 0);
	printf("testing easy strings\n");
	printf("%d\n%d\n%d\n%d\n%d\n", ft_atoi(str1), ft_atoi(str2), ft_atoi(str3), ft_atoi(str4), ft_atoi(str5));
	assert(ft_atoi(str1) == atoi(str1));
	assert(ft_atoi(str2) == atoi(str2));
	assert(ft_atoi(str3) == atoi(str3));
	assert(ft_atoi(str4) == atoi(str4));
	assert(ft_atoi(str5) == atoi(str5));
	printf("testing valid strings\n");
	while (i < tests)
		valid_atoi(max_spaces, i++);
	printf("testing bad strings\n");
	i = 0;
	while (i < tests)
		bad_atoi(max_spaces, i++);
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
