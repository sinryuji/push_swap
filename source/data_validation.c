/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:50:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/24 22:07:25 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/colors.h"
#include "../lib/ft_printf/lib/libft/include/libft.h"
#include <limits.h>

int	integer_check(int argc, char **argv)
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
				return (1);
		if (n > INT_MAX || n < INT_MIN)
			return (2);
	}
	return (0);
}

void	data_validation(int argc, char **argv)
{
	int	ret;

	if (argc == 1)
		ft_puterr(RED "Invalid number of factors.\n");
	ret = integer_check(argc, argv);
	if (ret == 1)
		ft_puterr(RED "Non-integer value in factors.\n");
	else if (ret == 2)
		ft_puterr(RED "Value out of integer range");
}
