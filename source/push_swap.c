/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:01:23 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/08 11:02:05 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

int	make_triangle_b(t_stack **a, t_stack **b, int size, int ascending);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	integer_validation(argc, argv);
	init_stack(&a, argc, argv);
	duplication_validation(a);
	merge_sort(&a, &b);
	return (0);
}
