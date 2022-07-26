/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 18:27:04 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	int	data;

	ft_printf("pa\n");
	if (!*b)
		return ;
	data = pop(b);
	push(a, data);
}

void	pb(t_stack **a, t_stack **b)
{
	int	data;

	ft_printf("pb\n");
	if (!*a)
		return ;
	data = pop(a);
	push(b, data);
}
