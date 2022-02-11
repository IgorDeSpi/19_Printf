/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:37 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/11 11:35:00 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_no_perc(const char *str, int *index, int *printed)
{
	ft_putchar_fd(str[(*index)], 1);
	(*index)++;
	(*printed)++;
}

static int	ft_percent(const char *str, int *index, va_list args, int *printed)
{
	int	ret;

	ret = 0;
	if (str[(*index)] == 'd' || str[(*index)] == 'i')
		ret = ft_int_conv(args, printed, index);
	else if (str[(*index)] == 'u')
		ret = ft_unsigned_int(args, printed, index);
	else if (str[(*index)] == 'c')
		ft_char_conv(args, printed, index);
	else if (str[(*index)] == 'x' || str[(*index)] == 'X' \
			|| str[(*index)] == 'p')
		ret = ft_hexa_conv(args, str[(*index)], printed, index);
	else if (str[(*index)] == 's')
		ft_str_conv(args, printed, index);
	else
	{
		ft_putchar_fd(str[(*index)], 1);
		(*index)++;
		(*printed)++;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;
	int		index;
	int		printed;

	va_start(args, str);
	if (!str)
		return (-1);
	ret = 0;
	index = 0;
	printed = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			index++;
			ret = ft_percent(str, &index, args, &printed);
			if (ret == -1)
				return (ret);
		}
		else
			ft_no_perc(str, &index, &printed);
	}
	va_end(args);
	return (printed);
}
