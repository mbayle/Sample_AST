/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:30:08 by alalonzo          #+#    #+#             */
/*   Updated: 2016/11/23 13:59:55 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ispunct(int c)
{
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64))
	{
		return (1);
	}
	if ((c >= 91 && c <= 96) || (c >= 123 && c <= 126))
	{
		return (1);
	}
	return (0);
}
