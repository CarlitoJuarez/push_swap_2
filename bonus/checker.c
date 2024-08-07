#include "checker_lib.h"

// allowed functions: read, write, malloc, free, exit

node *create_list(char **argv)
{
    int     i;
    node    *new_node;
    node    *curr;
    node    *root;

    i = 1;
    curr = NULL;
    root = NULL;
    while (argv[i])
    {
        new_node = malloc(sizeof(node) * 1);
        if (!new_node)
            return (NULL);
        new_node->val = atoi(argv[i]);
        new_node->next = NULL;
        if (curr)
            curr->next = new_node;
        new_node->prev = curr;
        curr = new_node;
        if (i == 1)
            root = curr;
        i++;
    }
    new_node = NULL;
    curr = NULL;
    write(1, "\n", 1);
    return (root);
}



void exec_cmnd(node *root_a, char **set)
{
    size_t i;
    node *root_b;
    node *buf;

    i = 0;

    root_b = NULL;
    while (set[i])
    {
        buf = root_a;
        printf("BUF:OG ");
        while (buf)
        {
            printf("%d, ", buf->val);
            buf =  buf->next;
        }
        printf("\n");
        if (comp_str(set[i], "sa"))
        {
            exec_swap(&root_a);
            buf = root_a;
            printf("BUF:sa: ");
            while (buf)
            {
                printf("%d, ", buf->val);
                buf =  buf->next;
            }
            printf("\n");
        }
        else if(comp_str(set[i], "sb"))
            exec_swap(&root_b);
        else if(comp_str(set[i], "ss"))
        {
            exec_swap(&root_a);
            exec_swap(&root_b);
        }
        else if(comp_str(set[i], "pa"))
        {
            exec_push(&root_a, &root_b);
            buf = root_a;
            printf("BUF:pa: ");
            while (buf)
            {
                printf("%d, ", buf->val);
                buf =  buf->next;
            }
            printf("\n");
        }
        else if(comp_str(set[i], "pb"))
        {
            exec_push(&root_b, &root_a);
            buf = root_a;
            printf("BUF:pb ");
            while (buf)
            {
                printf("%d, ", buf->val);
                buf =  buf->next;
            }
            printf("\n");
        }        
        else if(comp_str(set[i], "ra"))
            exec_rotate(&root_a);
        else if(comp_str(set[i], "rb"))
            exec_rotate(&root_b);
        else if(comp_str(set[i], "rr"))
        {
            exec_rotate(&root_a);
            exec_rotate(&root_b);
        }
        else if(comp_str(set[i], "rra"))
            exec_rrotate(&root_a);
        else if(comp_str(set[i], "rrb"))
            exec_rrotate(&root_b);
        else if(comp_str(set[i], "rrr"))
        {
            exec_rrotate(&root_a);
            exec_rrotate(&root_b);
        }
        else
        {
            write(1, "Not valid.\n", 11);
            return ;
        }
        i++;
    }
    buf = root_a;
    while (buf)
    {
        printf("%d, ", buf->val);
        buf =  buf->next;
    }
    if (is_sorted(root_a) && !root_b)
        printf("SORTED!!!!!\n");
    else
        printf("ERROR\n");
    free_list(root_a);
    free_list(root_b);
    free_set(set);
}

int main(int argc, char **argv)
{
    int i;
    int k;
    char *inst;
    char **set;
    node *root;

    inst = NULL;
    set = NULL;
    root = NULL;
    if (argc <= 1 || *argv[1] == '\n' || *argv[1] == ' ')
        return (0);
    else if (!valid_input(argv) || !in_range(argv))
        return (write(1, "Error\n", 6), 0);
    else
    {
        root = create_list(argv);
        if (duplicates(root))
            return (write(1, "Error\n", 6), 0);
        i = 1;
        k = 0;
        set = malloc(sizeof(char *) * 1);
        if (!set)
            return (free_list(root), 0);
        while (1)
        {
            inst = malloc(sizeof(char) * 4);
            if (!inst)
                return (free_list(root), 0);
            i = read(0, inst, 4);
            if (i == 0)
            {
                free(inst);
                break;
            }
            inst[i - 1] = 0;
            if (i == 3)
            {
                inst[i - 1] = 0;
                inst = realloc(inst, sizeof(char) * i);
                if (!inst)
                    return (1);
                if (k > 0)
                {
                    set = realloc(set, sizeof(char *) * (k + 2));
                    if(!set)
                        return (free(inst), 1);
                }
                set[k++] = inst;
                set[k] = NULL;
            }
            else if (i == 4)
            {
                if (k > 0)
                {
                    set = realloc(set, sizeof(char *) * (k + 2));
                    if(!set)
                        return (free(inst), 1);
                }
                set[k++] = inst;
                set[k] = NULL;
            }
            else
            {
                free(inst);
                inst = NULL;
                break;
            }
        }
        exec_cmnd(root, set);
    }

}