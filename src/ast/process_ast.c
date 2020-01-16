/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:37:00 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/15 01:49:29 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"
#include "lexer.h"

/*static int	has_priority(t_lex *lex, int priority)
{
	while (lex)
	{
		if (lex->priority == priority)
			return (1);
		lex = lex->next;
	}
	return (0);
}*/

/*
** side = 1 ==> LEFT
** side = 2 ==> RIGHT
*/
/*t_ast   *last_node(t_ast *ast, int side)
{
    
}*/

t_lex   *split_lex2(t_lex *lex, int stop)
{
    t_lex *new;
    t_lex *head;

    new = lex;
    head = new;
    while (lex && new->pos <= stop)
        new = new->next;
    new->next = NULL;
    new = head;
    return (new);
}

t_lex   *split_lex3(t_lex *lex, int start)
{
    t_lex *new;

    new = NULL;
    while (lex->pos <= start)
        lex = lex->next;
    new = lex;
    return (new);
}

t_ast   *create_ast(t_ast *ast, int priority)
{
    t_lex *left;
    t_lex *current;
    t_lex *right;
    
    if (!ast)
        return (NULL);
    left = NULL;
    current = ast->lex;
    right = NULL;
    while (current && current->next != NULL)
    {
        if (priority == current->next->priority)
        {
            right = current->next;
            left = current;
            break ;    
        }
        current = current->next;            
    }
    if (current->next)
        ft_strcmp(ast->root, g_shell->lex->value) == 0 ? ast->root = current->next->value : 0;
    if (right)
    {
        right = split_lex3(g_shell->lex, current->next->pos);
        ast->right = init_node(right, "NULL");
        left = split_lex2(g_shell->lex, left->pos);
        ast->left = init_node(left, "NULL");
        g_shell->lex = right;
        if (ast->lex->next)
            ast->right = create_ast(ast->right, priority);
    }   
    return (ast);
}