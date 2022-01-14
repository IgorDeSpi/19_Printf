/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <narvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:23:32 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/14 12:23:32 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_prec(char *str, int prec)
{
	int	count_char;

	count_char = 0;
	while (str[count_char] && count_char < prec)
		ft_putchar(str[count_char++]);
	return (count_char);
}
