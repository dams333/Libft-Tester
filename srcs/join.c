/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:42:00 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 10:52:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	return ft_strjoin("Hello", "World");
}

static char	*test2()
{
	return ft_strjoin("", "");
}

static char	*test3()
{
	start_malloc_catcher();
	free(ft_strjoin("Hello", "World"));
	stop_malloc_catcher_and_print_leaks();
	return "0";
}

static char	*test4()
{
	start_malloc_catcher();
	start_malloc_breaker();
	free(ft_strjoin("Hello", "World"));
	stop_malloc_breaker();
	stop_malloc_catcher_and_print_leaks();
	return "0";
}

t_tests_list	*join_list()
{
	t_tests_list	*list = init_tests_list("Join");
	add_test(list, "Basic", "ft_strjoin(\"Hello\", \"World\")", FALSE, STR_VALUE, &test1, "HelloWorld");
	add_test(list, "Empty", "ft_strjoin(\"\", \"\")", FALSE, STR_VALUE, &test2, "");
	add_test(list, "Leaks", "ft_strjoin(\"Hello\", \"World\")", FALSE, STR_VALUE, &test3, "0");
	add_test(list, "Malloc", "ft_strjoin(\"Hello\", \"World\") with failed malloc", FALSE, STR_VALUE, &test4, "0");
	return (list);
}