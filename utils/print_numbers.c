/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:56:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/02/14 09:39:48 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

void	ft_putnbr_unsigned_fd(unsigned int nb, int fd, int *count)
{
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, count);
		ft_putnbr_fd(nb % 10, fd, count);
	}
	else
	{
		ft_putchar_fd(nb + 48, fd, count);
	}
}

void	ft_putnbr_fd(int nb, int fd, int *count)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd, count);
		ft_putchar_fd('2', fd, count);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, count);
		ft_putnbr_fd(nb % 10, fd, count);
	}
	else
	{
		ft_putchar_fd(nb + 48, fd, count);
	}
}
