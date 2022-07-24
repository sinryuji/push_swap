/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:01:23 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/24 22:07:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

t_list	*stack_init(int argc, char **argv)
{
	t_list	*list;
	int		i;

	i = 1;
	list = ft_lstnew(argv[i++]);
	while (i < argc)
		ft_lstadd_back(&list, ft_lstnew(argv[i++]));
	return (list);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	data_validation(argc, argv);
	stack = stack_init(argc, argv);
	(void)stack;
	return (0);
}
