/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:09:16 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/26 20:13:21 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/colors.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	push(t_stack **top, int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_puterr(RED "Malloc error!\n");
	new->data = data;
	new->next = *top;
	*top = new;
}

int	pop(t_stack **top)
{
	t_stack	*tmp;
	int		data;

	if (*top)
	{
		tmp = *top;
		data = tmp->data;
		*top = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	return (data);
}

t_stack	*get_last_node(t_stack *top)
{
	while (top->next)
		top = top->next;
	return (top);
}

t_stack	*get_last_previous_node(t_stack *top)
{
	while (top->next->next)
		top = top->next;
	return (top);
}

void	init_stack(t_stack **top, int argc, char **argv)
{
	int		i;
	char	**str;

	while (--argc > 0)
	{
		str = ft_split(argv[argc], ' ');
		i = 0;
		while (str[i])
			i++;
		while (--i >= 0)
			push(top, ft_atoi(str[i]));
	}
}
