/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:27:30 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/20 17:11:12 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_telo(const char *str, va_list args)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (!(ft_isthis(*str)) && *str != '%' && *str)
				str++;
			if (*str == 0)
				while (*(str - 1) != '%')
					str--;
			i += ft_choice(str, args);
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	return (i);
}

void	ft_numtochput(char toch, int tochnost, int i)
{
	if (toch == '.' || toch == '0')
	{
		if (toch == '.' && i == 0 && tochnost > 0)
			tochnost++;
		if (tochnost == ft_numlen(i) && toch == '0')
			tochnost--;
		if (toch == '0' && i < 0)
			tochnost--;
		if (i < 0)
			write(1, "-", 1);
		while (tochnost-- - ft_numlen(i) > 0)
			write(1, "0", 1);
	}
	if (toch != '.' && toch != '0' && i < 0)
		write(1, "-", 1);
	if (i < 0)
		i *= -1;
	if (i != -2147483648)
		toch == '.' && i == 0 ? 0 : ft_putnbr_fd(i, 1);
	else
		write(1, "2147483648", 10);
}

int		ft_shet(int shirina, int tochnost, int i, char toch)
{
	int		z;
	int		len;

	len = ft_numlen(i);
	if (tochnost > len)
		z = tochnost;
	else
		z = len;
	if (i < 0)
		z++;
	if (i == 0 && toch == '.' && tochnost < 1)
		z--;
	if ((shirina > 0 && z > shirina) || (shirina < 0 && -z < shirina))
		return (-shirina);
	if (shirina < 0)
		return (z);
	else
		return (-z);
}

int		ft_argnum(va_list args, const char *str, int len)
{
	int		shirina;
	int		tochnost;
	char	toch;
	int		i;

	shirina = ft_shirina(args, (str - 1));
	tochnost = ft_tochnost(args, str - 1);
	toch = ft_toch(str - 1);
	(tochnost < 0 && toch == '0') ? shirina = tochnost : 0;
	(tochnost < 0 && toch == '0') ? tochnost = -1 : 0;
	i = va_arg(args, int);
	(tochnost < 0 && toch == '.') ? toch = '%' : 0;
	shirina != 0 ? shirina += ft_shet(shirina, tochnost, i, toch) : 0;
	len += ft_elena(len, shirina, tochnost, i);
	if (toch == '0' && tochnost > ft_numlen(i) && i < 0)
		len--;
	(i == 0 && toch == '.' && tochnost < 1) ? len-- : 0;
	ft_numshirput(shirina, 0);
	ft_numtochput(toch, tochnost, i);
	ft_numshirput(shirina, 1);
	return (len);
}

int		ft_choice(const char *str, va_list args)
{
	int		i;

	i = 0;
	if (*str == 'd' || *str == 'i')
		i += ft_argnum(args, str, 0);
	else if (*str == 'x' || *str == 'X')
		i += ft_argshesh(args, str, 0);
	else if (*str == 'p')
		i += ft_argaddres(args, str, 0);
	else if (*str == 'u')
		i += ft_arguns(args, str, 0);
	else if (*str == 'c')
		i += ft_argchar(args, str, 0);
	else if (*str == 's')
		i += ft_argstr(args, str, 0);
	else if (*str == '%')
		i += ft_pers(args, str, 0);
	return (i);
}
