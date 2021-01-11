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

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

# include <fcntl.h>
# include "libft.h"

typedef struct		list_s
{
	int				data;
	struct list_s	*next;
}					list_t;

list_t				*add_in_list(list_t *, int);
list_t				*params_to_list(int, char **);
void				pa_or_pb(list_t **, list_t **, char *);
list_t				*put_in_list(list_t *, int);

void				pa(list_t **, list_t **);
int					pb(list_t **, list_t **, int);
void				sa(list_t **);
int					sort_list(list_t **, list_t **, int);

int					is_sort(list_t *);

int					my_getnbr(char *);
void				my_put_nbr(int);
void				my_putstr(char const *);
void				my_putchar(char);

int					list_size(list_t *);
void				my_show_list(list_t *);

#endif
