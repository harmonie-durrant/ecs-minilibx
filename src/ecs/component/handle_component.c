/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_component.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:15:03 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 23:31:50 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ecs.h"

int	append_component(t_component **head, t_component *new)
{
	if (!new)
		return (1);
	if (*head)
		new->next = *head;
	*head = new;
	return (0);
}

void	*get_component(t_component *head, t_component_type type)
{
	t_component	*curr;

	curr = head;
	if (!head)
		return (NULL);
	while (curr)
	{
		if (curr->type == type)
			break ;
		curr = curr->next;
	}
	if (curr)
		return (curr->data);
	return (NULL);
}

int	remove_component(t_component **head, t_component_type type)
{
	t_component	*curr;
	t_component	*prev;

	curr = *head;
	prev = *head;
	if (!curr)
		return (1);
	if (curr->type == type)
	{
		*head = curr->next;
		destroy_component(curr);
		return (0);
	}
	while (curr && curr->type != type)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr)
	{
		prev->next = curr->next;
		destroy_component(curr);
		return (0);
	}
	return (1);
}
