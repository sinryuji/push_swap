/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:09:16 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/25 20:30:58 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/colors.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

void	stack_push(t_stack **top, int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_puterr(RED "Malloc error!\n");
	new->data = data;
	new->next = *top;
	*top = new;
}

int	stack_pop(t_stack **top)
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
		return (data);
	}
	return (0);
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
		ft_printf("\n");
	}
}

void	stack_init(t_stack **top, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (--argc > 0)
	{
		str = ft_split(argv[argc], ' ');
		j = 0;
		while (str[j])
			j++;
		while (--j >= 0)
			stack_push(top, ft_atoi(str[j]));
	}
}
