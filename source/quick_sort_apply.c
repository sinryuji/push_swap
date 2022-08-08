/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:13 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/08 19:58:00 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	a_to_b(t_stack **a, t_stack **b, int r)
{
	int	pivot;
	int	ra_cnt;
	int	pb_cnt;
	int	i;

	if (escape_a_to_b(a, r))
		return ;
//	pivot = get_pivots(*a).pivot1;
	pivot = get_pivots_range(*a, r).pivot1;
	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
	while (r--)
	{
		if ((*a)->data > pivot)
		{
			ra(a);
			ra_cnt++;
		}
		else
		{
			pb(a, b);
			pb_cnt++;
		}
	}
	if (get_list_length(*a) != ra_cnt)
	{
		while (i++ < ra_cnt)
			rra(a);
	}
//	print_state(*a, *b);
	a_to_b(a, b, ra_cnt);
	b_to_a(a, b, pb_cnt);
}

void	b_to_a(t_stack **a, t_stack **b, int r)
{
	int	pivot;
	int	rb_cnt;
	int	pa_cnt;
	int	i;

	if (escape_b_to_a(a, b, r))
		return ;
//	pivot = get_pivots(*b).pivot1;
	pivot = get_pivots_range(*b, r).pivot1;
	rb_cnt = 0;
	pa_cnt = 0;
	i = 0;
	while (r--)
	{
		if ((*b)->data > pivot)
		{
			pa(a, b);
			pa_cnt++;
		}
		else
		{
			rb(b);
			rb_cnt++;
		}
	}
	if (get_list_length(*b) != rb_cnt)
	{
		while(i++ < rb_cnt)
			rrb(b);
	}
//	print_state(*a, *b);
	a_to_b(a, b, pa_cnt);
	b_to_a(a, b, rb_cnt);
}
