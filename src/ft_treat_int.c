/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:00:19 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/17 15:45:02 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_int(char *dst_i, int save_i, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count_char += ft_treat_width(flags.dot - 1, ft_strlen(dst_i) - 1, 1);
	count_char += ft_putstr_perc(dst_i, ft_strlen(dst_i));
	return (count_char);
}

static int	ft_put_part_int(char *dst_i, int save_i, t_flags flags)
{
	int	count_char;

	count_char = 0;
	if (flags.minus == 1)
		count_char += ft_in_put_part_int(dst_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(dst_i))
		flags.dot = ft_strlen(dst_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count_char += ft_treat_width(flags.width, 0, 0);
	}
	else
		count_char += ft_treat_width(flags.width, ft_strlen(dst_i), flags.zero);
	if (flags.minus == 0)
		count_char += ft_in_put_part_int(dst_i, save_i, flags);
	return (count_char);
}

int	ft_treat_int(int i, t_flags flags)
{
	char	dst_i;
	int		save_i;
	int		count_char;

	save_i = i;
	count_char = 0;
	if (flags.dot == 0 && i == 0)
	{
		count_char += ft_treat_width(flags.width, 0, 0);
		return (count_char);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstr_perc('-', 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count_char++;
	}
	dst_i = ft_itoa(i);
	count_char += ft_put_part_int(dst_i, save_i, flags);
	free(dst_i);
	return (count_char);
}
