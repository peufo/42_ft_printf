/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:13:43 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 19:17:37 by jvoisard         ###   ########.fr       */
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

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}

static int	ft_includes(char str[], char c)
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
