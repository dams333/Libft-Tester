/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/26 12:10:26 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	ft_bzero(str, 10);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}
static char	*compare1()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	bzero(str, 10);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}

static char	*test2()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	ft_bzero(str, 0);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}
static char	*compare2()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	bzero(str, 0);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}

static char	*test3()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	ft_bzero(str, 50);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}
static char	*compare3()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	bzero(str, 50);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}

static char	*test4()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	ft_bzero(str, 1);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}
static char	*compare4()
{
	char	*str = malloc(sizeof(char) * 50);
	char	*str2 = malloc(sizeof(char) * 51);
	memset(str, 'a', 50);
	bzero(str, 1);
	for(int i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			str2[i] = '0';
		else
			str2[i] = '1';
	}
	str2[50] = '\0';
	return str2;
}

t_tests_list	*bzero_list()
{
	t_tests_list	*list = init_tests_list("Bzero");
	add_test(list, "Classic", "ft_bzero(str, 10)", FALSE, STR_COMPARE, &test1, &compare1);
	add_test(list, "Don't do anything", "ft_bzero(str, 0)", FALSE, STR_COMPARE, &test2, &compare2);
	add_test(list, "Fill buffer", "ft_bzero(str, 50)", FALSE, STR_COMPARE, &test3, &compare3);
	add_test(list, "Only one", "ft_bzero(str, 1)", FALSE, STR_COMPARE, &test4, &compare4);
	return (list);
}