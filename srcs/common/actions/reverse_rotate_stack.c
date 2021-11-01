/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:24:15 by user42            #+#    #+#             */
/*   Updated: 2021/06/14 09:11:01 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

/* Fonction de reverse rotate utile pour les différentes actions */
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
}

/* Action RRA demandée dans le sujet */
void	rra(t_stack *a, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	if (print_option == 1)
		write(1, "rra\n", 4);
	mem->action_count++;
}

/* Action RRB demandée dans le sujet*/
void	rrb(t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrb\n", 4);
	mem->action_count++;
}

/* Action RRR demandée dans le sujet */
void	rrr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrr\n", 4);
	mem->action_count--;
}
