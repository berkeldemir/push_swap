/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:46:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 10:12:35 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	int		*tmp_a;
	int		*tab_a;
	t_stack	*st_a;
	t_stack	*st_b;
	int		len_a;
	int		len_b;
	int		len_total;
}	t_info;

int		ft_printf(const char *str, ...);

int		find_stack_size(t_stack *stack);
int		choosen_index_from_stack(t_stack *stack, int index);
int		check_stack_sorted(t_stack *stack);
int		check_stack_circular_sorted(t_stack *stack);
t_stack	*find_smallest_on_stack(t_stack *stack);

void	init_info(t_info *i);
void	create_tmp_a(int ac, char **av, t_info *i);
void	reduce_tmp_a(t_info *i);
void	convert_st_a(t_info *info);
int		check_double(int *tab, int count);
int		new_atoi(const char *str, int *tab_num);
char	*is_empty(char *s);
void	quit_error(t_info *i);
void	quit(t_info *i, char code);

#endif