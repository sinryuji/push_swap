/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:53:06 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 20:24:47 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

static void	rotate_stack(t_stack **top)
{
	t_stack	*last;

	if (!*top)
		return ;
	last = get_last_node(*top);
	last->next = *top;
	*top = (*top)->next;
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

void	rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
