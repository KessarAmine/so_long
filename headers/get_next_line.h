/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:28 by kmohamed          #+#    #+#             */
/*   Updated: 2023/02/03 18:01:14 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_line
{
	char			current;
	struct s_line	*next;
}				t_line;

char	*get_next_line(int fd);
void	ft_lstclear(t_line **lst);
void	ft_lstadd_back(t_line **alst, t_line *new);
char	*convert_lst_to_line(t_line *head);
void	ft_lstdelone(t_line *Head);
int		ft_lstsize(t_line *Head);
t_line	*ft_lstnew(char value);
#endif