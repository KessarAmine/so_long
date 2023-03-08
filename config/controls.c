/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:54:58 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/04 10:33:04 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

int	move_right(int player_x, int player_y, t_env *env)
{
	if (!can_move(player_x, player_y, RIGHT, env))
		return (0);
	env->map[env->player1_x][env->player1_y] = '0';
	env->player1_y++;
	env->map[env->player1_x][env->player1_y] = 'P';
	env->counter++;
	ft_printf("steps = %d\n", env->counter);
	return (1);
}

int	move_left(int player_x, int player_y, t_env *env)
{
	if (!can_move(player_x, player_y, LEFT, env))
		return (0);
	env->map[env->player1_x][env->player1_y] = '0';
	env->player1_y--;
	env->map[env->player1_x][env->player1_y] = 'P';
	env->counter++;
	ft_printf("steps = %d\n", env->counter);
	return (1);
}

int	move_up(int player_x, int player_y, t_env *env)
{
	if (!can_move(player_x, player_y, UP, env))
		return (0);
	env->map[env->player1_x][env->player1_y] = '0';
	env->player1_x--;
	env->map[env->player1_x][env->player1_y] = 'P';
	env->counter++;
	ft_printf("steps = %d\n", env->counter);
	return (1);
}

int	move_down(int player_x, int player_y, t_env *env)
{
	if (!can_move(player_x, player_y, DOWN, env))
		return (0);
	env->map[env->player1_x][env->player1_y] = '0';
	env->player1_x++;
	env->map[env->player1_x][env->player1_y] = 'P';
	env->counter++;
	ft_printf("steps = %d\n", env->counter);
	return (1);
}

int	key_pressed(int key, t_env *env)
{
	int		x;
	int		y;

	x = env->player1_x;
	y = env->player1_y;
	if (key == KEY_ESC)
		exit_game(0, env);
	if (key == KEY_W || key == KEY_TOP)
		move_up(x, y, env);
	if (key == KEY_S || key == KEY_DOWN)
		move_down(x, y, env);
	if (key == KEY_A || key == KEY_LEFT)
		move_left(x, y, env);
	if (key == KEY_D || key == KEY_RIGHT)
		move_right(x, y, env);
	ft_print_map(env);
	return (0);
}
