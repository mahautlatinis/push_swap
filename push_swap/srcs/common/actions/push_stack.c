/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:35:58 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 15:07:27 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	push_other_stack(t_stack *one, t_stack *two)
{
	t_s_elem	*elem;

	if (is_empty_stack(one))
		return ;
	elem = one->first;
	if (stack_length(one) && stack_length(two))
	{
		one->first = one->first->next;
		elem->next = two->first;
		two->first = elem;
	}
	else if (!(stack_length(two)) && stack_length(one))
	{
		one->first = one->first->next;
		elem->next = NULL;
		two->first = elem;
	}
	return ;
}

void	push_end(t_stack *sta, int x, t_mem *mem)
{
	t_s_elem	*elem;
	t_s_elem	*temp;

	elem = (t_s_elem *)malloc(sizeof(t_s_elem));
	if (!elem)
		error(mem, 1, NULL, NULL);
	elem->value = x;
	if (elem == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	if (!sta->first)
	{
		elem->next = NULL;
		sta->first = elem;
		return ;
	}
	temp = sta->first;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
	return ;
}

void	push_end_plus_origin(t_stack *sta, int x, t_s_elem *ori, t_mem *m)
{
	t_s_elem	*elem;
	t_s_elem	*temp;

	elem = (t_s_elem *)malloc(sizeof(t_s_elem));
	if (!elem)
		error(m, 1, NULL, NULL);
	elem->value = x;
	elem->initial_position = ori;
	if (elem == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	if (!sta->first)
	{
		elem->next = NULL;
		sta->first = elem;
		return ;
	}
	temp = sta->first;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
	return ;
}

void	pa(t_stack *one, t_stack *two, int print_option, t_mem *mem)
{
	if (is_empty_stack(one))
		return ;
	push_other_stack(one, two);
	if (print_option == 1)
		write(1, "pa\n", 3);
	mem->action_count++;
}

void	pb(t_stack *one, t_stack *two, int print_option, t_mem *mem)
{
	if (is_empty_stack(one))
		return ;
	push_other_stack(one, two);
	if (print_option == 1)
		write(1, "pb\n", 3);
	mem->action_count++;
}
