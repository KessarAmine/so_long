/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:56:02 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/09 13:18:35 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/resources.h"

void	path_parsing(char	**clone, t_env *env, int i, size_t j)
{
	if ((clone[i][j] - 'E') == 0)
	{
		clone[i][j] = '-';
		env->exits_++;
	}
	if (((clone[i][j] - '1' ) == 0) || ((clone[i][j] - '-') == 0) ||
		((clone[i][j] - 'E') == 0))
		return ;
	if ((clone[i][j] - 'C') == 0)
		env->collectibles_++;
	if ((clone[i][j] - 'P') == 0)
		env->player_++;
	clone[i][j] = '-';
	if (i < env->height - 1)
		path_parsing(clone, env, i + 1, j);
	if (i > 0)
		path_parsing(clone, env, i - 1, j);
	if (j < env->width - 2)
		path_parsing(clone, env, i, j + 1);
	if (j > 0)
		path_parsing(clone, env, i, j - 1);
}

void	ft_free(char **tab, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return ((void) 0);
}

int	path(t_env *env)
{
	char	**clone;
	int		i;
	t_node	*visitednodes;

	i = 0;
	visitednodes = malloc(sizeof(t_node) * (env->height * env->height));
	clone = (char **)malloc(sizeof(char *) * (env->height + 1));
	clone[env->height] = NULL;
	while (i < env->height)
	{
		clone[i] = ft_strdup(env->map[i]);
		i++;
	}
	path_parsing(clone, env, env->player1_x, env->player1_y);
	if (env->collectibles_ != env->collectible_number
		|| env->player_ != 1 || env->exits_ != 1)
		throw_error(NoValidPathError, env);
	ft_free(clone, env->height);
	free(visitednodes);
	return (1);
}

void	ft_put_free(t_env *env)
{
	if (env->floor)
		mlx_destroy_image(env->mlx, env->floor);
	if (env->wall)
		mlx_destroy_image(env->mlx, env->wall);
	if (env->bed)
		mlx_destroy_image(env->mlx, env->bed);
	if (env->pie)
		mlx_destroy_image(env->mlx, env->pie);
	if (env->baby)
		mlx_destroy_image(env->mlx, env->baby);
}

void	exit_game(int status, t_env *env)
{
	int	line;

	line = 0;
	if (env->window)
		mlx_destroy_window(env->mlx, env->window);
	free(env->mlx);
	while (line < env->height)
		free(env->map[line++]);
	free(env->map);
	ft_put_free(env);
	system("leaks so_long");
	exit(status);
}

int	main(int argc, char **argv)
{
	t_env				env;
	t_map_constraints	map_constraints;
	int					game_state;

	if (argc != 2)
		exit (1);
	ft_memset(&env, 0, sizeof(t_env));
	ft_memset(&map_constraints, -1, sizeof(t_map_constraints));
	env.mlx = mlx_init();
	if (!env.mlx)
		return (0);
	game_state = init(&env, argv, &map_constraints);
	if (game_state != 0)
		return (1);
	env.window = mlx_new_window(env.mlx, (env.width) * 31,
			(env.height) * 32, "so_long");
	ft_print_map(&env);
	mlx_key_hook(env.window, key_pressed, &env);
	mlx_hook(env.window, 17, 0, (void *)exit_game, 0);
	mlx_loop(env.mlx);
	return (0);
}
