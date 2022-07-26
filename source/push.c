/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 17:21:42 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	int	data;

	if (!*b)
		return ;
	data = pop(b);
	push(a, data);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	int	data;

	if (!*a)
		return ;
	data = pop(a);
	push(b, data);
	ft_printf("pb\n");
}
