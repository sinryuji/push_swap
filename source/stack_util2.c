/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:47 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/03 16:46:41 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

t_stack *stack_copy(t_stack *top)
{
	t_stack *ret;
	t_stack	*last;

	ret = NULL;
	last = get_last_node(top);
	while (last)
	{
		push(&ret, last->data);
		last = last->prev;
	}
	return (ret);
}

void	stack_free(t_stack *top)
{
	while (top)
		pop(&top);
}
