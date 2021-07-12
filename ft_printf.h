/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:13:23 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/20 17:28:27 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_telo(const char *str, va_list args);
int		ft_choice(const char *str, va_list args);
int		ft_argnum(va_list args, const char *str, int len);
int		ft_argshesh(va_list args, const char *str, int len);
int		ft_argaddres(va_list args, const char *str, int len);
int		ft_arguns(va_list args, const char *str, int len);
int		ft_argchar(va_list args, const char *str, int len);
int		ft_argstr(va_list args, const char *str, int len);
int		ft_pers(va_list args, const char *str, int len);
int		ft_adresslen(unsigned long int n);
int		ft_sn(unsigned int n);
int		ft_tach(const char *str);
int		ft_toch(const char *str);
int		ft_tochnost(va_list args, const char *str);
int		ft_shirina(va_list args, const char *str);
int		ft_isthis(char z);
int		ft_un(unsigned int n);
int		ft_numlen(int n);
int		ft_abs(int i);
int		ft_shet(int shirina, int tochnost, int i, char toch);
int		ft_shat(int shirina, int tochnost, unsigned int u, char toch);
int		ft_shot(int shirina, int tochnost, unsigned int u, char toch);
int		ft_shut(int shirina, int tochnost, unsigned long int u, char toch);
int		ft_unsdot(char toch, int tochnost, unsigned int u);
int		ft_sheshdot(char toch, int tochnost, unsigned int u);
int		ft_leonid(int len, char *s, int tochnost, int shirina);
int		ft_lenya(int len, int shirina, int tochnost, int x);
int		ft_elena(int len, int shirina, int tochnost, int i);
int		ft_lenka(int len, int shirina, int tochnost, unsigned int u);
int		ft_lenok(int len, int shirina, int tochnost, unsigned int u);
int		ft_pewdiepie(char *s, int tochnost, int shirina);
int		ft_return(const char *str, int i);
char	ft_shir(const char *str);
void	ft_numtochput(char toch, int tochnost, int i);
void	ft_unstochput(char toch, int tochnost, unsigned int u);
void	ft_sheshtochput(char toch, int tochnost, unsigned int u, char c);
void	ft_numshirput(int shirina, int a);
void	ft_p_fd(char *s, int fd, int tochnost);
void	ft_putunsigned_fd(unsigned int n, int fd);
void	ft_adress_fd(unsigned long int n, int fd, char x);
void	ft_sheshbesh_fd(unsigned int n, int fd, char x);
void	ft_strcost(char *s, int to, int sh, char toch);

#endif
