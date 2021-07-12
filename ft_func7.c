/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:15:01 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/17 20:44:36 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int		ft_lenya(int len, int shirina, int tochnost, int x)
{
	if (tochnost > ft_sn(x))
		len += tochnost;
	else
		len += ft_sn(x);
	if (ft_abs(shirina) > 0)
		len += ft_abs(shirina);
	return (len);
}

int		ft_unsdot(char toch, int tochnost, unsigned int u)
{
	if ((toch == '0' || toch == '.') && u != 0)
	{
		while (tochnost-- - ft_un(u) > 0)
			write(1, "0", 1);
		return (0);
	}
	else if (toch == '.' && u == 0)
	{
		while (tochnost-- > 0)
			write(1, "0", 1);
		return (1);
	}
	else
	{
		if (toch == '0' && u == 0 && tochnost > 0)
			write(1, "0", 1);
		while (tochnost-- - ft_un(u) > 0)
			write(1, "0", 1);
		if (tochnost < 1 && toch == '0')
			return (1);
	}
	return (0);
}

int		ft_sheshdot(char toch, int tochnost, unsigned int u)
{
	if ((toch == '0' || toch == '.') && u != 0)
	{
		while (tochnost-- - ft_sn(u) > 0)
			write(1, "0", 1);
		return (0);
	}
	else if (toch == '.' && u == 0)
	{
		while (tochnost-- > 0)
			write(1, "0", 1);
		return (1);
	}
	else
	{
		if (toch == '0' && u == 0 && tochnost > 0)
			write(1, "0", 1);
		while (tochnost-- - ft_sn(u) > 0)
			write(1, "0", 1);
		if (tochnost < 1 && toch == '0')
			return (1);
	}
	return (0);
}
