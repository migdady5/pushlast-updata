/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:28:04 by amigdadi          #+#    #+#             */
/*   Updated: 2026/03/05 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	bench_meta(t_config cfg, double disorder, const char **strategy,
		const char **complexity)
{
	if (cfg.mode == MODE_SIMPLE)
	{
		*strategy = "Simple";
		*complexity = "O(n^2)";
	}
	else if (cfg.mode == MODE_MEDIUM)
	{
		*strategy = "Medium";
		*complexity = "O(n*sqrt(n))";
	}
	else if (cfg.mode == MODE_COMPLEX)
	{
		*strategy = "Complex";
		*complexity = "O(n log n)";
	}
	else if (disorder < 0.2)
	{
		*strategy = "Adaptive";
		*complexity = "O(n)";
	}
	else if (disorder < 0.5)
	{
		*strategy = "Adaptive";
		*complexity = "O(n*sqrt(n))";
	}
	else
	{
		*strategy = "Adaptive";
		*complexity = "O(n log n)";
	}
}

int	main(int ac, char **av)
{
	t_ops		ops;
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	int			*arr;
	char		**tokens;
	int			count;
	double		disorder;
	const char	*strategy;
	const char	*complexity;

	if (ac < 2)
		return (0);
	ops_init(&ops);
	a = NULL;
	b = NULL;
	if (!parse_flags(ac, av, &cfg, &count))
		error_exit();
	tokens = collect_tokens(ac, av, count, &count);
	if (!tokens)
		error_exit();
	arr = validate_and_parse(tokens, &count);
	free_tokens_partial(tokens, count);
	if (!arr)
		error_exit();
	a = build_stack_a(arr, count);
	free(arr);
	if (!a)
		error_exit();
	index_stack(a);
	disorder = compute_disorder(a);
	if (!is_sorted(a))
		sort(&a, &b, &ops, cfg.mode);
	if (cfg.bench)
	{
		bench_meta(cfg, disorder, &strategy, &complexity);
		print_bench(&ops, disorder, strategy, complexity);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
