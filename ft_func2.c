/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:29:42 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/20 17:17:57 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_argchar(va_list args, const char *str, int len)
{
	int		shirina;
	int		c;

	shirina = ft_shirina(args, (str - 1));
	c = va_arg(args, int);
	if (ft_abs(shirina) > 0)
		len += ft_abs(shirina);
	else
		len = 1;
	if (shirina != 0)
		shirina += (shirina > 0) ? -1 : 1;
	ft_numshirput(shirina, 0);
	ft_putchar_fd(c, 1);
	ft_numshirput(shirina, 1);
	return (len);
}

void	ft_adrtochput(char toch, int tochnost, unsigned long int u)
{
	if (toch == '0')
	{
		if (tochnost == ft_adresslen(u) + 2 && toch == '0')
			tochnost--;
		while (tochnost-- - ft_adresslen(u) - 2 > 0)
			write(1, "0", 1);
	}
}

int		ft_argaddres(va_list args, const char *str, int len)
{
	int					shirina;
	int					tochnost;
	char				toch;
	unsigned long int	p;

	shirina = ft_shirina(args, (str - 1));
	tochnost = ft_tochnost(args, str - 1);
	toch = ft_toch(str - 1);
	p = va_arg(args, unsigned long int);
	if (ft_abs(shirina) - 2 < ft_adresslen(p) && tochnost < ft_adresslen(p))
		len += ft_adresslen(p) + 2;
	else if (tochnost < 1)
		len += ft_abs(shirina);
	else
		len += tochnost;
	if (shirina != 0)
		shirina += (shirina < 0) ? 2 : -2;
	shirina != 0 ? shirina += ft_shut(shirina, 0, p, '%') : 0;
	shirina != 0 ? ft_numshirput(shirina, 0) : 0;
	write(1, "0x", 2);
	ft_adrtochput(toch, tochnost, p);
	ft_adress_fd(p, 1, *str);
	shirina != 0 ? ft_numshirput(shirina, 1) : 0;
	return (len);
}

int		ft_arguns(va_list args, const char *str, int len)
{
	int				shirina;
	int				to;
	char			toch;
	unsigned int	u;

	shirina = ft_shirina(args, (str - 1));
	to = ft_tochnost(args, str - 1);
	toch = ft_toch(str - 1);
	(to < 0 && toch == '0') ? shirina = to : 0;
	(to < 0 && toch == '0') ? to = -1 : 0;
	u = va_arg(args, unsigned int);
	(to < 0 && toch == '.') ? toch = '%' : 0;
	shirina != 0 ? shirina += ft_shat(shirina, to, u, toch) : 0;
	len += ft_lenok(len, shirina, to, u);
	(u == 0 && toch == '.' && to < 1) ? len-- : 0;
	ft_numshirput(shirina, 0);
	ft_unstochput(toch, to, u);
	ft_numshirput(shirina, 1);
	return (len);
}

int		ft_argshesh(va_list args, const char *str, int len)
{
	int				shirina;
	int				to;
	char			toch;
	unsigned int	x;

	shirina = ft_shirina(args, (str - 1));
	to = ft_tochnost(args, str - 1);
	toch = ft_toch(str - 1);
	(to < 0 && toch == '0') ? shirina = to : 0;
	(to < 0 && toch == '0') ? to = -1 : 0;
	x = va_arg(args, unsigned int);
	(to < 0 && toch == '.') ? toch = '%' : 0;
	shirina != 0 ? shirina += ft_shot(shirina, to, x, toch) : 0;
	len += ft_lenka(len, shirina, to, x);
	(x == 0 && toch == '.' && to < 1) ? len-- : 0;
	ft_numshirput(shirina, 0);
	ft_sheshtochput(toch, to, x, *str);
	ft_numshirput(shirina, 1);
	return (len);
}
