/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:27:50 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/03 16:43:53 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    swap(t_info *info, char ab)
{
    int *list;
    int size;
    int tmp;

    if (ab == 'a')
    {
        list = info->tab_a;
        size = info->len_a;
    }
    else if (ab == 'b')
    {
        list = info->tab_b;
        size = info->len_b;
    }
    else if (ab == 's')
    {
        swap(info, 'a');
        swap(info, 'b');
        return ;
    }
    else
        quit(i, -1);
    tmp = list[0];
    list[0] = list[1];
    list[1] = tmp;
}
