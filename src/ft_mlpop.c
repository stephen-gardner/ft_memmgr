/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:25:01 by sgardner          #+#    #+#             */
/*   Updated: 2017/12/05 02:06:14 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

t_mlink	*ft_mlpop(t_mchain *mchain)
{
	t_mlink		*next;

	if (!mchain->links)
		return (NULL);
	next = mchain->links->next;
	free(mchain->links->ptr);
	free(mchain->links);
	mchain->link_count--;
	return ((mchain->links = next));
}
