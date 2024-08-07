#include "../push_swap.h"

void push_normal(node **cur_a, node **cur_b, node **buf)
{
    if ((*cur_b)->stack == 'a')
        (*cur_b)->stack = 'b';
    else
        (*cur_b)->stack = 'a';
    *buf = (*cur_b)->next; // 2b
    (*cur_b)->next = *cur_a; // 1b -> 1a
    (*cur_a)->prev = *cur_b; // 1b <- 1a
    (*buf)->prev = NULL; // NULL <- 2b
}
void b_only_one(node **cur_a, node **cur_b)
{
        if ((*cur_b)->stack == 'a')
            (*cur_b)->stack = 'b';
        else
            (*cur_b)->stack = 'a';
        (*cur_b)->next = *cur_a; // 1b -> 1a
        (*cur_a)->prev = *cur_b; // 1b <- 1a
}

void a_empty(node **cur_a, node **cur_b)
{
        if ((*cur_b)->stack == 'a')
            (*cur_b)->stack = 'b';
        else
            (*cur_b)->stack = 'a';
        *cur_a = *cur_b;
        if ((*cur_b)->next)
            (*cur_b)->next->prev = NULL;
        *cur_b = (*cur_b)->next;
        (*cur_a)->next = NULL;
}

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}