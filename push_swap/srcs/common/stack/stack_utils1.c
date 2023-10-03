/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:35 by malatini          #+#    #+#             */
/*   Updated: 2021/06/13 17:09:54 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

/* Cherche un doublon sur les petites suites */
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

/* Détermine si la stack est triée ou pas */
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
