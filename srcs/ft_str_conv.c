/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:28:17 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/11 14:34:29 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_str_conv(va_list args, int *printed, int *index)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*printed += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		*printed += ft_strlen(str);
	}
	(*index)++;
}
