/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:13:43 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/21 12:01:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_includes(char str[], char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_is_valid_base(char base[])
{
	while (*base)
	{
		if (*base < ' '
			|| *base == 127
			|| *base == '+'
			|| *base == '-'
			|| ft_includes(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

int	ft_is_digit(char c)
{
	return ('0' <= c && c <= '9');
}
