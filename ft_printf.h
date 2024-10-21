/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:17:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 23:21:30 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format	t_format;
typedef int				(*t_formater)(va_list args, t_format *format);
struct	s_format
{
	t_formater	formater;
	int			width;
	int			precision;
	char		sign_positive;
	char		is_prefix_hex;
	char		is_padright;
	char		is_expand_zero;
};

int	ft_printf(const char *str, ...);
int	handle_flag(const char **str, va_list args);
int	format_c(va_list args, t_format *format);
int	format_s(va_list args, t_format *format);
int	format_p(va_list args, t_format *format);
int	format_di(va_list args, t_format *format);
int	format_u(va_list args, t_format *format);
int	format_x_lower(va_list args, t_format *format);
int	format_x_upper(va_list args, t_format *format);
int	format_percent(va_list args, t_format *format);
int	ft_put_nbr(long nbr, char *base);
int	ft_put_unbr(unsigned long nbr, char *base);
int	ft_strlen(char *str);
int	ft_includes(char str[], char c);
int	ft_is_valid_base(char base[]);
int	ft_is_digit(char c);
int	ft_atoi(const char **str);
int	ft_itoa(char *dest, int n, char *base, t_format *format);
int	ft_uitoa(char *dest, unsigned int n, char *base);
int	ft_pad(char *str, int str_len, t_format *format);
int	ft_write_n(char c, int n);
int	ft_padleft(char *str, int str_len, int width, char fill);

#endif
