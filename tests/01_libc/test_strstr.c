/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:41:45 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/28 21:42:15 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

static void repeat_strstr(void)
{
	char s1[] = "MZIRIBMZIRIBMZP";
	char s2[] = "MZIRIBMZP";
	char *p1, *p2;

	p1 = strstr(s1, s2);
	p2 = ft_strstr(s1, s2);
	if (p1 != p2)
	{
		printf("failed when partial match for self similar needle present\n");
		printf("haystack\t[%s]\tneedle\t[%s]\n", s1, s2);
		printf("libc\t[%s]\t(%p)\nlibft\t[%s]\t(%p)\n", p1, p1, p2, p2);
		abort();
	}
}

static void partial_strstr(void)
{
	char	needle[] = "needle";
	size_t	nee_len = strlen(needle);
	char	*libc, *libft;

	for (size_t i = 0; i < nee_len; i++)
	{
		char	haystack[] = "01234567890123456789";
		size_t start = randi(10);
		
		memcpy(haystack + start, needle, nee_len);
		memcpy(haystack + start + i, needle, nee_len);
		libc = strstr(haystack, needle);
		libft = ft_strstr(haystack, needle);
		if (libc != libft)
		{
			printf("test #%zu failed\nhystck:\t[%s]\nneedle:\t[%s]\n",
					i, haystack, needle);
			printf("libc:\t[%s]\t%p\nlibft:\t[%s]\t%p\n", libc, libc, libft, libft);
			abort();
		}
	}
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
	repeat_strstr();
	printf("seeking needle when partial match present\n");
	partial_strstr();
	printf("seeking present needle\n");
	while (i < tests)
		found_strstr(30, i++);
	i = 0;
	printf("seeking missing needle\n");
	while (i < tests)
		not_found_strstr(50, i++);

}
