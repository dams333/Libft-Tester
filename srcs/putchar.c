/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:15:40 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 11:01:42 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	t_stdout *stdout = init_stdout_test();
	ft_putchar_fd(0, 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test2()
{
	t_stdout *stdout = init_stdout_test();
	ft_putchar_fd('\t', 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test3()
{
	t_stdout *stdout = init_stdout_test();
	ft_putchar_fd('a', 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test4()
{
	t_stdout *stdout = init_stdout_test();
	ft_putchar_fd('~', 1);
	end_stdout_test(stdout);
	return stdout->output;
}

t_tests_list	*putchar_list()
{
	t_tests_list	*list = init_tests_list("Putchar");
	add_test(list, "Zero", "ft_putchar_fd(0, 1);", FALSE, STR_VALUE, &test1, "");
	add_test(list, "Tab", "ft_putchar_fd(\'\\t\', 1);", FALSE, STR_VALUE, &test2, "\t");
	add_test(list, "Alpha", "ft_putchar_fd(\'a\', 1);", FALSE, STR_VALUE, &test3, "a");
	add_test(list, "Tild", "ft_putchar_fd(\'~\', 1);", FALSE, STR_VALUE, &test4, "~");
	return (list);
}