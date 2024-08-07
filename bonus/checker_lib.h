#ifndef CHECKER_LIB_H
# define CHECKER_LIB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int             val;
    struct node     *next;
    struct node     *prev;
} node;

void    exec_swap(node **root);
void    exec_push(node **root_a, node **root_b);
void    exec_rotate(node **root);
void    exec_rrotate(node **root);

void    free_set(char **set);
void    free_list(node *root);
int     valid_input(char **argv);
int     comp_str(char *s1, char *s2);
int     is_sorted(node *root);
int     in_range(char **argv);
int     duplicates(node *root);

#endif