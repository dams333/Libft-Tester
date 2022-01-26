/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:33:57 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/26 14:16:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	main()
{
	t_tester	*tester = init_tester("Libft Tester");
	add_test_list(tester, is_alpha_list());
	add_test_list(tester, is_digit_list());
	add_test_list(tester, is_alnum_list());
	add_test_list(tester, is_ascii_list());
	add_test_list(tester, is_print_list());
	add_test_list(tester, strlen_list());
	add_test_list(tester, memset_list());
	add_test_list(tester, bzero_list());
	add_test_list(tester, memcpy_list());
	add_test_list(tester, atoi_list());
	add_test_list(tester, itoa_list());
	add_test_list(tester, putnbr_list());
	launch_test(tester);
}