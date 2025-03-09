/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:57:24 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 00:18:00 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"

# define SILENT -1
# define LOUD 1

typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	int				cost;
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
}	t_info;

void	init_info(t_info *i);
void	create_tmp_a(int ac, char **av, t_info *i);
void	reduce_tmp_a(t_info *i);
void	convert_st_a(t_info *info);


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

int		check_stack_sorted(t_stack *stack);
int		check_double(int *tab, int count);
int		new_atoi(const char *str, int *tab_num);
char	*is_empty(char *s);
void	quit(t_info *i, char code);

#endif