/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:12:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/10 18:33:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

void	indexing(t_stack **a)
{
	int	i;
	t_stack *tmp;
	t_stack *ret;
	t_stack *tmp2;

	i = 0;
	tmp = stack_copy(*a);
	ret = NULL;
	quick_sort(tmp, 0, get_list_length(tmp) - 1);
	tmp2 = get_last_node(*a);
	while (tmp2)
	{
		push(&ret, get_value_index(tmp2->data, tmp));
		tmp2 = tmp2->prev;
	}
	stack_free(a);
	*a = ret;
	stack_free(&tmp);
}
