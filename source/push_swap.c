/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:01:23 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/08 11:14:11 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

int	check_sort(t_stack *top)
{
	while (top && top->next)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
	}	
	return (1);
}

void	print_state(t_stack *a, t_stack *b)
{
	ft_printf("a : ");
	print_stack(a);
	ft_printf("b : ");
	print_stack(b);
}

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
