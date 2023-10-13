/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1_target_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:11:07 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 15:12:55 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

t_stack	*cpy_stack(t_stack *sta, t_mem *mem, t_params *params)
{
	t_stack		*cpy;
	t_s_elem	*read;

	if (!sta)
		return (NULL);
	cpy = (t_stack *)malloc(sizeof(t_stack));
	read = sta->first;
	if (!cpy)
		error(mem, 1, &params->min_a, &params->min_b);
	read = sta->first;
	cpy->first = NULL;
	while (read)
	{
		push_end_plus_origin(cpy, read->value, read, mem);
		read = read->next;
	}
	return (cpy);
}

void	bubble_swap(t_s_elem **ori, t_s_elem **tmplst, t_s_elem **elem, int *t)
{
	*t = (*elem)->value;
	*ori = (*elem)->initial_position;
	(*elem)->value = (*tmplst)->value;
	(*elem)->initial_position = (*tmplst)->initial_position;
	(*tmplst)->value = (*t);
	(*tmplst)->initial_position = *ori;
}

t_stack	*bubble_sort_it(t_stack *cpy)
{
	int			temp;
	t_s_elem	*origin;
	t_s_elem	*tmplst;
	t_s_elem	*elem;

	tmplst = cpy->first;
	elem = cpy->first;
	origin = cpy->first->initial_position;
	temp = cpy->first->value;
	while (elem)
	{
		while (tmplst)
		{
			if (elem->value > tmplst->value)
				bubble_swap(&origin, &tmplst, &elem, &temp);
			tmplst = tmplst->next;
		}
		elem = elem->next;
		tmplst = elem;
	}
	return (cpy);
}

void	set_target_index_cpy(t_stack *cpy)
{
	t_s_elem	*elem;
	int			index;

	elem = cpy->first;
	index = 0;
	while (elem)
	{
		elem->t_i = index;
		elem = elem->next;
		index++;
	}
}

void	set_target_index(t_stack *sta)
{
	t_s_elem	*elem;

	elem = sta->first;
	while (elem)
	{
		elem->initial_position->t_i = elem->t_i;
		elem = elem->next;
	}
}
