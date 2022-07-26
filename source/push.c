/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 19:10:59 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"

static void	push_stack(t_stack **to, t_stack **from)
{
	if (!*from)
		return ;
	push(to, pop(from));
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	ft_printf("pb\n");
}
