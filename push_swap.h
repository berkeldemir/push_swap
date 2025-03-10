/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:46:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 04:52:09 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"

# define SILENT -1
# define LOUD 1

typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	int				cost;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
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
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
}	t_info;

int		ft_printf(const char *str, ...);

t_stack	*head_of_stack(t_stack *stack);
t_stack	*find_biggest_on_stack(t_stack *stack);
t_stack	*find_smallest_on_stack(t_stack *stack);
int		check_stack_sorted(t_stack *stack);
int		check_stack_circular_sorted(t_stack *stack);
int		pos_on_stack(t_stack *stack, int number);
int		find_max_below(t_stack *stack, int number);
int		find_min_above(t_stack *stack, int number);

void	swap_a(t_info *i, int flag);
void	push_a(t_info *i, int flag);
void	rotate_a(t_info *i, int flag);
void	reverse_rotate_a(t_info *i, int flag);

void	swap_b(t_info *i, int flag);
void	push_b(t_info *i, int flag);
void	rotate_b(t_info *i, int flag);
void	reverse_rotate_b(t_info *i, int flag);

void	swap_both(t_info *i, int flag);
void	rotate_both(t_info *i, int flag);
void	reverse_rotate_both(t_info *i, int flag);

void	create_tmp_a(int ac, char **av, t_info *i);
void	reduce_tmp_a(t_info *i);
void	convert_st_a(t_info *info);

void	sort(t_info *i);
void	sort_3_numbers(t_info *i);
void	big_sort(t_info *i);

t_stack	*find_cheapest(t_stack *stack);
void	calc_cost_a(t_info *info);
void	calc_cost_b(t_info *i);
void	reset_costs(t_info *i);
void	init_info(t_info *i);
int		check_double(int *tab, int count);
int		new_atoi(const char *str, int *tab_num);
char	*is_empty(char *s);
void	quit(t_info *i, char code);

#endif