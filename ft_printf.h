/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:17:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 19:22:41 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format	t_format;
typedef void			(*t_formater)(va_list *args, t_format *fm);
struct	s_format
{
	t_formater	formater;
	int			width;
	int			precision;
	int			put_count;
	char		sign_positive;
	char		is_prefix_hex;
	char		is_padright;
	char		is_expand_zero;
	char		is_sign_print;
	char		is_precision_defined;
};

int		ft_printf(const char *str, ...);
int		handle_flag(const char **str, va_list *args);
void	format_c(va_list *args, t_format *fm);
void	format_s(va_list *args, t_format *fm);
void	format_p(va_list *args, t_format *fm);
void	format_di(va_list *args, t_format *fm);
void	format_u(va_list *args, t_format *fm);
void	format_x_lower(va_list *args, t_format *fm);
void	format_x_upper(va_list *args, t_format *fm);
void	format_percent(va_list *args, t_format *fm);
int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);
int		ft_is_valid_base(char base[]);
int		ft_atoi(const char **str);
int		ft_itoa(char *dest, long n, char *base, t_format *fm);
int		ft_uitoa(char *dest, unsigned long n, char *base);
int		ft_put_pad(char *str, int str_len, t_format *fm);
int		ft_put_sign(int n, t_format *fm);
int		ft_put_padleft(char *str, int str_len, int width, char fill);
int		ft_put_padright(char *str, int str_len, int width, char fill);
int		ft_put_char_n(char c, int n);
void	ft_run(t_format *fm, int put_result);
void	ft_run_precision(t_format *fm, long n, char *str, int str_len);
void	ft_run_precision_unsigned(t_format *fm, char *str, int str_len);
void	ft_run_expand_zero(t_format *fm, long n, char *str, int str_len);

#endif
