/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:42:37 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 21:43:22 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void	too_short_strnstr(void)
{
	char	s1[] = "12345needle23456";
	char	s2[] = "needle";

	for (size_t i = 0; i < 11; i++)
	{
		char *p1 = strnstr(s1, s2, i), *p2 = ft_strnstr(s1, s2, i);
		if (p1 != p2)
		{
			printf("failed when needle is not fully covered by len (n=%zu)\n", i);
			printf("s1=[%s]\nlibc:\t%p\nlibft\t%p\n", s1, p1, p2);
			abort();
		}
	}
}

static void partial_strnstr(void)
{
	char	needle[] = "needle";
	size_t	nee_len = strlen(needle);
	char	*libc, *libft;

	for (size_t i = 0; i < nee_len; i++)
	{
		char	haystack[] = "01234567890123456789";
		size_t	start = randi(10);
		
		memcpy(haystack + start, needle, nee_len);
		memcpy(haystack + start + i, needle, nee_len);
		libc = strnstr(haystack, needle, start + nee_len + i);
		libft = ft_strnstr(haystack, needle, start + nee_len + i);
		if (libc != libft)
		{
			printf("test #%zu failed (n=%zu)\nhystck:\t[%s]\nneedle:\t[%s]\n",
					i, start + nee_len + i, haystack, needle);
			printf("libc:\t[%s]\t%p\nlibft:\t[%s]\t%p\n", libc, libc, libft, libft);
			abort();
		}
	}
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
	printf("seeking needle when n is too short for full match\n");
	too_short_strnstr();
	printf("seeking needle when partial match present\n");
	partial_strnstr();
	printf("seeking present needle\n");
	while (i < tests)
		found_strnstr(40, 8, i++);
	i = 0;
	printf("seeking missing needle\n");
	while (i < tests)
		not_found_strnstr(50, 15, i++);
}
