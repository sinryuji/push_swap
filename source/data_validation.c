/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:50:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/25 19:42:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/colors.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"
#include <limits.h>

void	integer_validation(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;
	long	n;

	i = 1;
	while (i < argc)
	{
		j = 0;
		str = argv[i++];
		n = ft_atol(str);
		if (n < 0)
			j++;
		while (str[j])
			if (!ft_isdigit(str[j++]))
				ft_puterr(RED "Invalid number of factors.\n");
		if (n > INT_MAX || n < INT_MIN)
			ft_puterr(RED "Non-integer value in factors.\n");
	}
}

void	duplication_validation(t_stack *top)
{
	t_stack *current;
	t_stack *tmp;

	while (top)
	{
		current = top;
		tmp = top->next;
		while (tmp)
		{
			if (current->data == tmp->data)
				ft_puterr(RED "Duplicate data found.\n");
			tmp = tmp->next;
		}
		top = top->next;
	}
}
