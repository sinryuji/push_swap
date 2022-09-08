/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/08 11:41:25 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	division(t_stack **a, t_stack **b, t_info info)
{
	int	i;

	if (info.depth % 2 == 0)
	{
		i = 0;
		while (i < info.pow)
		{
			make_triangle_a(a, b, get_size(info.pow, info.pow - 1 - i, info.n), \
			get_ascending(info.pow, i));
			i++;
		}
	}
	else
	{
		i = info.pow;
		while (i--)
			make_triangle_b(a, b, get_size(info.pow, info.pow - 1 - i, info.n), \
			get_ascending(info.pow, i));
	}
}

void	merge_sort(t_stack **a, t_stack **b)
{
	t_info	info;

	info.n = get_list_length(*a);
	info.depth = get_depth(*a, info.n);
	info.pow = ft_pow(3, info.depth);
	division(a, b, info);
	merge(a, b, info);
}
