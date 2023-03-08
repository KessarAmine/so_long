/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:55:02 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/04 10:32:11 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

int	destination_valid(int player_x, int player_y, t_env *env)
{
	if ((env->map[player_x][player_y] == 'E' && !env->collectables_remaining))
	{
		ft_printf("Victory !\n");
		exit_game(0, env);
	}
	if (env->map[player_x][player_y] == 'E' && env->collectables_remaining != 0)
		return (0);
	if (env->map[player_x][player_y] == '1')
		return (0);
	if (env->map[player_x][player_y] == 'C')
		env->collectables_remaining--;
	return (1);
}

int	can_move(int player_x, int player_y, t_directions direction, t_env *env)
{
	if (direction == UP && destination_valid(--player_x, player_y, env))
		return (1);
	else if (direction == DOWN && destination_valid(++player_x, player_y, env))
		return (1);
	else if (direction == RIGHT && destination_valid(player_x, ++player_y, env))
		return (1);
	else if (direction == LEFT && destination_valid(player_x, --player_y, env))
		return (1);
	return (0);
}

int	map_valid(t_map_constraints *map_constraints, t_env *env)
{
	int		i;
	size_t	j;
	int		valid_path;

	i = 0;
	while (i < env->height)
		sub_(map_constraints, env, &i, &j);
	if (map_constraints->noexiterror < 0)
		throw_error(NoExitError, env);
	else if (map_constraints->noplayererror < 0)
		throw_error(NoPlayerError, env);
	else if (env->collectible_number == 0)
		throw_error(NoCollectbleError, env);
	valid_path = path(env);
	if (valid_path != 1)
		throw_error(valid_path, env);
	ft_printf("Valid Map\n");
	return (1);
}

void	throw_error(int error, t_env *env)
{
	if (error == BoundriesError)
		ft_printf("[Error] ... BoundriesError\n");
	else if (error == NoExitError)
		ft_printf("[Error] ... NoExitError\n");
	else if (error == NoPlayerError)
		ft_printf("[Error] ... NoPlayerError\n");
	else if (error == NoCollectbleError)
		ft_printf("[Error] ... NoCollectbleError\n");
	else if (error == ManyPlayersError)
		ft_printf("[Error] ... ManyPlayersError\n");
	else if (error == ManyExitsError)
		ft_printf("[Error] ... ManyExitsError\n");
	else if (error == DifferentWidthError)
		ft_printf("[Error] ... DifferentWidthError\n");
	else if (error == NoValidPathError)
		ft_printf("[Error] ... NoValidPathError\n");
	else if (error == wrongcontent)
		ft_printf("[Error] ... WrongContent\n");
	else if (error == missing_map)
		ft_printf("[Error] ... MissingMap\n");
	exit_game(1, env);
}
