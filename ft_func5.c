/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:31:35 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/16 16:07:18 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		ft_return(const char *str, int i)
{
	if (*str == '*' && *(str - 1) == '-' && i > 0)
		return (-i);
	if (*str == '*')
		return (i);
	if (*(str - 1) == '-')
		return (ft_atoi(str - 1));
	if (*str != 0)
		return (ft_atoi(str));
	return (0);
}

int		ft_shirina(va_list args, const char *str)
{
	int		i;
	int		j;

	i = 0;
	while (*(str) != '%')
		str--;
	str++;
	if (*str == 48)
	{
		j = 0;
		while (str[j + 1] == 48)
			j++;
		if (str[j + 1] == '-')
			return (-ft_atoi(str + j + 2));
		while (!ft_isthis(str[j]) && str[j] != '.')
			j++;
		if (str[j] != '.')
			return (0);
	}
	while (*str == '-' && !ft_isdigit(*str) && !ft_isthis(*str) && *str != '*')
		str++;
	(*str == '*') ? i = va_arg(args, int) : 0;
	return (ft_return(str, i));
}

int		ft_tochnost(va_list args, const char *str)
{
	while (ft_isdigit(*str) || *str == '*')
		str--;
	str++;
	if (*str == 48)
		while (*(str + 1) == 48)
			str++;
	if (*(str + 1) == '*' && *str == 48)
		return (va_arg(args, int));
	if (*(str) == '0')
		return (ft_atoi(str + 1));
	while (*str != '.' && *str != '%')
	{
		if (*str == '0')
		{
			while (ft_isdigit(*str))
				str--;
			if (*(str + 1) == '0')
				return (ft_atoi(str + 2));
			str++;
		}
		str--;
	}
	if (*(str + 1) == '*' && (*str != '%'))
		return (va_arg(args, int));
	return (*str == '%') ? -1 : ft_atoi(str + 1);
}

int		ft_toch(const char *str)
{
	while (ft_isdigit(*str))
		str--;
	if (*(str + 1) == '0' && *str != '.' && *str != '-' && *(str + 2) != '-')
		return ('0');
	while (*str != '.' && *str != '%')
	{
		if (*str == '0')
		{
			while (ft_isdigit(*str))
				str--;
			if (*(str + 1) == '0')
				return ('0');
			str++;
		}
		str--;
	}
	return (*str);
}

int		ft_tach(const char *str)
{
	while (ft_isdigit(*str))
		str--;
	while (*str != '.' && *str != '%')
		str--;
	return (*str);
}
