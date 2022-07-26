/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:56:45 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 20:25:30 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

static void	reverse_rotate_stack(t_stack **top)
{
	t_stack	*last;

	if (!*top)
		return ;
	last = get_last_node(*top);
	get_last_previous_node(*top)->next = NULL;
	last->next = *top;
	*top = last;
}

void	rra(t_stack **a)
{
	reverse_rotate_stack(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate_stack(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
}
