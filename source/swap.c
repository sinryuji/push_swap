/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:42:02 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 20:23:49 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"

static void	swap_stack(t_stack **top)
{
	int	data;
	int	data2;

	if (!*top || !(*top)->next)
		return ;
	data = pop(top);
	data2 = pop(top);
	push(top, data);
	push(top, data2);
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
