/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:55:05 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/08 11:41:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

int	add_line(t_env	*env, char *line)
{
	int		i;
	char	**temp;

	if (!line)
		return (0);
	i = 0;
	env->height++;
	temp = (char **)malloc(sizeof(char *) * (env->height + 1));
	temp[env->height] = NULL;
	while (i < env->height - 1)
	{
		temp[i] = env->map[i];
		i++;
	}
	temp[i] = line;
	if (env->map)
		free(env->map);
	env->map = temp;
	return (1);
}

void	ft_init_img(t_env *env)
{
	int	i;
	int	j;

	env->path_floor = "assets/textures/floor.xpm";
	env->floor = mlx_xpm_file_to_image(env->mlx, env->path_floor,
			&i, &j);
	env->path_wall = "assets/textures/wall.xpm";
	env->wall = mlx_xpm_file_to_image(env->mlx, "assets/textures/wall.xpm",
			&i, &j);
	env->path_baby = "assets/characters/baby.xpm";
	env->baby = mlx_xpm_file_to_image(env->mlx, env->path_baby,
			&i, &j);
	env->path_pappy = "assets/characters/pappy.xpm";
	env->pappy = mlx_xpm_file_to_image(env->mlx, env->path_pappy,
			&i, &j);
	env->path_pie = "assets/collectables/pie.xpm";
	env->pie = mlx_xpm_file_to_image(env->mlx, env->path_pie,
			&i, &j);
	env->path_bed = "assets/exit/bed.xpm";
	env->bed = mlx_xpm_file_to_image(env->mlx, env->path_bed,
			&i, &j);
}

int	init(t_env *env, char **argv, t_map_constraints *map_constraints)
{
	char	*line;

	env->fd = open(argv[1], O_RDONLY);
	if (env->fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(env->fd);
		if (line == NULL)
			break ;
		if (env->width == 0)
			env->width = ft_strlen(line);
		else if (ft_strlen(line) != env->width)
			throw_error(DifferentWidthError, env);
		if (!add_line(env, line))
			break ;
	}
	map_valid(map_constraints, env);
	env->collectables_remaining = env->collectible_number;
	ft_init_img(env);
	close(env->fd);
	return (0);
}

void	ft_put_element(int x, int y, t_env *env, t_elements element)
{
	if (element == FLOOR)
		mlx_put_image_to_window(env->mlx, env->window, env->floor,
			x * 32, y * 32);
	else if (element == WALL)
		mlx_put_image_to_window(env->mlx, env->window, env->wall,
			x * 32, y * 32);
	else if (element == BED)
		mlx_put_image_to_window(env->mlx, env->window, env->bed,
			x * 32, y * 32);
	else if (element == PIE)
		mlx_put_image_to_window(env->mlx, env->window, env->pie,
			x * 32, y * 32);
	else if (element == BABY)
		mlx_put_image_to_window(env->mlx, env->window, env->baby,
			x * 32, y * 32);
	else if (element == DADDY)
		mlx_put_image_to_window(env->mlx, env->window, env->pappy,
			x * 32, y * 32);
}

void	ft_print_map(t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			ft_put_element(j, i, env, FLOOR);
			if (env->map[i][j] == '1')
				ft_put_element(j, i, env, WALL);
			else if (env->map[i][j] == 'P')
				ft_put_element(j, i, env, BABY);
			else if (env->map[i][j] == 'C')
				ft_put_element(j, i, env, PIE);
			else if (env->map[i][j] == 'E')
				ft_put_element(j, i, env, BED);
			else if (env->map[i][j] == 'X')
				ft_put_element(j, i, env, DADDY);
			j++;
		}
		i++;
	}
}
