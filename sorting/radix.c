/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/02/26 23:56:00 by copilot           #+#    #+#             */
/*   Updated: 2026/03/05 00:00:00 by assistant        ###   ########.fr       */
=======
/*   Created: 2026/03/05 18:02:53 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/05 18:02:54 by amigdadi         ###   ########.fr       */
>>>>>>> 72b8a3d (a)
/*                                                                            */
/* ************************************************************************** */



#include "pushswap.h"

static int	max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b, t_ops *ops)
{
<<<<<<< HEAD
	int	n;
	int	bits;
	int	i;
	int	j;

	n = stack_size(*a);
	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < n)
		{
			if (((*a)->index >> i) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			j++;
		}
		while (*b)
			pa(a, b, ops);
		i++;
=======
	int		max_bits;
	int		bit;
	int		size;
	int		i;
	int		max_index;
	t_node	*temp;

	if (!a || !*a)
		return ;

	index_stack(*a);

	/* Find max index to determine number of bits needed */
	max_index = 0;
	temp = *a;
	while (temp)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}

	/* Calculate max_bits */
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;

	/* Radix sort: LSD (Least Significant Digit) */
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		size = stack_size(*a);
		while (i < size)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(a, b, ops);
			else
				ra(a, ops);
			i++;
		}
		/* Push all elements back from b to a */
		while (*b)
			pa(a, b, ops);
		bit++;
>>>>>>> 72b8a3d (a)
	}
}
