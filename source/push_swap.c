/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:01:23 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/06 18:17:55 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

int	ascending_triangle_a_3(t_stack **a, t_stack **b);
int	ascending_triangle_a_4(t_stack **a, t_stack **b);
int	descending_triangle_a_3(t_stack **a, t_stack **b);
int	descending_triangle_a_4(t_stack **a, t_stack **b);
int	get_depth(t_stack *a, int n);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	integer_validation(argc, argv);
	init_stack(&a, argc, argv);
	duplication_validation(a);
//	quick_sort(a, 0, get_list_length(a) - 1);
//	selection_sort(&a, &b);
//	a_to_b(&a, &b, get_list_length(a));
//	print_state(a, b);
	indexing(&a);
//	hourglass_sort(&a, &b);
	merge_sort(&a, &b);
//	ascending_triangle_a_4(&a, &b);
//	print_state(a, b);
	return (0);
}
