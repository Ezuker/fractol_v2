/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:19:36 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/08 00:16:58 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_addcomma(char *s, int i, double sum)
{
	double	divide;
	double	add_value;

	divide = 10.0;
	if (s[i] == '.')
	{
		i++;

		while (s[i] && s[i] >= '0' && s[i] <= '9')
		{
			add_value = (s[i] - '0') / divide;
			sum += add_value;
			divide *= 10;
			i++;
		}
	}
	return (sum);
}

double	ft_atof(const char *nptr)
{
	char	*s;
	int		i;
	double	sum;
	int		save;

	i = 0;
	sum = 0;
	save = 0;
	s = (char *)nptr;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		save = i;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		sum = sum * 10 + (s[i] - '0');
		i++;
	}
	sum = ft_addcomma(s, i, sum);
	if (s[save] == '-')
		return (-sum);
	return (sum);
}
