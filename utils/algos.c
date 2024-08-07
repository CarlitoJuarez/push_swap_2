#include "../push_swap.h"

void exec_algo(node **root_a, node **root_b)
{
    // node *cheapest;
    // node *cur;
    // int len;
    // int pos;


	// printf("A: \n");
	// print_it(*root_a);
	// printf("B: \n");
	// print_it(*root_b);
	// printf("\n");
    // len = len_of(*root_b);

    // if (len == 3)
    //     rev_three_nodes(root_b);
    // cheapest = find_cheapest(*root_b);
    // printf("CHEAPEST: %d\n", cheapest->val);
    // pos = cheapest->position;
    // bring_to_start(pos, len, root_b);
    // printf("root_b:\n");
    // print_it(*root_b);
    // cur = cheapest->target;
    // printf("TAR: %d\n", cur->val);
    // pos = cur->position;
    // printf("TAR_POS: %d\n", cur->position);
    // len = len_of(*root_a);
    // printf("LEN: %d\n", len);
	bring_to_start(root_b, root_a);
    ft_printf("pa\n");
    exec_push(root_a, root_b);
}

void three_nodes(node **root)
{
    node *max;

    max = find_max(*root);
    if (*root == max)
    {
        exec_rotate(root);
        ft_printf("ra\n");
    }
    else if ((*root)->next == max)
    {
        exec_rrotate(root);
        ft_printf("rra\n");
    }
    if ((*root)->val > (*root)->next->val)
    {
        ft_printf("sa\n");
        exec_swap(root);
    }
}

void rev_three_nodes(node **root)
{
    node *min;

    min = find_min(*root);
    if (*root == min)
        exec_rotate(root);
    else if((*root)->next == min)
        exec_rrotate(root);
    if ((*root)->val < (*root)->next->val)
        exec_swap(root);
}