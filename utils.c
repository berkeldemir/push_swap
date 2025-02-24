/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:05:27 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/24 11:14:23 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    quit_error(t_info *i)
{
    ft_putendl_fd("Error", 1);
    quit(i, 1);
}

void    quit(t_info *i, int code)
{
    if (i->tab_a)
        free(i->tab_a);
    if (i->tab_b)
        free(i->tab_b);
    if (i)
        free(i);
    if (code == 0)
        exit(EXIT_SUCCESS);
    if (code != 0)
        exit(EXIT_FAILURE);
}
