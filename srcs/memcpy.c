/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/26 12:28:44 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	memset(str2, 'b', 50);
	ft_memcpy(str2, str, 10);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}
static char	*compare1()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	memset(str2, 'b', 50);
	memcpy(str2, str, 10);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}

static char	*test2()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	str[5] = '\0';
	memset(str2, 'b', 50);
	ft_memcpy(str2, str, 10);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}
static char	*compare2()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	str[5] = '\0';
	memset(str2, 'b', 50);
	memcpy(str2, str, 10);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}

static char	*test3()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	memset(str2, 'b', 50);
	ft_memcpy(str2, str, 0);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}
static char	*compare3()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	memset(str2, 'b', 50);
	memcpy(str2, str, 0);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}

static char	*test4()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	memset(str2, 'b', 50);
	ft_memcpy(str2, str, 50);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}
static char	*compare4()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	memset(str2, 'b', 50);
	memcpy(str2, str, 50);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}

static char	*test5()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	str[0] = '\0';
	memset(str2, 'b', 50);
	ft_memcpy(str2, str, 1);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}
static char	*compare5()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 50);
	char	*str3 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	str[0] = '\0';
	memset(str2, 'b', 50);
	memcpy(str2, str, 1);
	for(int i = 0; i < 50; i++)
	{
		if(str2[i] == 0)
			str3[i] = '0';
		else
			str3[i] = str2[i];
	}
	str3[50] = '\0';
	return str3;
}

t_tests_list	*memcpy_list()
{
	t_tests_list	*list = init_tests_list("Memcpy");
	add_test(list, "Classic", "ft_memcpy(str2, str, 10);", FALSE, STR_COMPARE, &test1, &compare1);
	add_test(list, "With \\0 in the copy", "ft_memcpy(str2, str, 10);", FALSE, STR_COMPARE, &test2, &compare2);
	add_test(list, "Don't do anything", "ft_memcpy(str2, str, 0);", FALSE, STR_COMPARE, &test3, &compare3);
	add_test(list, "Fill buffer", "ft_memcpy(str2, str, 50);", FALSE, STR_COMPARE, &test4, &compare4);
	add_test(list, "Only \\0", "ft_memcpy(str2, str, 1);", FALSE, STR_COMPARE, &test5, &compare5);
	return (list);
}