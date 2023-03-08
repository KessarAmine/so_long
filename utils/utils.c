/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:08:40 by kmohamed          #+#    #+#             */
/*   Updated: 2023/02/14 11:33:19 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (b);
}

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		i;
	int		l;
	size_t	memo_alloc;

	l = ft_strlen(str);
	memo_alloc = (l + 1) * sizeof(char);
	newstr = (char *) malloc(memo_alloc);
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (++i < l)
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}
