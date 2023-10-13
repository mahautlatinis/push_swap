/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:18:54 by user42            #+#    #+#             */
/*   Updated: 2023/10/13 15:09:04 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	swap_ab(t_stack *sta)
{
	t_s_elem	*elem;
	t_s_elem	*second;

	if (!sta)
		return ;
	if (stack_length(sta) >= 2)
	{
		elem = sta->first;
		second = sta->first->next->next;
		sta->first = sta->first->next;
		sta->first->next = elem;
		elem->next = second;
	}
	return ;
}

void	sa(t_stack *a, int print_option, t_mem *mem)
{
	if (!a || !mem)
		return ;
	swap_ab(a);
	if (print_option == 1)
		write(1, "sa\n", 3);
	mem->action_count++;
	return ;
}

void	sb(t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem)
		return ;
	swap_ab(b);
	if (print_option == 1)
		write(1, "sb\n", 3);
	mem->action_count++;
	return ;
}

void	ss(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	if (!a || !b || !mem)
		return ;
	swap_ab(a);
	swap_ab(b);
	if (print_option == 1)
		write(1, "ss\n", 3);
	mem->action_count++;
	return ;
}
