/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 01:20:24 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/15 03:06:03 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

t_ast   *init_node(t_lex *lex, char *root)
{
    t_ast *new_node;

    if (!(new_node = ft_memalloc(sizeof(t_ast))))
        return (NULL);
    new_node->lex = lex;
    new_node->root = root;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

void    init_priority(t_lex *lex)
{
    if (!lex)
        return ;
    while (lex)
    {
        if (lex->operator == OTHER)
            lex->priority = 0;
        else if (lex->operator == PIPE)
            lex->priority = 1;
        else if (lex->operator == SEMIC || lex->operator == AND)
            lex->priority = 3;
        else if (lex->operator == DAND || lex->operator == DPIPE)
            lex->priority = 2;
        else
            lex->priority = 0;
        //printf("[DEBUG][PRIORITY]\n   Value du maillon : | %s |\n   Valeur de token : | %u |\n   Valeur de priority : | %d |\n", lex->value, lex->operator, lex->priority);
        lex = lex->next;
    }
}

t_ast   *no_root(t_lex *lex, t_ast *ast)
{
    char *new_root;

    new_root = ast->root;
    lex->next ? lex = lex->next : 0;
    while (lex && ft_strcmp(lex->value, "_EOI_") != 0)
    {
        new_root = ft_strcat(new_root, lex->value);
        new_root = ft_strcat(new_root, " ");
        lex = lex->next;
    }
    ast->root = new_root;
    return (ast);
}

t_ast    *sub_split(t_ast *ast, int find, int priority)
{
    if ((ast->right || ast->left) && ast->lex->pos < find)
    {
        if (ast->lex->pos > find)
            sub_split(ast->right, find, priority);
        if (ast->lex->pos < find)
            sub_split(ast->left, find, priority);
    }
    else
    {
        t_lex *left;
        t_lex *current;
        t_lex *right;
        
        left = NULL;
        current = ast->lex;
        right = NULL;
        while (current->pos <= find)
        {
            left = current;
            if (current->next->priority == priority)
            {
                right = current->next;
                break ;    
            }
            current = current->next;
        }
        if (right)
        {
            right = split_lex3(ast->lex, current->next->pos);
            ast->right = init_node(right, "NULL");
            left = split_lex2(ast->lex, left->pos);
            ast->left = init_node(left, "NULL");
        }
    }
    return (ast);
}

// side = 0 => ROOT
// side = 1 => LEFT
// side = 2 => RIGHT
int    find_priority(t_ast *ast, int depth, int side, int priority)
{
    t_lex *lex;

    lex = ast->lex;
    if (!ast)
       return (0); 
    else 
    { 
        while (lex)
        {
            if (lex->priority == priority)
            {
                ft_putstr(GREEN);
                ft_putstr("IT'S A MATCH ! ");
                ft_putstr(NC);
                ft_putstr("Side ");
                side == 1 ? ft_putstr("left ") : ft_putstr("right ");
                ft_putstr("at depth ");
                ft_putnbr(depth);
                ft_putstr(" | next priority is : ");
                ft_putstr(lex->value);
                ft_putstr("  | lex->pos is : ");
                ft_putnbr(lex->pos);
                write(1, "\n", 1);
                if(lex->next != NULL)
                    sub_split(ast, lex->pos, priority);
            }
            lex = lex->next;
        }
    }
    return (1);
}

int     max_depth(t_ast *ast, int left_depth, int right_depth)  
{
    int priority;

    priority = 2;
    if (!ast)
       return 0; 
    else 
    {
        while (priority >= 1)
        {
            if (ast->left)
                find_priority(ast->left, left_depth++, 1, priority);
            if (ast->right)
                find_priority(ast->right, right_depth++, 2, priority);
            priority--;
        }
        left_depth = max_depth(ast->left, left_depth, right_depth); 
        right_depth = max_depth(ast->right, left_depth, right_depth);
        if (left_depth > right_depth)  
           return(left_depth+1); 
        else 
            return(right_depth+1); 
    } 
}

int     build_ast(t_lex *lex, t_ast **ast)
{
    int depth_max;

    depth_max = 0;
    if (!ast)
		return (-1);
	*ast = NULL;
    if (lex && lex->token != UNKNOWN)
    {
        init_priority(lex);
        *ast = init_node(lex, lex->value);
        *ast = create_ast(*ast, 3);
        ft_putstr(GREEN);
        ft_putendl("[DEBUG][BUILD_AST] Create AST Level 3 complete");
        ft_putstr(NC);
        depth_max = max_depth((*ast), 2, 2);
        ft_putstr(RED);
        ft_putstr("Depth of tree : ");
        ft_putstr(NC);
        ft_putnbr(depth_max);
        write(1, "\n", 1);
        ft_putstr(GREEN);
        ft_putendl("[DEBUG][BUILD_AST] Create AST Level 2 complete");
        ft_putstr(NC);
        !(*ast)->right && !(*ast)->left ? no_root(lex, (*ast)) : 0;
        ft_putast(*ast);
    }
    return (0);
}