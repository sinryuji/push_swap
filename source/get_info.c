/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:31:59 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/08 11:32:09 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_depth(t_stack *a, int n)
{
	int	depth;

	depth = 0;
	while (n > 4)
	{
		n = n / 3 + (n % 3 > 0);
		depth++;
	}

	return (depth);
}

int	get_ascending(int pow, int i)
{
	int	ret;

	ret = 1;
	while (pow > 1)
	{
		if (i < pow * 2 / 3)
		{
			i = (pow / 3 - 1) - (i % (pow / 3));
			ret = !ret;
		}
		else
			i = i - pow * 2 / 3;
		pow /= 3;
	}

	return (ret);
}

int	get_y(int x, int pow)
{
	int	root;
	int	range;
	int	cnt;

	root = (pow - 1) / 2;
	range = pow / 3;
	cnt = 0;
	while (pow > 3)
	{
		if (x <= range)
			range -= pow / 9 * 2;
		else if (x <= range + pow / 3)
		{
			if (cnt % 2 == 0)
				root += pow / 3;
			else 
				root -= pow / 3;
			range += pow / 3 / 3;
		}
		else
		{
			if (cnt % 2 == 0)
				root -= pow / 3;
			else
				root += pow / 3;
			range += pow / 3 + pow / 3 / 3;
			cnt++;
		}
		pow /= 3;
		cnt++;
	}
	if (cnt % 2 == 0)
	{
		if (x % 3 == 2)
			root++;
		else if (x % 3 == 0)
			root--;
	}
	else
	{
		if (x % 3 == 2)
			root--;
		else if (x % 3 == 0)
			root++;
	}

	return (root);
}

int	get_size(int pow, int i, int n)
{
	int	x;
	int	y;
	int	ret;

	x = n % pow;
	ret = n / pow;
	while (x)
	{
		y = get_y(x, pow);	
		if (i == y)
			return (ret + 1);
		x--;
	}
	
	return (ret);
}
