/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 20:55:53 by tdontos-          #+#    #+#             */
/*   Updated: 2020/06/07 20:55:54 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(list_t **l_a, list_t **l_b)
{
	while (*l_b != NULL)
	{
		pa_or_pb(l_b, l_a, "pa");
		if (list_size(*l_b) >= 1 || is_sort(*l_a) == 1)
			ft_putchar(' ');
	}
}

int		pb(list_t **l_a, list_t **l_b, int argc)
{
	if (is_sort(*l_a) == 0 && list_size(*l_a) == argc - 1)
		return (0);
	pa_or_pb(l_a, l_b, "pb");
	ft_putchar(' ');
	return (1);
}

void	sa(list_t **l_a)
{
	list_t *list;

	list = (*l_a)->next;
	(*l_a)->next = list->next;
	list->next = *l_a;
	*l_a = list;
	ft_putstr("sa");
}

void	add_space(list_t **l_a, list_t **l_b, int argc)
{
	if ((is_sort(*l_a) == 1 && list_size(*l_a) == argc - 1)
		|| list_size(*l_b) > 0)
		ft_putchar(' ');
}

int		sort_list(list_t **l_a, list_t **l_b, int argc)
{
	int i;

	i = 1;
	while (i == 1)
	{
		i = 0;
		while ((*l_a)->next != NULL)
		{
			if ((*l_a)->data > (*l_a)->next->data)
			{
				sa(l_a);
				i = 1;
				add_space(l_a, l_b, argc);
			}
			if (pb(l_a, l_b, argc) == 0)
				return (0);
		}
		pa(l_a, l_b);
	}
	ft_putchar('\n');
	return (0);
}
