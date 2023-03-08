/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:28:28 by kmohamed          #+#    #+#             */
/*   Updated: 2023/02/14 09:39:41 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{	
			get_conversion(args, str[i + 1], &count);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}
