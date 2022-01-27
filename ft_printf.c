/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:57:58 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/27 13:47:49 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	ft_flag_parse(const char *cpy, int i, t_flags *flags, va_list args)
{
	while (cpy[i])
	{
		if (!ft_isdigit(cpy[i]) && !ft_is_type_list(cpy[i]) && !ft_is_flag_list(cpy[i]))
			break ;
		if (cpy[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (cpy[i] == '.')
			i = ft_flag_dot(cpy, i, flags, args);
		if (cpy[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (cpy[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(cpy[i]))
			*flags = ft_flag_digit(cpy[i], *flags);
		if (ft_is_type_list(cpy[i]))
		{
			flags->type = cpy[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_treat_cpy(const char *cpy, va_list args)
{
	int		i;
	t_flags	flags;
	int		count_char;

	i = 0;
	count_char = 0;
	while
}
