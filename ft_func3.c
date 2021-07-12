/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:30:18 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/16 16:08:25 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	ft_p_fd(char *s, int fd, int tochnost)
{
	int		i;

	i = 0;
	while (i < tochnost && s[i])
		write(fd, &s[i++], 1);
}

int		ft_pers(va_list args, const char *str, int len)
{
	int		shirina;
	int		tochnost;
	char	toch;

	tochnost = ft_tochnost(args, str - 1);
	toch = ft_toch(str - 1);
	shirina = ft_shirina(args, (str - 1));
	len = 1;
	if (shirina != 0)
	{
		len = ft_abs(shirina);
		shirina += (shirina > 0) ? -1 : 1;
	}
	ft_numshirput(shirina, 0);
	if (toch == '0')
	{
		len += tochnost - 1;
		while (tochnost-- - 1)
			write(1, "0", 1);
	}
	ft_putchar_fd('%', 1);
	ft_numshirput(shirina, 1);
	return (len);
}

void	ft_numshirput(int shirina, int a)
{
	if (shirina > 0 && a == 0)
	{
		while (shirina-- > 0)
			write(1, " ", 1);
	}
	if (shirina < 0 && a == 1)
	{
		shirina *= -1;
		while (shirina-- > 0)
			write(1, " ", 1);
	}
}

int		ft_pewdiepie(char *s, int tochnost, int shirina)
{
	int		dlina;
	int		lena;

	lena = ft_strlen(s);
	dlina = tochnost;
	if (lena < tochnost || tochnost < 0)
		dlina = lena;
	if (tochnost < 0)
	{
		if (ft_abs(shirina) > lena)
		{
			shirina += (shirina > 0) ? -lena : lena;
			return (shirina);
		}
		return (0);
	}
	if (ft_abs(shirina) < dlina)
		return (0);
	shirina += (shirina > 0) ? -dlina : dlina;
	return (shirina);
}

int		ft_argstr(va_list args, const char *str, int len)
{
	int		sh;
	int		to;
	char	toch;
	char	*s;

	sh = ft_shirina(args, (str - 1));
	to = ft_tochnost(args, str - 1);
	toch = ft_tach(str - 1);
	toch == '.' && to < 0 ? toch = '%' : 0;
	s = va_arg(args, char *);
	if (s)
	{
		len = ft_leonid(0, s, to, sh);
		ft_strcost(s, to, sh, toch);
	}
	else
	{
		len = ft_leonid(0, "(null)", to, sh);
		ft_strcost("(null)", to, sh, toch);
	}
	return (len);
}
