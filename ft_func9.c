/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:13:50 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/20 17:15:52 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_shat(int shirina, int tochnost, unsigned int u, char toch)
{
	int		z;
	int		len;

	len = ft_un(u);
	if (tochnost > len)
		z = tochnost;
	else
		z = len;
	if (u == 0 && toch == '.' && tochnost < 1)
		z--;
	if ((shirina > 0 && z > shirina) || (shirina < 0 && -z < shirina))
		return (-shirina);
	if (shirina < 0)
		return (z);
	else
		return (-z);
}

int		ft_shot(int shirina, int tochnost, unsigned int u, char toch)
{
	int		z;
	int		len;

	len = ft_sn(u);
	if (tochnost > len)
		z = tochnost;
	else
		z = len;
	if (u == 0 && toch == '.' && tochnost < 1)
		z--;
	if ((shirina > 0 && z > shirina) || (shirina < 0 && -z < shirina))
		return (-shirina);
	if (shirina < 0)
		return (z);
	else
		return (-z);
}

int		ft_shut(int shirina, int tochnost, unsigned long int u, char toch)
{
	int		z;
	int		len;

	len = ft_adresslen(u);
	if (tochnost > len)
		z = tochnost;
	else
		z = len;
	if (u == 0 && toch == '.' && tochnost < 1)
		z--;
	if ((shirina > 0 && z > shirina) || (shirina < 0 && -z < shirina))
		return (-shirina);
	if (shirina < 0)
		return (z);
	else
		return (-z);
}
