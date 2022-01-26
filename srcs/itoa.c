/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/26 14:26:39 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	return ft_itoa(0);
}
static char	*test2()
{
	return ft_itoa(42);
}
static char	*test3()
{
	return ft_itoa(-42);
}
static char	*test4()
{
	return ft_itoa(2147483647);
}
static char	*test5()
{
	return ft_itoa(-2147483648);
}
static char	*test6()
{
	start_malloc_catcher();
	free(ft_itoa(0));
	stop_malloc_catcher_and_print_leaks();
	return "0";
}
static char	*test7()
{
	start_malloc_catcher();
	start_malloc_breaker();
	free(ft_itoa(0));
	stop_malloc_breaker();
	stop_malloc_catcher();
	return "0";
}

t_tests_list	*itoa_list()
{
	t_tests_list	*list = init_tests_list("Itoa");
	add_test(list, "Zero", "ft_itoa(0)", FALSE, STR_VALUE, &test1, "0");
	add_test(list, "Positive", "ft_itoa(42)", FALSE, STR_VALUE, &test2, "42");
	add_test(list, "Negative", "ft_itoa(-42)", FALSE, STR_VALUE, &test3, "-42");
	add_test(list, "Int max", "ft_itoa(2147483647)", FALSE, STR_VALUE, &test4, "2147483647");
	add_test(list, "Int min", "ft_itoa(-2147483648))", FALSE, STR_VALUE, &test5, "-2147483648");
	add_test(list, "Leaks", "free(ft_itoa(0))", FALSE, STR_VALUE, &test6, "0");
	add_test(list, "Malloc", "ft_itoa(0) with failed malloc", FALSE, STR_VALUE, &test7, "0");
	return (list);
}