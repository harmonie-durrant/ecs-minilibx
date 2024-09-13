/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:23:05 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:45:33 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

void	print_component_list(t_component *head)
{
	t_component	*curr;

	curr = head;
	if (!curr)
		return ;
	while (curr)
	{
		curr->print(curr->data);
		ecs_putstr_fd("\n", 2);
		curr = curr->next;
	}
}
