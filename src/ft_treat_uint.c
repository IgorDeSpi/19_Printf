/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:55:37 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/26 15:20:42 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_part_uint(char *unsi_int, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.dot >= 0)
		count_char += ft_treat_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
	count_char += ft_putstr_perc(unsi_int, ft_strlen(unsi_int));
	return (count_char);
}

static int	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.minus == 1)
		count_char += ft_input_part_uint(unsi_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count_char += ft_treat_width(flags.width, 0, 0);
	}
	else
		count_char += ft_treat_width(flags.width, ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		count_char += ft_input_part_uint(unsi_int, flags);
	return (count_char);
}

int	ft_treat_uint(unsigned int ui, t_flags flags)
{
	char	*unsi_int;
	int		count_char;

	count_char = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		count_char += ft_treat_width(flags.width, 0, 0);
		return (count_char);
	}
	unsi_int = ft_u_itoa(ui);
	count_char += ft_put_part_uint(unsi_int, flags);
	free(unsi_int);
	return (count_char);
}
