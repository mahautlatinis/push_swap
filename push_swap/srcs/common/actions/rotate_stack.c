/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:51:08 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 15:09:15 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	rotate_stack(t_stack *sta)
{
	t_s_elem	*last;
	t_s_elem	*tmp;

	if (!sta)
		return ;
	last = last_element(sta);
	tmp = sta->first;
	sta->first = sta->first->next;
	tmp->next = NULL;
	last->next = tmp;
	return ;
}

void	ra(t_stack *a, int print_option, t_mem *mem)
{
	if (!a || !mem)
		return ;
	rotate_stack(a);
	if (print_option == 1)
		write(1, "ra\n", 3);
	mem->action_count++;
	return ;
}

void	rb(t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem)
		return ;
	rotate_stack(b);
	if (print_option == 1)
		write(1, "rb\n", 3);
	mem->action_count++;
	return ;
}

void	rr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem || !a)
		return ;
	rotate_stack(a);
	rotate_stack(b);
	if (print_option == 1)
		write(1, "rr\n", 3);
	mem->action_count++;
	return ;
}

t_s_elem	*last_element(t_stack *sta)
{
	t_s_elem	*elem;

	if (!sta || !sta->first)
		return (NULL);
	elem = sta->first;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
