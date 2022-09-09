/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:53:06 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:50:24 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/ft_printf/include/ft_printf.h"
#include <stdlib.h>

static int	rotate_stack(t_stack **top)
{
	t_stack	*last;

	if (!*top)
		return (0);
	last = get_last_node(*top);
	last->next = *top;
	(*top)->prev = last;
	*top = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
	return (1);
}

int	ra(t_stack **a)
{
	if (rotate_stack(a))
	{
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rb(t_stack **b)
{
	if (rotate_stack(b))
	{
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rr(t_stack **a, t_stack **b)
{
	if (rotate_stack(a) && rotate_stack(b))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
