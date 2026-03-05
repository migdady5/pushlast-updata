/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:25:00 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/05 18:05:11 by amigdadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	print_bench(t_ops *ops, double disorder, const char *strategy,
		const char *complexity)
{
	double	disorder_percent;

	if (!ops || !strategy || !complexity)
		return ;
	disorder_percent = disorder * 100.0;
	dprintf(2, "[bench] disorder: %.2f%%\n", disorder_percent);
	dprintf(2, "[bench] strategy: %s / %s\n", strategy, complexity);
	dprintf(2, "[bench] total_ops: %ld\n", ops->total);
	dprintf(2, "[bench] sa: %ld sb: %ld ss: %ld pa: %ld pb: %ld\n",
		ops->sa, ops->sb, ops->ss, ops->pa, ops->pb);
	dprintf(2, "[bench] ra: %ld rb: %ld rr: %ld rra: %ld rrb: %ld rrr: %ld\n",
		ops->ra, ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}
