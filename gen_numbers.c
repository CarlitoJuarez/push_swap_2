#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    for (int i = 0; i < 500; i++)
    {
        int high = rand();
        int low = rand();
        int combined = ((high << 16) | low);

        if (combined < INT_MIN)
            combined += INT_MIN - INT_MIN + 1;
        printf("%d ", combined - '0');
    }
}