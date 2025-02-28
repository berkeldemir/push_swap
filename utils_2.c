/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:56:42 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/28 16:10:48 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	new_atoi(const char *str, int *tab_num)
{
	int		i;
	long	num;
	int		isneg;

	i = 0;
	num = 0;
	isneg = 1;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] != '\0' && str[i++] == '-')
		isneg *= -1;
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
        if ((long)(num * (long)isneg) > 2147483647 || \
        (long)(num * (long)isneg) < -2147483648)
            return (-1);
	}
    *tab_num = num;
	return (1);
}
