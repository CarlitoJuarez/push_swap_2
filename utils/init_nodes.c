#include "../push_swap.h"

void set_pos(node *root)
{
    node    *cur;
    int     i;

    i = 0;
    cur = root;
    while (cur)
    {
        cur->position = i;
        cur = cur->next;
        i++;
    }
    cur = NULL;
}

void	set_target(node *root_b, node *root_a)
{
	node	*cur;
	node	*tar;
	long	best;
	long	check;
	long	check_2;

	while (root_a)
	{
		cur = root_b;
		check = 1;
		check_2 = 1;
		best = find_min(root_b)->val;
		while (cur)
		{
			if (root_a->val < cur->val)
				check = 0;
			if (root_a->val > cur->val)
				check_2 = 0;
			if (cur->val < root_a->val && cur->val > best)
			{
				best = cur->val;
				tar = cur;
			}
			cur = cur->next;
		}
		if (best == find_min(root_b)->val)
			root_a->target = find_min(root_b);
		else
			root_a->target = tar;
		if (check == 1)
			root_a->target = find_max(root_b);
		else if (check_2 == 1)
			root_a->target = find_max(root_b);
		root_a = root_a->next;
	}
}

void	set_target_2(node *root_b, node *root_a)
{
	node	*cur;
	node	*tar;
	long	best;

	while (root_a)
	{
		cur = root_b;
		best = LONG_MAX;
		while (cur)
		{
			if (cur->val > root_a->val && cur->val < best)
			{
				best = cur->val;
				tar = cur;
			}
			cur = cur->next;
		}
		if (best == LONG_MAX)
			root_a->target = find_min(root_b);
		else
			root_a->target = tar;
		root_a = root_a->next;
	}
}

void	set_price_a(node *root_a)
{
	int len;
	node *cur;

	cur = root_a;
	len = len_of(root_a);
	while (cur)
	{
		if (cur->position < len / 2 + 1)
		{
			if (cur->target->up == 1)
			{
				if (cur->position > cur->target->price)
					cur->price = cur->position;
				else
					cur->price = cur->target->price;
			}
			else
				cur->price = cur->position + cur->target->price;
		}
		else 
		{
			if (cur->target->up == 0)
			{
				if (cur->position > cur->target->price)
					cur->price = len - cur->position + cur->target->price;
				else
					cur->price = cur->target->price;
			}
			else
				cur->price = (len - cur->position) + cur->target->price;
		}
		// printf("THIS: %d TARGET-POS: %d PRICE: %d\n", cur->val, cur->target->position, cur->price);
		cur = cur->next;
	}
}

void	set_price_b(node *root_a, node *root_b)
{
	int		len;
	node	*cur;

	len = len_of(root_a);
	cur = root_a;
	while (cur)
	{
		if (cur->position < (len / 2) + 1)
		{
			// printf("UP\n");
			cur->price = cur->position;
			cur->up = 1;
		}
		else
		{
			cur->price = len - cur->position;
			cur->up = 0;
		}
		// printf("THIS: %d PRICE: %d\n", cur->val, cur->price);
		cur = cur->next;
	}
	set_price_a(root_b);
}
