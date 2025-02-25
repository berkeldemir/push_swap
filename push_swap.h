/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:46:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/25 20:12:17 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct	s_info
{
	int	*tab_a;
	int	*tab_b;
	int	len_a;
	int	len_b;
	int	count;
}	t_info;


int		ft_printf(const char *str, ...);
void	create(int ac, char **av, t_info *i);

int		check_double(int *tab, int count);
char	*is_empty(char *s);
void    quit_error(t_info *i);
void    quit(t_info *i, int code);

#endif