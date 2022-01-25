/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:06:09 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/25 16:22:34 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(unsigned long long ull_cpy, int base, \
char *rtn, int count)
{
	while (ull_cpy != 0)
	{
		if ((ull_cpy % base) < 10)
			rtn[count - 1] = (ull_cpy % base) + 48;
		else
			rtn[count - 1] = (ull_cpy % base) + 55;
		ull_cpy /= base;
		count--;
	}
	return (rtn);
}

char	*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_cpy;
	int					count;

	rtn = 0;
	count = 0;
	ull_cpy = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	rtn = malloc(sizeof(char) * (count + 1));
	if (!rtn)
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_cpy, base, rtn, count);
	return (rtn);
}
