/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:00:53 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/30 19:03:43 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(t_stack *top)
{
	while (top->next)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
	}	
	return (1);
}

t_stack	*get_min_node(t_stack *top)
{
	t_stack	*min;

	min = top;
	while (top)
	{
		if (min->data > top->data)
			min = top;	
		top = top->next;
	}

	return (min);
}
