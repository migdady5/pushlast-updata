/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeqdad <toqa.meqdad@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:50:36 by tmeqdad           #+#    #+#             */
/*   Updated: 2026/03/02 22:44:45 by tmeqdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_max_index(t_node *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static void	push_back_to_a(t_node **a, t_node **b, t_ops *ops)
{
	int	max;
	int	pos;
	int	size;
	t_node	*tmp;

	while (*b)
	{
		max = find_max_index(*b);
		pos = 0;
		size = stack_size(*b);
		tmp = *b;
		while (tmp->index != max)
		{
			pos++;
			tmp = tmp->next;
		}
		if (pos <= size / 2)
			while ((*b)->index != max)
				rb(b, ops);
		else
		{
			while ((*b)->index != max)
				rrb(b, ops);
			pa(a, b, ops);
		}
	}
}

void	chunk_sort(t_node **a, t_node **b, t_ops *ops)
{
   int	n;
   int	chunk_size;
   int	range_max;

   if (is_sorted(*a))
		return ;
	n = stack_size(*a);
	if (n <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	range_max = chunk_size;
	while (*a)
	{
		if((*a)->index < range_max)
		{
			pb(a, b, ops);
			if((*b)->index < range_max - (chunk_size / 2))
				rb(b, ops);
		}
		else
			ra(a, ops);
		if (stack_size(*b) == range_max)
			range_max += chunk_size;
	}
	push_back_to_a(a, b, ops);
}
