/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:09:13 by mpetruse          #+#    #+#             */
/*   Updated: 2019/11/11 18:09:33 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double_array(void **line, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(line[i]);
		i++;
	}
	free(line);
}
