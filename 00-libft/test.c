#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "libft.h"

# define NBR(x)		printf("%d", x); fflush(0);
# define DONE		printf("..DONE\n");

void print_list(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst) {
		printf("%zu:%p\n", i, lst->content);
		lst = lst->next;
		i++;
	}
	printf("\n");
}

void print_list_elt(void *content)
{
	printf("\t%p\n", content);
}

void *upper_lst(void *content)
{
	size_t	i;
	char	*str;

	str = ft_strdup((char*)content);
	i = 0;
	while(str[i]) {
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	compare_list(char const *fct, t_list *list, char **strs, int limit, int length)
{
	int	i;
	int	correct;

	i = 0;
	correct = 0;
	while ((limit < 0 || i < limit) && i < length && list)
	{
		if (strcmp(list->content, strs[i]))
			printf("%s: Expected `%s` got `%p`\n", fct, strs[i], list->content);
		else
			correct++;
		i++;
		list = list->next;
	}
	if ((limit < 0 && correct == length) || (correct == limit))
		printf("%s: All good\n", fct);
	return (1);
}

// https://opensource.apple.com/source/Libc/Libc-825.25/string/strlcat.c.auto.html
size_t strlcat(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, maxlen);
    if (dstlen == maxlen) return maxlen+srclen;
    if (srclen < maxlen-dstlen) {
        memcpy(dst+dstlen, src, srclen+1);
    } else {
        memcpy(dst+dstlen, src, maxlen-1);
        dst[dstlen+maxlen-1] = '\0';
    }
    return dstlen + srclen;
}

// https://opensource.apple.com/source/Libc/Libc-825.25/string/strlcpy.c.auto.html
size_t strlcpy(char * dst, const char * src, size_t maxlen) {
    const size_t srclen = strlen(src);
    if (srclen < maxlen) {
        memcpy(dst, src, srclen+1);
    } else if (maxlen != 0) {
        memcpy(dst, src, maxlen-1);
        dst[maxlen-1] = '\0';
    }
    return srclen;
}

// https://github.com/lattera/freebsd/blob/master/lib/libc/string/strnstr.c
char *strnstr(const char *s, const char *find, size_t slen) {
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int	min(int a, int b) {
	return ((a < b) ? a : b);
}

int	max(int a, int b) {
	return ((a > b) ? a : b);
}

int	same_sign(int a, int b) {
	return ((a < 0 && b < 0) || (a > 0 && b > 0));
}

void test_char_ft(int (*org)(int), int (*ft)(int)) {
	int	i;
	int	ret_o, ret_y;

	printf("[int|unsigned char|expected|yours]\n");
	i = 0;
	while (i < 256) {
		ret_o = (*org)(i);
		ret_y = (*ft)(i);
		if (ret_o == ret_y)
			printf("G");
		else if (same_sign(ret_o, ret_y))
			printf("g");
		else
			printf("[%d|%c|%d|%d]", i, i, ret_o, ret_y);
		i++;
	}
	printf("\n");
}

char strupper_and_one(unsigned int idx, char c) {
	if (idx == 0) {
		return ('1');
	}
	return (ft_toupper(c));
}

int	_c_in_set(char c, char const *set) {
	int	i;

	i = 0;
	while (set[i])
		if ((unsigned char)set[i++] == (unsigned char)c)
			return (1);
	return (0);
}

int main(int argc, char const *argv[]) {
	int	j;
	(void) argc;
	(void) argv;

	/*
	atoi
	*/
	printf("---atoi---[string|atoi|yours]\n");

	int i = 1;
	while (i < argc) {
		if (atoi(argv[i]) == ft_atoi((char*) argv[i])) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], atoi(argv[i]), ft_atoi((char*) argv[i]));
		}
		i++;
	}
	printf("\n");

	/*
	bzero
	*/
	printf("\n---bzero---[string|length]\n");

	char *str_bzero_org = NULL;
	char *str_bzero_ft = NULL;
	int	min_length;

	i = 0;
	while (i < argc) {
		str_bzero_org = strdup(argv[i]);
		str_bzero_ft = strdup(argv[i]);
		min_length = min(strlen(argv[i]), 5);
		bzero(str_bzero_org, min_length);
		ft_bzero((void*)str_bzero_ft, min_length);
		if (memcmp(str_bzero_org, str_bzero_ft, min_length) == 0)
			printf("G");
		else
			printf("[%s|%d]", argv[i], min_length);
		free(str_bzero_org);
		free(str_bzero_ft);
		i++;
	}
	printf("\n");

	/*
	calloc
	*/
	printf("\n---calloc---[string|checked|length]\n");

	char	*str_calloc = NULL;
	int		length = 0;

	i = 0;
	while (i < argc) {
		length = strlen(argv[i]) + 1;
		str_calloc = (char*)ft_calloc(length, sizeof(*str_calloc));
		if (str_calloc)
		{
			j = 0;
			while (j < length)
				if (str_calloc[j++])
					break ;
			if (j == length)
				printf("G");
			else
				printf("[content:%s:%d/%d]", argv[i], j, length);
			free(str_calloc);
		}
		else
			printf("[malloc:%s:%d]", argv[i], length);
		str_calloc = NULL;
		i++;
	}
	printf("\n");

	/*
	is_
	*/

	printf("\n---isalnum---");
	test_char_ft(&isalnum, &ft_isalnum);

	printf("\n---isalpha---");
	test_char_ft(&isalpha, &ft_isalpha);

	printf("\n---isascii---");
	test_char_ft(&isascii, &ft_isascii);

	printf("\n---isdigit---");
	test_char_ft(&isdigit, &ft_isdigit);

	printf("\n---isprint---");
	test_char_ft(&isprint, &ft_isprint);

	/*
	itoa
	*/
	printf("\n---itoa---[number|sprintf|yours]\n");

	long	test_itoa[50] = { 0, 1, -1, 12, 21, -21, -12, 2147483999, -2147483999, 123456, -123456, 2147483648, -2147483648, 2147483647, -2147483647 };
	i = 0;
	char *str_itoa = NULL;
	char str2[50] = "";
	while (i < 50) {
		sprintf(str2, "%d", (int)test_itoa[i]);
		str_itoa = ft_itoa((int)test_itoa[i]);
		if (strcmp(str2, str_itoa) == 0) {
			printf("G");
		} else {
			printf("[%d|%s|%s]", (int)test_itoa[i], str2, str_itoa);
		}
		i++;
		free(str_itoa);
	}
	printf("\n");

	/*
	memccpy
	*/
	printf("\n---memccpy---[string|memccpy|yours]\n");

	int memccpy_length = 0;
	char	str_dest[250] = "";
	char	str_ft_dest[250] = "";
	i = 0;
	while (i < argc) {
		memccpy_length = strlen(argv[i]);
		memccpy(str_dest, argv[i], 'c', memccpy_length);
		ft_memccpy(str_ft_dest, argv[i], 'c', memccpy_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	memchr
	*/
	printf("\n---memchr---[string|memchr|yours]\n");

	i = 0;
	while (i < argc) {
		if (memchr(argv[i], 'c', 50) == ft_memchr(argv[i], 'c', 50)) {
			printf("G");
		} else {
			printf("[%s|%p|%p]", argv[i], memchr(argv[i], 'c', 50), ft_memchr(argv[i], 'c', 50));
		}
		i++;
	}
	printf("\n");

	/*
	memcmp
	*/
	printf("\n---memcmp---[string|comparison|memcmp|yours]\n");

	i = 0;
	while (i < argc) {
		if (memcmp(argv[i], argv[i], 50) == ft_memcmp(argv[i], argv[i], 50)) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], memcmp(argv[i], argv[i], 50), ft_memcmp(argv[i], argv[i], 50));
		}
		if (memcmp(argv[i], argv[argc - 1], 50) == ft_memcmp(argv[i], argv[argc - 1], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%d|%d]", argv[i], argv[argc - 1], memcmp(argv[i], argv[argc - 1], 50), ft_memcmp(argv[i], argv[argc - 1], 50));
		}
		i++;
	}
	printf("\n");

	/*
	memcpy
	*/
	printf("\n---memcpy---[string|memcpy|yours]\n");

	int memcpy_length = 0;
	i = 0;
	while (i < argc) {
		memcpy_length = strlen(argv[i]);
		memcpy(str_dest, argv[i], memcpy_length);
		ft_memcpy(str_ft_dest, argv[i], memcpy_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	memmove
	*/
	printf("\n---memmove---[string|memmove|yours]\n");

	int memmove_length = 0;
	i = 0;
	while (i < argc) {
		memmove_length = strlen(argv[i]);
		memmove(str_dest, argv[i], memmove_length);
		ft_memmove(str_ft_dest, argv[i], memmove_length);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	memset
	*/
	printf("\n---memset---[char|memset|yours]\n");

	i = 0;
	while (i < argc) {
		memset(str_dest, argv[i][0], 50);
		ft_memset(str_ft_dest, argv[i][0], 50);
		if (strcmp(str_dest, str_ft_dest) == 0) {
			printf("G");
		} else {
			printf("[%c|%s|%s]", argv[i][0], str_dest, str_ft_dest);
		}
		i++;
	}
	printf("\n");

	/*
	split
	*/
	printf("\n---split (`e.wu-+ `)---[char|string][length|split_length|sep_count|string]\n");

	char to_split[10] = {'e', '.', 'w', 'u', '-', '+', ' ', '0', '2', '1'};
	char **splitted = NULL;
	int	k, l;
	int	out_length, total_length, sep_count;

	i = 0;
	while (i < argc) {
		k = 0;
		while (k < (int)sizeof(to_split))
		{
			splitted = ft_split(argv[i], to_split[k]);
			if (splitted)
			{
				out_length = strlen(argv[i]);
				sep_count = 0;
				l = 0;
				while (argv[i][l])
					if (argv[i][l++] == to_split[k])
						sep_count++;
				total_length = 0;
				j = 0;
				while (splitted[j])
				{
					total_length += strlen(splitted[j]);
					if (strchr(splitted[j], to_split[k]))
						printf("[remaining:%c|%s]", to_split[k], splitted[j]);
					else
						printf("G");
					free(splitted[j]);
					j++;
				}
				free(splitted);
				if (out_length != (total_length + sep_count))
					printf("[missing:%d|%d|%d|%s]", out_length, total_length, sep_count, argv[i]);
				else
					printf("G");
			}
			else
				printf("[malloc:%s]", argv[i]);
			k++;
		}
		i++;
	}
	printf("\n");

	/*
	strchr
	*/
	printf("\n---strchr---[string|strchr|yours]\n");

	i = 0;
	while (i < argc) {
		if (strchr(argv[i], 'c') == ft_strchr(argv[i], 'c')) {
			printf("G");
		} else {
			printf("[%s|%p|%p]", argv[i], strchr(argv[i], 'c'), ft_strchr(argv[i], 'c'));
		}
		i++;
	}
	printf("\n");

	/*
	strdup
	*/
	printf("\n---strdup---[string|strdup|yours]\n");

	char	*str_dup_org = NULL;
	char	*str_dup_ft = NULL;
	i = 0;
	while (i < argc) {
		str_dup_org = strdup(argv[i]);
		str_dup_ft = ft_strdup(argv[i]);
		if (strcmp(str_dup_org, str_dup_ft) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_dup_org, str_dup_ft);
		}
		free(str_dup_org);
		free(str_dup_ft);
		i++;
	}
	printf("\n");

	/*
	strjoin
	*/
	printf("\n---strjoin---[string|asprintf|yours]\n");

	char	str_join_org[1024];
	char	*str_join_ft = NULL;
	i = 0;
	while (i < argc) {
		sprintf(str_join_org, "%s%s", argv[i], argv[0]);
		str_join_ft = ft_strjoin(argv[i], argv[0]);
		if (strcmp(str_join_org, str_join_ft) == 0) {
			printf("G");
		} else {
			printf("[%s%s|%s|%s]", argv[i], argv[0], str_join_org, str_join_ft);
		}
		free(str_join_ft);
		i++;
	}
	printf("\n");

	/*
	strlcat
	*/
	printf("\n---strlcat---[string|strlcat|yours]\n");
	printf("\n---Unreliable results...\n");

	char str_lcat_org[2550] = "";
	int res_org = 0;
	char str_lcat_ft[2550] = "";
	int res_ft = 0;

	i = 0;
	while (i < argc) {
		res_org = strlcat(str_lcat_org, argv[i], 5);
		res_ft = ft_strlcat(str_lcat_ft, argv[i], 5);
		if (strcmp(str_lcat_org, str_lcat_ft) == 0) {
			printf("G");
		} else {
			printf("[bad copy|%s|%s|%s]", argv[i], str_lcat_org, str_lcat_ft);
		}
		if (res_org == res_ft) {
			printf("G");
		} else {
			printf("[bad return|%s|%d|%d]", argv[i], res_org, res_ft);
		}
		i++;
	}
	printf("\n");

	/*
	strlcpy
	*/
	printf("\n---strlcpy---[string|strlcpy|yours]\n");

	char str_lcpy_org[2550] = "";
	char str_lcpy_ft[2550] = "";

	i = 0;
	while (i < argc) {
		res_org = strlcpy(str_lcpy_org, argv[i], 5);
		res_ft = ft_strlcpy(str_lcpy_ft, argv[i], 5);
		if (strcmp(str_lcpy_org, str_lcpy_ft) == 0) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], str_join_org, str_join_ft);
		}
		if (res_org == res_ft) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], res_org, res_ft);
		}
		i++;
	}
	printf("\n");

	/*
	strlen
	*/
	printf("\n---strlen---[string|strlen|yours]\n");

	i = 0;
	while (i < argc) {
		if (strlen(argv[i]) == ft_strlen(argv[i])) {
			printf("G");
		} else {
			printf("[%s|%zu|%zu]", argv[i], strlen(argv[i]), ft_strlen(argv[i]));
		}
		i++;
	}
	printf("\n");

	/*
	strmapi
	*/
	printf("\n---strmapi---[string|yours]\n");

	char *str_mapi_ft = NULL;
	int all_upper;

	i = 0;
	while (i < argc) {
		str_mapi_ft = ft_strmapi(argv[i], &strupper_and_one);
		all_upper = 1;
		j = 0;
		while (str_mapi_ft[j])
		{
			if (islower(str_mapi_ft[j++]))
			{
				all_upper = 0;
				break ;
			}
		}
		if ((str_mapi_ft[0] == '1' || strlen(str_mapi_ft) == 0) && all_upper)
			printf("G");
		else
			printf("[%s|%s]", argv[i], str_mapi_ft);
		i++;
	}
	printf("\n");

	/*
	strncmp
	*/
	printf("\n---strncmp---[string|strncmp|yours]\n");
	int	ncmp_ret;
	int	nft_cmp_ret;

	i = 0;
	while (i < argc) {
		ncmp_ret = strncmp(argv[i], argv[i], 50);
		nft_cmp_ret = ft_strncmp(argv[i], argv[i], 50);
		if (ncmp_ret == nft_cmp_ret || same_sign(ncmp_ret, nft_cmp_ret)) {
			printf("G");
		} else {
			printf("[%s|%d|%d]", argv[i], ncmp_ret, nft_cmp_ret);
		}

		ncmp_ret = strncmp(argv[i], argv[argc - 1], 50);
		nft_cmp_ret = ft_strncmp(argv[i], argv[argc - 1], 50);
		if (ncmp_ret == nft_cmp_ret || same_sign(ncmp_ret, nft_cmp_ret)) {
			printf("G");
		} else {
			printf("[%s|%s|%d|%d]", argv[i], argv[argc - 1], ncmp_ret, nft_cmp_ret);
		}
		i++;
	}
	printf("\n");

	/*
	strnstr
	*/
	printf("\n---strnstr---[string|strnstr|yours]\n");

	i = 0;
	while (i < argc) {
		if (strnstr(argv[i], argv[i], 50) == ft_strnstr(argv[i], argv[i], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%s]", argv[i], strnstr(argv[i], argv[i], 50), ft_strnstr(argv[i], argv[i], 50));
		}
		if (strnstr(argv[i], argv[argc - 1], 50) == ft_strnstr(argv[i], argv[argc - 1], 50)) {
			printf("G");
		} else {
			printf("[%s|%s|%s|%s]", argv[i], argv[argc - 1], strnstr(argv[i], argv[argc - 1], 50), ft_strnstr(argv[i], argv[argc - 1], 50));
		}
		if (strnstr(argv[i], "e", 50) == ft_strnstr(argv[i], "e", 50)) {
			printf("G");
		} else {
			printf("[%s|e|%s|%s]", argv[i], strnstr(argv[i], argv[argc - 1], 50), ft_strnstr(argv[i], argv[argc - 1], 50));
		}
		if (strnstr(argv[i], "e", 0) == ft_strnstr(argv[i], "e", 0)) {
			printf("G");
		} else {
			printf("[%s|e|%s|%s]", argv[i], strnstr(argv[i], argv[argc - 1], 50), ft_strnstr(argv[i], argv[argc - 1], 50));
		}
		i++;
	}
	printf("\n");

	/*
	strrchr
	*/
	printf("\n---strrchr---[string|strrchr|yours]\n");

	i = 0;
	while (i < argc) {
		if (strrchr(argv[i], 'c') == ft_strrchr(argv[i], 'c')) {
			printf("G");
		} else {
			printf("[%s|%p|%p]", argv[i], strrchr(argv[i], 'c'), ft_strrchr(argv[i], 'c'));
		}
		i++;
	}
	printf("\n");

	/*
	strtrim
	*/
	printf("\n---strtrim (` .+-e`)---[where|string|yours]\n");

	char set[10] = " .+-e103*";
	char *str_trim = NULL;

	i = 0;
	while (i < argc) {
		str_trim = ft_strtrim(argv[i], " .+-e10");
		if (str_trim)
		{
			j = 0;
			while (argv[i][j] && _c_in_set(argv[i][j], set))
				j++;
			if (argv[i][j] == str_trim[0])
				printf("G");
			else
				printf("[start:%s|%s]", argv[i], str_trim);

			j = max(0, strlen(argv[i]) - 1);
			while (j >= 0 && _c_in_set(argv[i][j], set))
				j--;
			if (argv[i][j] == str_trim[max(0, strlen(str_trim) - 1)])
				printf("G");
			else
				printf("[end:%s|%s]", argv[i], str_trim);
			free(str_trim);
		}
		else
			printf("[malloc:%s]", argv[i]);
		i++;
	}
	char tmp_set[2];
	tmp_set[1] = 0;
	int set_ct = 0;
	while (set_ct < (int)sizeof(set))
	{
		tmp_set[0] = set[set_ct];
		i = 0;
		while (i < argc)
		{
			str_trim = ft_strtrim(argv[i], tmp_set);
			if (str_trim)
			{
				j = 0;
				while (argv[i][j] && _c_in_set(argv[i][j], tmp_set))
					j++;
				if (argv[i][j] == str_trim[0])
					printf("G");
				else
					printf("[start:%s|%s]", argv[i], str_trim);

				j = max(0, strlen(argv[i]) - 1);
				while (j >= 0 && _c_in_set(argv[i][j], tmp_set))
					j--;
				if (argv[i][j] == str_trim[max(0, strlen(str_trim) - 1)])
					printf("G");
				else
					printf("[end:%s|%s]", argv[i], str_trim);
				free(str_trim);
				i++;
			}
			else
				printf("[malloc:%s]", argv[i]);
			i++;
		}
		set_ct++;
	}
	printf("\n");

	/*
	substr
	*/
	printf("\n---substr---[original|yours|strncpy|start|length]\n");

	char *str_substr = NULL;
	char *str_substr_org = NULL;
	int argv_length;

	str_substr_org = (char*)malloc(sizeof(*str_substr_org) * 500);
	i = 0;
	while (i < argc) {
		argv_length = strlen(argv[i]);
		min_length = min(argv_length, 5);
		str_substr = ft_substr(argv[i], 0, min_length);
		strncpy(str_substr_org, argv[i], min_length);
		str_substr_org[min_length] = 0;
		if (strcmp(str_substr, str_substr_org) == 0)
			printf("G");
		else
			printf("[%s|%s|%s|0|%d]", argv[i], str_substr, str_substr_org, min_length);
		free(str_substr);
		if (min_length > 5)
		{
			min_length = min(argv_length, 10);
			str_substr = ft_substr(argv[i], 5, min_length);
			strncpy(str_substr_org, argv[i] + 5, min_length);
			str_substr_org[5 + min_length] = 0;
			if (strcmp(str_substr, str_substr_org) == 0)
				printf("G");
			else
				printf("[%s|%s|%s|5|%d]", argv[i], str_substr, str_substr_org, min_length);
			free(str_substr);
		}
		i++;
	}
	free(str_substr_org);
	printf("\n");

	/*
	to_
	*/
	printf("\n---tolower---");
	test_char_ft(&tolower, &ft_tolower);

	printf("\n---toupper---");
	test_char_ft(&toupper, &ft_toupper);

	char	*strs[3];
	char	*upper[3];

	(void) argc;
	(void) argv;

	printf("---Bonus---\n\n");

	strs[0] = strdup("opppoppop");
	strs[1] = strdup("okokokok");
	strs[2] = strdup("wqqwqwwqqw");

	upper[0] = strdup("OPPPOPPOP");
	upper[1] = strdup("OKOKOKOK");
	upper[2] = strdup("WQQWQWWQQW");

	t_list *first = ft_lstnew(strs[1]);
	t_list **list = &first;

	compare_list("ft_lstnew", first, strs + 1, 1, 3);
	if (first->next)
		printf("ft_lstnew: Invalid next element !\n");

	ft_lstadd_back(list, ft_lstnew(strs[2]));
	compare_list("ft_lstadd_back", first, strs + 1, 2, 3);

	ft_lstadd_front(list, ft_lstnew(strs[0]));
	compare_list("ft_lstadd_front", first, strs, 3, 3);

	i = ft_lstsize(*list);
	if (i == 3)
		printf("ft_lstsize: All good\n");
	else
		printf("ft_lstsize: Expected `%d` got `%d`\n", 3, i);

	t_list	*last = ft_lstlast(*list);
	if (!last)
		printf("ft_lstlast: Returned nothing !\n");
	else
	{
		if (strcmp(last->content, strs[2]))
			printf("ft_lstlast: Expected `%p` got `%s`\n", last->content, strs[2]);
		else
			printf("ft_lstlast: All good\n");
	}

	printf("ft_lstiter:\n");
	ft_lstiter(*list, &print_list_elt);

	t_list	*list_copy = ft_lstmap(first, &upper_lst, &free);
	compare_list("ft_lstmap", list_copy, upper, 3, 3);

	printf("ft_lstclear: ");
	ft_lstclear(list, &free);
	ft_lstclear(&list_copy, &free);
	printf("All good\n");

	t_list *empty = NULL;

	strs[0] = strdup("opppoppop");
	ft_lstadd_front(&empty, ft_lstnew(strs[0]));
	compare_list("ft_lstadd_front (empty)", empty, strs, 1, 3);
	ft_lstclear(&empty, &free);

	strs[0] = strdup("opppoppop");
	ft_lstadd_back(&empty, ft_lstnew(strs[0]));
	compare_list("ft_lstadd_back (empty)", empty, strs, 1, 3);
	ft_lstclear(&empty, &free);

	printf("\nSeg. fault tests (?)\n");
	printf(":lst_addback\n"); NBR(1)
	ft_lstadd_back(NULL, NULL); NBR(2)
	ft_lstadd_back(&empty, NULL); DONE

	printf(":lst_addfront\n"); NBR(1)
	ft_lstadd_front(NULL, NULL); NBR(2)
	ft_lstadd_front(&empty, NULL); DONE

	printf(":lstclear\n"); NBR(1)
	ft_lstclear(NULL, NULL); NBR(2)
	ft_lstclear(&empty, NULL); NBR(3)
	ft_lstclear(&empty, NULL); NBR(4)
	ft_lstclear(&empty, &free); DONE

	printf(":lstdelone\n"); NBR(1)
	ft_lstdelone(NULL, NULL); NBR(2)
	ft_lstdelone(NULL, &free); NBR(3)
	ft_lstdelone(empty, NULL); DONE

	printf(":lstiter\n"); NBR(1)
	ft_lstiter(NULL, NULL); NBR(2)
	ft_lstiter(NULL, &print_list_elt); NBR(3)
	ft_lstiter(empty, NULL); NBR(4)
	ft_lstiter(empty, &print_list_elt); DONE

	printf(":lstlast\n"); NBR(1)
	ft_lstlast(NULL); NBR(2)
	ft_lstlast(empty); DONE

	printf(":lstmap\n"); NBR(1)
	ft_lstmap(NULL, NULL, NULL); NBR(2)
	ft_lstmap(NULL, NULL, &free); NBR(3)
	ft_lstmap(NULL, &upper_lst, NULL); NBR(4)
	ft_lstmap(NULL, &upper_lst, &free); NBR(5)
	ft_lstmap(empty, NULL, NULL); NBR(6)
	ft_lstmap(empty, &upper_lst, NULL); NBR(7)
	ft_lstmap(empty, &upper_lst, &free); DONE
	return (0);
}
