/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:29:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/04 12:40:33 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

char	*convert_lst_to_line(t_line *head)
{
	t_line	*temp;
	int		length;
	int		i;
	char	*strg;

	temp = head;
	length = ft_lstsize(head);
	strg = malloc(length + 1);
	if (strg == NULL)
		return (NULL);
	i = 0;
	while (temp)
	{
		strg[i++] = temp->current;
		temp = temp->next;
	}
	return (strg);
}

char	*get_next_line(int fd)
{
	int		cnt;
	char	buff;
	t_line	*head;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cnt = read(fd, &buff, 1);
	head = NULL;
	if (cnt <= 0)
		return (NULL);
	while (cnt > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(buff));
		if (buff == '\n')
			break ;
		cnt = read(fd, &buff, 1);
	}
	ft_lstadd_back(&head, ft_lstnew('\0'));
	temp = convert_lst_to_line(head);
	ft_lstclear(&head);
	return (temp);
}
