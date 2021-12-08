/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:13:32 by halwahed          #+#    #+#             */
/*   Updated: 2021/10/13 11:01:30 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(unsigned long n, int sign)
{
	if (n >= 2147483648UL && sign == 1)
		return (-1);
	else if (n > 2147483648UL && sign == -1)
		return (0);
	else
		return (n);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	n;

	sign = 1;
	n = 0;
	while (((*str >= 9) && (*str <= 13)) || (*str == ' '))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
			n = (n * 10) + (*str - '0');
		else
			break ;
		str++;
	}
	n = ft_check(n, sign);
	return (n * sign);
}
