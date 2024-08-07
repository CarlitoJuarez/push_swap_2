#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2)
{
    int buf;

    buf = *p1;
    *p1 = *p2;
    *p2 = buf;
}

int sort(int *arr, int size, int a)
{
    int i;
    int count[10];
    int *output;

    i = 0;
    while (i < size)
        count[arr[i++] / a % 10]++;
    i = 1;
    while (i < 10)
        count[i] += count[i - 1];
    i = size - 1;
    while (i >= 0)
    {
        output[count[(arr[i] / a) % 10] - 1] = arr[i];
        count[(arr[i] / a) % 10]--;
        i--;
    }
    i = 0;
    while (i < size)
    {
        arr[i] = output[i];
        i++;
    }
}

int max(int *arr, int size)
{
    int i;
    int max;

    i = 0;
    max = 0;
    while (i < size)
    {
        if (arr[i] > max)
            max = arr[i];
        i++;
    }
    return (max);
}

void raddix_sort(int *arr, int size)
{
    int max;
    int a;

    max = get_max(arr, size);
    a = 1;
    while (max / a)
    {
        sort(arr, size, a);
        a *= 10;
    }
}

int main(void)
{
    int *arr;
    arr = malloc(sizeof(int) * 5);
    arr[0] = 3020;
    arr[1] = 1940;
    arr[2] = 4;
    arr[3] = 22;
    arr[4] = 3;
    unsigned long i;

    i = 0;
    while (i < 5)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\n");
    // merge sort algorithm
    raddix_sort(arr, 5);
    printf("PIMMEL\n");
    i = 0;
    while (i < 5)
    {
        printf("%d, ", arr[i]);
        i++;
    }
}