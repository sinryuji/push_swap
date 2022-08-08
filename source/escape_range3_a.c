/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_range3_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:41:02 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/08 18:38:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	escape_a_201(t_stack **a)
{
	if (get_list_length(*a) == 3)
		ra(a);
	else
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
	}
}

void	escape_a_120(t_stack **a)
{
	if (get_list_length(*a) == 3)
		rra(a);
	else
	{
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
}

void	escape_a_210(t_stack **a)
{
	if (get_list_length(*a) == 3)
	{
		sa(a);
		rra(a);
	}
	else
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
}
