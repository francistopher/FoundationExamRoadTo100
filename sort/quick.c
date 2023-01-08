#include <stdio.h>

void swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int partition(int* arr, int l, int r)
{
    int pi = l; // pivot index at low extreme
    l++; // after the pivot we start sorting
    while (l <= r) // continue partitioning while pointers don't cross
    {
        // meet the outerloop requirement while
        while (l <= r && arr[l] <= arr[pi]) // left pointer houses lower/equal value than pivot
            l++;
        while (r >= l && arr[r] > arr[pi]) // right pointer houses higher value than pivot
            r--;
        if (l < r) // potentially not the same value in question
        {
            swap(&arr[l], &arr[r]); // swap two housed values on the wrong side
        }
    }
    swap(&arr[pi], &arr[r]); // putting pivot in place
    return r;
}

void quick(int* ns, int l, int r) // array, left, right
{
    if (l < r) // if left and right don't collide, aka sorting more than one number
    {
        int split = partition(ns, l, r); // save partition 
        quick(ns, l, split - 1); // sort left of partitioned segment
        quick(ns, split + 1, r); // sort right of partitioned segment
    }
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int wow[10] = {7, 4, 3, 2, 5, 6, 1, 9, 8, 0};
    print(wow, 10);
    quick(wow, 0, 9);
    print(wow, 10);
    return 0;
}
