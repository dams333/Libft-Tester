/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/26 14:05:40 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	test1()
{
	return ft_atoi("0");
}
int	test2()
{
	return ft_atoi("42");
}
int	test3()
{
	return ft_atoi("-42");
}
int	test4()
{
	return ft_atoi("2147483647");
}
int	test5()
{
	return ft_atoi("-2147483648");
}
int	test6()
{
	return ft_atoi("    \t\t\v  -42");
}
int	test7()
{
	return ft_atoi("    \t\t\v  +42");
}
int	test8()
{
	return ft_atoi("    \t\t\v  +-42");
}
int	test9()
{
	return ft_atoi("    \t\t\v  +42aaa4");
}

t_tests_list	*atoi_list()
{
	t_tests_list	*list = init_tests_list("Atoi");
	add_test(list, "Zero", "ft_atoi(\"0\")", FALSE, INT_VALUE, &test1, 0);
	add_test(list, "Positive", "ft_atoi(\"42\")", FALSE, INT_VALUE, &test2, 42);
	add_test(list, "Negative", "ft_atoi(\"-42\")", FALSE, INT_VALUE, &test3, -42);
	add_test(list, "Int max", "ft_atoi(\"2147483647\")", FALSE, INT_VALUE, &test4, 2147483647);
	add_test(list, "Int min", "ft_atoi(\"-2147483648\")", FALSE, INT_VALUE, &test5, -2147483648);
	add_test(list, "White spaces", "ft_atoi(\"    \\t\\t\\v  -42\")", FALSE, INT_VALUE, &test6, -42);
	add_test(list, "Plus", "ft_atoi(\"    \\t\\t\\v  +42\")", FALSE, INT_VALUE, &test7, 42);
	add_test(list, "Min + and -", "ft_atoi(\"    \\t\\t\\v  +-42\")", FALSE, INT_VALUE, &test8, 0);
	add_test(list, "With non digits", "ft_atoi(\"    \\t\\t\\v  +42aaa4\")", FALSE, INT_VALUE, &test9, 42);
	return (list);
}