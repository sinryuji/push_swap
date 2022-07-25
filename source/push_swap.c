/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:01:23 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/25 20:32:08 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*top;
	char	**data;

	top = NULL;
	integer_validation(argc, argv);
	stack_init(&top, argc, argv);
	duplication_validation(top);
	print_stack(top);
	return (0);
}
