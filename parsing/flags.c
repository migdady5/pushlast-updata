/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amigdadi <amigdadi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:00:00 by amigdadi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/05 00:00:00 by assistant        ###   ########.fr       */
=======
/*   Updated: 2026/03/05 18:36:37 by amigdadi         ###   ########.fr       */
>>>>>>> 72b8a3d (a)
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	set_mode(const char *s, t_mode *mode)
{
	if (!ft_strncmp(s, "--simple", 9))
		*mode = MODE_SIMPLE;
	else if (!ft_strncmp(s, "--medium", 9))
		*mode = MODE_MEDIUM;
	else if (!ft_strncmp(s, "--complex", 10))
		*mode = MODE_COMPLEX;
	else if (!ft_strncmp(s, "--adaptive", 11))
		*mode = MODE_ADAPTIVE;
	else
		return (0);
	return (1);
}

<<<<<<< HEAD
int	parse_flags(int ac, char **av, t_config *cfg, int *first_num_i)
{
	int	i;

	if (!cfg || !first_num_i)
		return (0);
	cfg->mode = MODE_ADAPTIVE;
	cfg->bench = 0;
=======
int	parse_flags(int ac, char **av, t_mode *mode, int *first_num_i, int *bench)
{
	int	i;

	if (!mode || !first_num_i || !bench)
		return (0);
	*mode = MODE_COMPLEX;
	*bench = 0;
>>>>>>> 72b8a3d (a)
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strncmp(av[i], "--bench", 8))
<<<<<<< HEAD
			cfg->bench = 1;
		else if (!set_mode(av[i], &cfg->mode))
=======
			*bench = 1;
		else if (!set_mode(av[i], mode))
>>>>>>> 72b8a3d (a)
			return (0);
		i++;
	}
	*first_num_i = i;
	return (1);
}
