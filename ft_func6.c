/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:32:25 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/17 22:48:45 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_numlen(int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n <= 0)
	{
		n *= -1;
	}
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int		ft_un(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int		ft_isthis(char z)
{
	if (z == 's' || z == 'u' || z == 'x' || z == 'X'
	|| z == 'c' || z == 'i' || z == 'd' || z == 'p')
		return (1);
	return (0);
}

int		ft_leonid(int len, char *s, int tochnost, int shirina)
{
	int		dlina;

	dlina = tochnost;
	if ((int)ft_strlen(s) < tochnost || tochnost < 0)
		dlina = (int)ft_strlen(s);
	if (ft_abs(shirina) > dlina)
		len += ft_abs(shirina);
	else
		len = dlina;
	return (len);
}

void	ft_strcost(char *s, int to, int sh, char toch)
{
	sh = ft_pewdiepie(s, to, sh);
	ft_numshirput(sh, 0);
	(toch == '.') ? ft_p_fd(s, 1, to) : ft_putstr_fd(s, 1);
	ft_numshirput(sh, 1);
}
