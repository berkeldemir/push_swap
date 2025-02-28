/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:46:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/01 15:01:02 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_algo
{
	char **a;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}	t_algo;

typedef struct s_info
{
	int	*tmp_a;
	int	*tab_a;
	int	*tab_b;
	int	len_a;
	int	len_b;
	int	count;
	t_algo	*radix;
	t_algo	*turk;
	t_algo	*quick;
	
}	t_info;

int		ft_printf(const char *str, ...);
void	create(int ac, char **av, t_info *i);
void	reduce(t_info *i);
int		check_double(int *tab, int count);
int		new_atoi(const char *str, int *tab_num);
char	*is_empty(char *s);
void	quit_error(t_info *i);
void	quit(t_info *i, int code);

#endif