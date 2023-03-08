/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:31:18 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/08 18:53:26 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdarg.h>

# include "../minilibx/mlx.h"
# include "get_next_line.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_TOP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_LEFT 123

typedef struct s_env
{
	int		fd;
	int		player1_x;
	int		player1_y;
	int		collectible_number;
	int		counter;
	void	*mlx;
	void	*window;
	void	*floor;
	void	*wall;
	void	*baby;
	void	*pappy;
	void	*pie;
	void	*bed;
	char	*path_floor;
	char	*path_wall;
	char	*path_baby;
	char	*path_pappy;
	char	*path_pie;
	char	*path_bed;
	char	**map;
	int		collectables_remaining;
	int		height;
	size_t	width;
	int		collectibles_;
	int		exits_;
	int		player_;
}				t_env;

typedef struct s_node
{
	int	i;
	int	j;
}				t_node;

typedef struct map_constraints
{
	int	noexiterror;
	int	noplayererror;
}				t_map_constraints;

typedef enum map_Erros
{
	NoExitError = -1,
	BoundriesError = -2,
	NoPlayerError = -3,
	NoCollectbleError = -4,
	ManyPlayersError = -5,
	ManyExitsError = -6,
	DifferentWidthError = -7,
	NoValidPathError = -8,
	wrongcontent = -9,
	missing_map = -10
}				t_map_Erros;

typedef enum directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}			t_directions;

typedef enum elements
{
	FLOOR,
	WALL,
	BED,
	PIE,
	BABY,
	DADDY
}			t_elements;

/*==Config Folder*/
int			destination_valid(int player_x, int player_y, t_env *env);
int			can_move(int p_x, int p_y, t_directions d, t_env *env);
int			map_valid(t_map_constraints *map_cons, t_env *env);
void		throw_error(int error, t_env *env);
int			add_line(t_env	*env, char *line);
void		ft_init_img(t_env *env);
int			init(t_env *env, char **argv, t_map_constraints *map_constraints);
void		ft_put_element(int x, int y, t_env *env, t_elements element);
void		ft_print_map(t_env *env);
int			move_right(int player_x, int player_y, t_env *env);
int			move_left(int player_x, int player_y, t_env *env);
int			move_up(int player_x, int player_y, t_env *env);
int			move_down(int player_x, int player_y, t_env *env);
int			key_pressed(int key, t_env *env);
void		sub_(t_map_constraints *map_c, t_env *e, int *i, size_t *j);
void		sub_sub(t_map_constraints *map_c, t_env *env, int *i, size_t *j);
int			_map(t_env *env, char **argv);
/*Utils folder*/
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strdup(char *str);
int			ft_printf(const char *str, ...);
void		ft_putstr_fd(char *str, int fd, int *count);
void		ft_putnbr_hexlower_fd(unsigned long long nbr, int fd, int *count);
void		ft_putnbr_hexupper_fd(unsigned long long nbr, int fd, int *count);
void		ft_putptr(void *p, int *count);
void		ft_putchar_fd(char c, int fd, int *count);
void		ft_putnbr_unsigned_fd(unsigned int nb, int fd, int *count);
void		ft_putnbr_fd(int nb, int fd, int *count);
void		get_conversion(va_list args, char signe, int *count);
void		mark(t_map_constraints *map_c, t_env *env, int *i, size_t *j);
void		exit_game(int exit_status, t_env *env);
/*so_long*/
int			path(t_env *env);
void		path_parsing(char	**clone, t_env *env, int i, size_t j);
void		checker(char current, t_env *env);
void		ft_put_free(t_env *env);
#endif