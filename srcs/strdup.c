/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:07:34 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 11:13:22 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	char *str = ft_strdup("Hello World !");
	str[0] = 'h';
	return str;
}
static char	*test2()
{
	return ft_strdup("");
}
static char	*test3()
{
	start_malloc_catcher();
	free(ft_strdup("Hello World !"));
	stop_malloc_catcher_and_print_leaks();
	return "0";
}
static char	*test4()
{
	start_malloc_catcher();
	start_malloc_breaker();
	free(ft_strdup("Hello World !"));
	stop_malloc_breaker();
	stop_malloc_catcher_and_print_leaks();
	return "0";
}

t_tests_list	*strdup_list()
{
	t_tests_list	*list = init_tests_list("Strdup");
	add_test(list, "Basic", "ft_strdup(\"Hello World !\"), replacing H ny h", FALSE, STR_VALUE, &test1, "hello World !");
	add_test(list, "Empty string", "ft_strdup(\"\")", FALSE, STR_VALUE, &test2, "");
	add_test(list, "Leaks", "ft_strdup(\"Hello World !\")", FALSE, STR_VALUE, &test3, "0");
	add_test(list, "Malloc", "ft_strdup(\"Hello World !\") with failed malloc", FALSE, STR_VALUE, &test4, "0");
	return (list);
}