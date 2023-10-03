/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:18:54 by user42            #+#    #+#             */
/*   Updated: 2021/06/14 09:21:51 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

/* Fonction de swap utile pour les différentes actions */
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
}

/* Action SA demandée dans le sujet */
void	sa(t_stack *a, int print_option, t_mem *mem)
{
	if (!a || !mem)
		return ;
	swap_ab(a);
	if (print_option == 1)
		write(1, "sa\n", 3);
	mem->action_count++;
}

/* Action SB demandée dans le sujet */
void	sb(t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem)
		return ;
	swap_ab(b);
	if (print_option == 1)
		write(1, "sb\n", 3);
	mem->action_count++;
}

/* Action SS demandée dans le sujet*/
void	ss(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	if (!a || !b || !mem)
		return ;
	swap_ab(a);
	swap_ab(b);
	if (print_option == 1)
		write(1, "ss\n", 3);
	mem->action_count++;
}
