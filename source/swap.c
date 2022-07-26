/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:42:02 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 18:29:50 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **a)
{
	int	data;
	int	data2;

	ft_printf("sa\n");
	if (!*a)
		return ;
	data = pop(a);
	data2 = pop(a);
	push(a, data);		
	push(a, data2);		
}

void	sb(t_stack **b)
{
	int	data;
	int	data2;

	ft_printf("sb\n");
	if (!*b)
		return ;
	data = pop(b);
	data2 = pop(b);
	push(b, data);		
	push(b, data2);		
}
