/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:24:15 by user42            #+#    #+#             */
/*   Updated: 2023/10/13 15:08:03 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	reverse_rotate(t_stack *sta)
{
	t_s_elem	*prev;
	t_s_elem	*elem;

	if (!sta->first || !sta->first->next || !sta)
		return ;
	elem = sta->first;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = sta->first;
	sta->first = elem;
	prev->next = NULL;
	return ;
}

void	rra(t_stack *a, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	if (print_option == 1)
		write(1, "rra\n", 4);
	mem->action_count++;
	return ;
}

void	rrb(t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrb\n", 4);
	mem->action_count++;
	return ;
}

void	rrr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrr\n", 4);
	mem->action_count--;
	return ;
}
