/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:42:33 by sgardner          #+#    #+#             */
/*   Updated: 2017/12/04 22:15:01 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

t_mlink	*ft_mlrev(t_mchain *mchain)
{
	t_mlink		*current;
	t_mlink		*prev;
	t_mlink		*next;

	if (!(current = mchain->links))
		return (NULL);
	prev = NULL;
	while (TRUE)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		if (!next)
			break ;
		current = next;
	}
	return ((mchain->links = current));
}
