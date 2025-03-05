/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:46:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/05 17:54:43 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"

# define SILENT -1
# define LOUD 1

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
	size_t	target_a;
	size_t	target_b;
}	t_info;

int		ft_printf(const char *str, ...);

int		choosen_index_from_stack(t_stack *stack, int index);
int		check_stack_sorted(t_stack *stack);
int		check_stack_circular_sorted(t_stack *stack);
int		pos_of_number_on_stack(t_stack *stack, int number);
t_stack	*find_biggest_on_stack(t_stack *stack);
t_stack	*find_smallest_on_stack(t_stack *stack);
t_stack	*head_of_stack(t_stack *stack);
int		number_on_the_index(t_stack *stack, int index);

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

void	big_sort(t_info *i);

void	init_info(t_info *i);
void	create_tmp_a(int ac, char **av, t_info *i);
void	reduce_tmp_a(t_info *i);
void	convert_st_a(t_info *info);
void	sort(t_info *i);
int		check_double(int *tab, int count);
int		new_atoi(const char *str, int *tab_num);
char	*is_empty(char *s);
void	quit_error(t_info *i);
void	quit(t_info *i, char code);

void	print_stacks(t_info *i);

#endif