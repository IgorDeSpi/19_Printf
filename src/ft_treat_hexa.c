/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:33:35 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/25 14:49:05 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_part_hexa(char *hexa, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.dot >= 0)
		count_char += ft_treat_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	count_char += ft_putstr_perc(hexa, ft_strlen(hexa));
	return (count_char);
}

static int	ft_put_part_hexa(char *hexa, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.minus == 1)
		count_char += ft_input_part_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count_char += ft_treat_width(flags.width, 0, 0);
	}
	else
		count_char += ft_treat_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		count_char += ft_input_part_hexa(hexa, flags);
	return (count_char);
}

int	ft_treat_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		count_char;

	count_char = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		count_char += ft_treat_width(flags.width, 0, 0);
		return (count_char);
	}
	hexa = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	count_char += ft_put_part_hexa(hexa, flags);
	free(hexa);
	return (count_char);
}
