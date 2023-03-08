/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_characters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:20:29 by kmohamed          #+#    #+#             */
/*   Updated: 2023/02/14 11:31:05 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

void	ft_putstr_fd(char *str, int fd, int *count)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", fd, count);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd, count);
		i++;
	}
}

void	ft_putnbr_hexlower_fd(unsigned long long nbr, int fd, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_hexlower_fd(nbr / 16, fd, count);
	ft_putchar_fd(base[nbr % 16], fd, count);
}

void	ft_putnbr_hexupper_fd(unsigned long long nbr, int fd, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_putnbr_hexupper_fd(nbr / 16, fd, count);
	ft_putchar_fd(base[nbr % 16], fd, count);
}

void	ft_putptr(void *p, int *count)
{
	write(1, "0x", 2);
	(*count)++;
	(*count)++;
	ft_putnbr_hexlower_fd((unsigned long long)p, 1, count);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}
