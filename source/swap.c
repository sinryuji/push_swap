/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:42:02 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 18:51:17 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_stack(t_stack **stack)
{
	int	data;
	int	data2;

	if (!*stack || !(*stack)->next)
		return ;
	data = pop(stack);
	data2 = pop(stack);
	push(stack, data);		
	push(stack, data2);		
}

void	sa(t_stack **a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
