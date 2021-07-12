/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:30:57 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/17 23:51:16 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_sn(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == 0)
		i++;
	while (n / 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

int		ft_adresslen(unsigned long int n)
{
	int		i;

	i = 0;
	while (n / 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

void	ft_sheshbesh_fd(unsigned int n, int fd, char x)
{
	int				c;
	unsigned int	num;
	int				reg;
	int				dig;

	reg = (x == 'X') ? -10 + 'A' : 22 + 'A';
	num = n;
	c = 1;
	while (num / 16)
	{
		num /= 16;
		c *= 16;
	}
	while (c != 0)
	{
		dig = (n / c < 10) ? n / c + 48 : n / c + reg;
		write(fd, &dig, 1);
		n %= c;
		c /= 16;
	}
}

void	ft_adress_fd(unsigned long int n, int fd, char x)
{
	unsigned long int	c;
	unsigned long int	num;
	int					reg;
	int					dig;

	reg = (x == 'X') ? -10 + 'A' : 22 + 'A';
	num = n;
	c = 1;
	while (num / 16)
	{
		num /= 16;
		c *= 16;
	}
	while (c != 0)
	{
		dig = (n / c < 10) ? n / c + 48 : n / c + reg;
		write(fd, &dig, 1);
		n %= c;
		c /= 16;
	}
}

void	ft_putunsigned_fd(unsigned int n, int fd)
{
	unsigned int	c;
	unsigned int	num;
	int				dig;

	num = n;
	c = 1;
	while (num / 10)
	{
		num /= 10;
		c *= 10;
	}
	while (c != 0)
	{
		dig = n / c + 48;
		write(fd, &dig, 1);
		n %= c;
		c /= 10;
	}
}
