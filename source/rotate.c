/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:53:06 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 19:41:33 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*last;

	if (!*stack)
		return ;
	last = get_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}
