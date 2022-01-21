/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:49:10 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/21 12:02:02 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_put_part_int(char *str, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.dot >= 0)
	{
		count_char += ft_treat_width(flags.dot, ft_strlen(str), 0);
		count_char += ft_putstr_perc(str, flags.dot);
	}
	else
		count_char += ft_putstr_perc(str, ft_strlen(str));
	return (count_char);
}

int	ft_treat_string(char *str, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count_char += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		count_char += ft_treat_width(flags.width, flags.dot, 0);
	else
		count_char += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count_char += ft_put_part_int(str, flags);
	return (count_char);
}
