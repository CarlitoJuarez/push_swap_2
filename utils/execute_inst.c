#include "../push_swap.h"

void    exec_swap(node **root)
{
    node *buf;
    node *cur;

//    1 -> 2 -> 3
//      <-   <-

    cur = *root;
    buf = cur->next;       // 2
    cur->next = buf->next; // 1 -> 3
    if (buf->next != NULL)
        buf->next->prev = cur; // 1 <- 3
    buf->next = cur;       // 2 -> 1
    buf->prev = NULL;       // NULL <- 2
    cur->prev = buf;       // 2 <- 1
    *root = buf;
}

void    exec_push(node **root_a, node **root_b)
{
    node *buf;
    node *cur_a;
    node *cur_b;

    cur_a = *root_a;
    cur_b = *root_b;
    buf = NULL;
    if (cur_a && cur_b && cur_b->next) // push 1b infront of 1a
    {
        push_normal(&cur_a, &cur_b, &buf);
        *root_a = cur_b;
        *root_b = buf;
    }
    else if (cur_a && cur_b && !cur_b->next) // if B has only 1 node
    {
        b_only_one(&cur_a, &cur_b);
        *root_a = cur_b;     // 
        *root_b = NULL;
    }
    else if (!cur_a && cur_b) // if A is empty
    {
        a_empty(&cur_a, &cur_b);
        *root_a = cur_a;
        *root_b = cur_b;
    }
}


void    exec_rrotate(node **root)
{
    node *buf;
    node *cur;

    // 1 -> 2 -> 3
    // 3 -> 1 -> 2
    cur = *root;
    buf = cur;
    // if ((*root)->stack == 'a')
    //     ft_printf("rra\n");
    // else
    //     ft_printf("rrb\n");
    while (buf)
    {
        if (buf->next)
            buf = buf->next;
        else 
            break;
    }
    buf->prev->next = NULL; // 2 -> NULL
    buf->next = cur; // 3 -> 1
    cur->prev = buf; // 3 <- 1
    buf->prev = NULL; // NULL <- 3
    //  NULL <- 3 -> 1 -> 2 -> NULL
//                <-    <-
    *root = buf;
}

void    exec_rotate(node **root)
{
    node *buf;
    node *cur;
    // 1 -> 2 -> 3 -> 4
    // 2 -> 3 -> 4 -> 1

    // if ((*root)->stack == 'a')
    //     ft_printf("ra\n");
    // else
    //     ft_printf("rb\n");
    cur = *root;
    buf = cur;
    while (buf)
    {
        if (buf->next)
            buf = buf->next;
        else
            break;
    }
    buf->next = cur; // 4 -> 1
    cur->prev = buf; // 4 <- 1
    cur->next->prev = NULL; // NULL <- 2
    *root = cur->next; // 2 -> .. 
    cur->next = NULL; // 1 -> NULL
}

