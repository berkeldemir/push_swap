/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:44:24 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 00:21:45 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static void	exec_command(t_info *i, char *cmd)
{
    if (!ft_strncmp(cmd, "sa\n", 3))
		swap_a(i, SILENT);
    else if (!ft_strncmp(cmd, "sb\n", 3))
		swap_b(i, SILENT);
    else if (!ft_strncmp(cmd, "ss\n", 3))
		swap_both(i, SILENT);
    else if (!ft_strncmp(cmd, "pa\n", 3))
		push_a(i, SILENT);
    else if (!ft_strncmp(cmd, "pb\n", 3))
		push_b(i, SILENT);
    else if (!ft_strncmp(cmd, "ra\n", 3))
		rotate_a(i, SILENT);
    else if (!ft_strncmp(cmd, "rb\n", 3))
		rotate_b(i, SILENT);
    else if (!ft_strncmp(cmd, "rr\n", 3))
		rotate_both(i, SILENT);
    else if (!ft_strncmp(cmd, "rra\n", 4))
		reverse_rotate_a(i, SILENT);
    else if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate_b(i, SILENT);
    else if (!ft_strncmp(cmd, "rrr\n", 4))
		reverse_rotate_both(i, SILENT);
    else
		(free(cmd), quit(i, 'e'));
	return ;
}

static void	read_inputs(t_info *i)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		exec_command(i, line);
		free(line);
	}
}


int main(int ac, char **av)
{
    t_info	*i;

	i = (t_info *)malloc(sizeof(t_info));
	if (!i)
		return (0);
    create_tmp_a(ac, av, i);
	reduce_tmp_a(i);
	convert_st_a(i);
	
    read_inputs(i);
	if (check_stack_sorted(i->st_a) == 1 && i->len_b == 0)
		(ft_putendl_fd("OK\n", 1), quit(i, '+'));
	else
		(ft_putendl_fd("KO\n", 1), quit(i, '-'));
}
