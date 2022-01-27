/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:15:40 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/27 11:01:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static char	*test1()
{
	t_stdout *stdout = init_stdout_test();
	ft_putstr_fd("Hello World !", 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test2()
{
	t_stdout *stdout = init_stdout_test();
	ft_putstr_fd("", 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test3()
{
	t_stdout *stdout = init_stdout_test();
	ft_putstr_fd("\n", 1);
	end_stdout_test(stdout);
	return stdout->output;
}
static char	*test4()
{
	t_stdout *stdout = init_stdout_test();
	ft_putstr_fd("Salut a tous ! Comment ca va la ?\n", 1);
	end_stdout_test(stdout);
	return stdout->output;
}

t_tests_list	*putstr_list()
{
	t_tests_list	*list = init_tests_list("Putstr");
	add_test(list, "Basic", "ft_putstr_fd(\"Hello World !\", 1);", FALSE, STR_VALUE, &test1, "Hello World !");
	add_test(list, "Empty string", "ft_putstr_fd(\"\", 1);", FALSE, STR_VALUE, &test2, "");
	add_test(list, "Just \\n", "ft_putstr_fd(\"\\n\", 1);", FALSE, STR_VALUE, &test3, "\n");
	add_test(list, "Long text", "ft_putstr_fd(\"Salut a tous ! Comment ca va la ?\\n\", 1);", FALSE, STR_VALUE, &test4, "Salut a tous ! Comment ca va la ?\n");
	return (list);
}