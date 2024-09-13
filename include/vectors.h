/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:31:16 by harmonie          #+#    #+#             */
/*   Updated: 2024/09/13 18:31:42 by harmonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_v2i
{
	int	x;
	int	y;
}	t_v2i;

typedef struct s_v2f
{
	float	x;
	float	y;
}	t_v2f;

typedef struct s_v3i
{
	int	x;
	int	y;
	int	z;
}	t_v3i;

typedef struct s_v3f
{
	float	x;
	float	y;
	float	z;
}	t_v3f;

#endif