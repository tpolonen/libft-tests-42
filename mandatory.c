/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:31:23 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/05 15:58:25 by tpolonen         ###   ########.fr       */
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

void	rand_strcmp(size_t min_len, size_t same_chars, size_t variance)
{
	char	*str1;
	char	*str2;
	size_t 	cur_len = min_len + (arc4random() % variance);
	size_t	cur_same_chars = same_chars + (arc4random() % variance);

	rand_substrs(&str1, &str2, cur_same_chars, cur_len - cur_same_chars);
	if (ft_strcmp(str1, str2) != strcmp(str1, str2))
	{
		printf("failed for [%s] vs [%s]\n", str1, str2);
		abort();
	}
	free(str1);
	free(str2);
}	

void	test_strcmp(void)
{
	int		tests = 100;
	size_t	min_len = 50;
	size_t	same_chars = 12;
	size_t	variance = 8;
		
	printf("...ft_strcmp\n");
	while (tests > 0)
	{
		rand_strcmp(min_len, same_chars, variance);
		tests--;
	}
}

void	test_strncmp(void)
{

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
