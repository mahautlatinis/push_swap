/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:02:24 by malatini          #+#    #+#             */
/*   Updated: 2021/06/14 13:13:25 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

int	sort_mins(t_mem *mem, t_params *params)
{
	while (params->min_b > 0 && params->min_a > 0)
	{
		rr(mem->a, mem->b, 1, mem);
		params->min_b--;
		params->min_a--;
	}
	while (params->min_a < 0 && params->min_b < 0)
	{
		rrr(mem->a, mem->b, 1, mem);
		params->min_b++;
		params->min_a++;
	}
	return (SUCCESS);
}

int	sort(t_mem *mem, t_params *params)
{
	if ((params->min_b > 0 && params->min_a > 0)
		|| (params->min_b < 0 && params->min_a < 0))
		sort_mins(mem, params);
	while (params->min_b > 0)
	{
		rb(mem->b, 1, mem);
		(params->min_b)--;
	}
	while (params->min_b < 0)
	{
		rrb(mem->b, 1, mem);
		params->min_b++;
	}
	while (params->min_a > 0)
	{
		ra(mem->a, 1, mem);
		(params->min_a)--;
	}
	while (params->min_a < 0)
	{
		rra(mem->a, 1, mem);
		params->min_a++;
	}
	pa(mem->b, mem->a, 1, mem);
	return (SUCCESS);
}
