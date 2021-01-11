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

list_t	*add_in_list(list_t *list, int data)
{
	list_t	*elem;

	elem = malloc(sizeof(*elem));
	elem->data = data;
	elem->next = list;
	return (elem);
}

list_t	*put_in_list(list_t *list, int data)
{
	list_t	*elem;
	list_t	*tmp;

	elem = malloc(sizeof(list_t));
	tmp = list;
	elem->data = data;
	elem->next = NULL;
	if (list == NULL)
		return (elem);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

void	pa_or_pb(list_t **list_1, list_t **list_2, char *str)
{
	if (*list_1 == NULL)
		return ;
	*list_2 = add_in_list(*list_2, (*list_1)->data);
	*list_1 = (*list_1)->next;
	ft_putstr(str);
}

list_t	*params_to_list(int argc, char **argv)
{
	list_t	*list;
	int		i;

	i = 0;
	list = NULL;
	while (++i != argc)
		list = add_in_list(list, ft_atoi(argv[i]));
	return (list);
}

int		list_size(list_t *list)
{
	int i;

	i = 0;
	while (list != NULL)
	{
		i += 1;
		list = list->next;
	}
	return (i);
}
