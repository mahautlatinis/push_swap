/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:35 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 15:10:27 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

int	find_duplicate_small(t_stack *a)
{
	int			i;
	t_s_elem	*elem;
	t_s_elem	*tmp;

	i = 0;
	tmp = a->first;
	while (tmp->next)
	{
		elem = tmp->next;
		while (elem)
		{
			if (tmp->value == elem->value)
			{
				i++;
				break ;
			}
			elem = elem->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted_stack(t_stack *a)
{
	t_s_elem	*elem;

	elem = a->first;
	while (elem->next)
	{
		if (elem->next->value < elem->value)
			return (ERROR);
		elem = elem->next;
	}
	return (SUCCESS);
}
