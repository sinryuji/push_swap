/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:34:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/29 18:21:53 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_last_node(t_stack *top)
{
	while (top->next)
		top = top->next;
	return (top);
}

int	get_list_length(t_stack *top)
{
	int	i;

	i = 0;
	while (top)
	{
		top = top->next;
		i++;
	}

	return (i);
}

int	get_node_index(t_stack *current)
{
	return (0);
}
