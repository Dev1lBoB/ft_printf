/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:10:23 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/20 17:23:44 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_elena(int len, int shirina, int tochnost, int i)
{
	if (tochnost > ft_numlen(i))
		len += tochnost;
	else
		len += ft_numlen(i);
	if (ft_abs(shirina) > 0)
		len += ft_abs(shirina);
	if (i < 0)
		len++;
	if (i == -2147483648 && tochnost > 10)
		len--;
	return (len);
}

int		ft_lenka(int len, int shirina, int tochnost, unsigned int u)
{
	if (tochnost > ft_sn(u))
		len += tochnost;
	else
		len += ft_sn(u);
	if (ft_abs(shirina) > 0)
		len += ft_abs(shirina);
	return (len);
}

int		ft_lenok(int len, int shirina, int tochnost, unsigned int u)
{
	if (tochnost > ft_un(u))
		len += tochnost;
	else
		len += ft_un(u);
	if (ft_abs(shirina) > 0)
		len += ft_abs(shirina);
	return (len);
}

void	ft_unstochput(char toch, int tochnost, unsigned int u)
{
	if (toch == '.' || toch == '0')
	{
		if (toch == '.' && u == 0 && tochnost > 0)
			tochnost++;
		if (tochnost == ft_un(u) && toch == '0')
			tochnost--;
		while (tochnost-- - ft_un(u) > 0)
			write(1, "0", 1);
	}
	toch == '.' && u == 0 ? 0 : ft_putunsigned_fd(u, 1);
}

void	ft_sheshtochput(char toch, int tochnost, unsigned int u, char c)
{
	if (toch == '.' || toch == '0')
	{
		if (toch == '.' && u == 0 && tochnost > 0)
			tochnost++;
		if (tochnost == ft_sn(u) && toch == '0')
			tochnost--;
		while (tochnost-- - ft_sn(u) > 0)
			write(1, "0", 1);
	}
	toch == '.' && u == 0 ? 0 : ft_sheshbesh_fd(u, 1, c);
}
