/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:09:16 by hyeongki          #+#    #+#             */
/*   Updated: 2022/08/08 22:10:02 by hyeongki         ###   ########.fr       */
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
	if (*top)
		new->next = *top;
	else
		new->next = NULL;
	new->next = *top;
	new->prev = NULL;
	if (*top)
		(*top)->prev = new;
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
		if (*top)
			(*top)->prev = NULL;
		free(tmp);
		tmp = NULL;
	}
	return (data);
}

void	print_stack(t_stack *top)
{
	t_stack	*tmp;

	if (top)
	{
		tmp = top;
		while (tmp)
		{
			ft_printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	}
	ft_printf("\n");
}

void	print_state(t_stack *a, t_stack *b)
{
	ft_printf("a : ");
	print_stack(a);
	ft_printf("b : ");
	print_stack(b);
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
		ft_split_free(str);
	}
}
