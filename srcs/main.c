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

int		is_sort(list_t *l_a)
{
	while (l_a->next != NULL)
	{
		if (l_a->data > l_a->next->data)
			return (1);
		l_a = l_a->next;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	list_t	*l_a;
	list_t	*l_b;
	int		i;

	l_a = NULL;
	l_b = NULL;
	i = 0;
	if (argc < 2)
		// err !!!!
		return (84);
	while (argv[++i] != NULL)
		l_a = put_in_list(l_a, ft_atoi(argv[i]));
	if (is_sort(l_a) == 0)
	{
		ft_putchar('\n');
		return (0);
	}
	while (is_sort(l_a) != 0)
		sort_list(&l_a, &l_b, argc);
	ft_putchar('\n');
	return (0);
}
