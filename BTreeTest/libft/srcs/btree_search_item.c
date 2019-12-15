/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 04:35:00 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/26 04:35:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the first element related to the reference data given as argument.
** The tree is be browsed using infix traversal.
** If the element isn’t found, the function returns NULL.
*/

void	*btree_search_item(t_btree *root, void *data_ref, \
							int (*cmpf)(void *, void *))
{
	void	*out;

	out = NULL;
	if (root)
	{
		out = btree_search_item(root->left, data_ref, cmpf);
		if (!out && !((*cmpf)(root->item, data_ref)))
			out = root->item;
		if (!out)
			out = btree_search_item(root->right, data_ref, cmpf);
	}
	return (out);
}
