#include "checker_lib.h"

void free_list(node *root)
{
    node *curr;
    node *buf;

    curr = root;
    while (curr)
    {
        buf = curr;
        curr = curr->next;
        free(buf);
    }
    buf = NULL;
    root = NULL;
}

void free_set(char **set)
{
    int i;

    i = 0;
    while (*(set + i))
    {
        free(*(set + i));
        *(set + i) = NULL;
        i++;
    }
    free(set);
}

int valid_input(char **argv)
{
    int i;
    int j;
    char *s;

    i = 1;
    while (argv[i])
    {   
        j = 0;
        s = argv[i];
        while (*(s + j))
        {
            if ( j == 0 && (*s == '-' || *s == '+') )
                j++;
            if ( !(*(s + j) >= '0' && *(s + j) <= '9') )
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int duplicates(node *root)
{
    node *cur;
    node *buf;

    cur = root;
    while (cur)
    {
        buf = cur->next;
        while (buf)
        {
            if (buf->val == cur->val)
                return (1);
            buf = buf->next;
        }
        cur = cur->next;
    }
    return (0);
}

int in_range(char **str)
{
    unsigned int    i;
    unsigned int    j;
    int             sign;
    long            check;

    j = 0;
    while ((str[j]))
    {
        sign = 1;
        i = 0;
        if (*(str[j] + i) == '-' || *(str[j] + i) == '+')
        {
            if (*(str[j] + i) == '-')
                sign = -1;
            i++;
        }
        check = 0;
        while (*(str[j] + i))
        {
            check = check * 10 + (*(str[j] + i) - '0');
            i++;
        }
        check *= sign;
        if (check < INT_MIN || check > INT_MAX)
            return (0);
        j++;
    }
    return (1);
}

int comp_str(char *s1, char *s2)
{
    int i;

    i = 0;
    while (*(s1 + i))
    {
        printf("I: %d\n", i);
        printf("I: %c\n", *(s1 + i));
        if (*(s1 + i) != *(s2 + i))
            return (0);
        i++;
    }
    return (1);
}

int is_sorted(node *root)
{
    node *cur;
    node *buf;

    cur = root;
    while (cur)
    {
        buf = cur->next;
        while (buf)
        {
            if (cur->val > buf->val)
                return (0);
            buf = buf->next;
        }
        cur = cur->next;
    }
    return (1);
}