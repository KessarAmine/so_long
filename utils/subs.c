/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:04:51 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/08 12:08:18 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

void	sub_(t_map_constraints *map_constraints, t_env *env, int *i, size_t *j)
{
	(*j) = 0;
	while ((*j) < env->width)
	{
		sub_sub(map_constraints, env, i, j);
		(*j)++;
	}
	(*i)++;
}

void	sub_sub(t_map_constraints *mc, t_env *env, int *i, size_t *j)
{
	if (*j != env->width - 1)
	{
		checker(env->map[*i][*j], env);
		if (*j == env->width - 2 || *j == 0 || *i == 0 || *i == env->height)
		{
			if (env->map[*i][*j] != '1')
				throw_error(BoundriesError, env);
		}
		else if (env->map[*i][*j] == 'E')
		{
			if (mc->noexiterror > 0)
				throw_error(ManyExitsError, env);
			mc->noexiterror *= -1;
		}
		else if (env->map[*i][*j] == 'P')
		{
			if (mc->noplayererror > 0)
				throw_error(ManyPlayersError, env);
			mc->noplayererror *= -1;
			env->player1_x = *i;
			env->player1_y = *j;
		}
		else if (env->map[*i][*j] == 'C')
			env->collectible_number++;
	}
}

void	ft_draw_element(int x, int y, t_env *env, t_elements element)
{
	ft_put_element(x, y, env, FLOOR);
	ft_put_element(x, y, env, element);
}

void	checker(char current, t_env *env)
{
	if (current != '1' && current != 'E' && current != 'P'
		&& current != 'C' && current != '0')
		throw_error(wrongcontent, env);
}
