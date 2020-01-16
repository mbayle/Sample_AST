/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 02:44:11 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/15 02:05:28 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

void	ft_putendl_col(char *str, char *color, char *colreset)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putendl(colreset);
}

void	ft_padding(int padd)
{
	int	i;

	i = 0;
	while (++i < padd)
		write(1, "\t", 1);
}

void	ft_print_node(t_ast *ast, char *side, int lvl)
{
	(void) ast;
	t_lex *tmp;

	ft_padding(lvl);
	ft_putstr("-- ");
	ft_putstr(side);
	ft_putnbr(lvl);
	ft_putendl(" --");
	ft_padding(lvl);
	if (ft_strcmp(side, "root") == 0)
	{
		ft_putstr(RED);
		ft_putstr(ast->root);
		ft_putendl(NC);
		ft_padding(lvl);
		ft_putendl("------------");
		return ;
	}
	else
		tmp = ast->lex;
	ft_putstr(RED);
	if (!ast->left && !ast->right)
	{
		while (tmp && tmp->next)
		{
			ft_putstr(tmp->value);
			ft_putstr(" ");
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		ft_putstr(tmp->value);
	}
	ft_putendl(NC);
	ft_padding(lvl);
	ft_putendl("------------");
}

void	ft_print_ast(t_ast *ast, char *side, int lvl)
{
	if (!ast)
		return ;
	if (ast->right)
		ft_print_ast(ast->right, "right", ++lvl);
	else
		++lvl;
	ft_print_node(ast, side, lvl);
	if (ast->left)
		ft_print_ast(ast->left, "left", lvl--);
	else
		--lvl;
}

void	ft_putast(t_ast *ast)
{
	if (ast)
	{
		ft_putendl_col("\n---- AST -----\n", GREEN, NC);
		ft_print_ast(ast, "root", 0);
		ft_putendl_col("\n--------------", GREEN, NC);
	}
}