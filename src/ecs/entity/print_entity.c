/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:49:24 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:45:17 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

void	print_entity(t_entity *entity)
{
	if (!entity)
		return ;
	ecs_putstr_fd("======\tENTITY ", 2);
	ecs_putnbr_fd(entity->id, 2);
	ecs_putstr_fd("\t======\n\n", 2);
	print_component_list(entity->components);
	ecs_putstr_fd("======\t  END ", 2);
	ecs_putnbr_fd(entity->id, 2);
	ecs_putstr_fd("\t======\n\n", 2);
}

void	print_entity_list(t_entity *head)
{
	if (!head)
		return ;
	print_entity(head);
	print_entity_list(head->next);
}
