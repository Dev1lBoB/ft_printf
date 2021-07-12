/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:45:15 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/15 13:59:45 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = ft_telo(str, args);
	va_end(args);
	return (i);
}
