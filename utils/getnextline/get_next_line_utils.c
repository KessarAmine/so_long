/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:29:17 by kmohamed          #+#    #+#             */
/*   Updated: 2023/02/03 17:32:28 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

int	ft_lstsize(t_line *Head)
{
	t_line	*temp;
	int		count;

	count = 0;
	temp = Head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	ft_lstdelone(t_line *Head)
{
	t_line	*temp;

	if (!Head)
		return ;
	temp = Head;
	Head = Head->next;
	free(temp);
}

t_line	*ft_lstnew(char value)
{
	t_line	*result;

	result = malloc(sizeof(t_line));
	if (result == NULL)
		return (NULL);
	result->current = value;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back(t_line **alst, t_line *new)
{
	t_line	*ptr;

	if (alst && *alst)
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if (alst)
		*alst = new;
}

void	ft_lstclear(t_line **lst)
{
	t_line	*temp;
	t_line	*prev;

	if (lst && *lst)
	{
		prev = (t_line *)*lst;
		while (prev)
		{
			temp = prev->next;
			ft_lstdelone(prev);
			prev = temp;
		}
		*lst = NULL;
	}
}
