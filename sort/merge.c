#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int l, int m, int r)
{
    int larrl = m - l + 1; // calc left side length
    int rarrl = r - m; // calc right side length

    int* larr = (int*)malloc(sizeof(int) * larrl); // create left arr
    int* rarr = (int*)malloc(sizeof(int) * rarrl); // create right arr

    for (int i = 0; i < larrl; i++) // load left arr
        larr[i] = arr[l + i];
    for (int i = 0; i < rarrl; i++) // load right arr
        rarr[i] = arr[m + 1 + i];
   
    int i = 0, j = 0, k = l;

    while (i < larrl && j < rarrl) // i,j indexes not out of bounds
    {
        if (larr[i] <= rarr[j]) // use index to load from whomever is lowest
        {
            arr[k++] = larr[i++]; // left arr i points to lowest
        } else {
            arr[k++] = rarr[j++]; // right arr j points to lowest
        }
    }
    while (i < larrl) // if i index not out of bound
        arr[k++] = larr[i++]; // load using left arr
    while (j < rarrl) // if j index nout ou of bound
        arr[k++] = rarr[j++]; // load using right arr
}

void merge(int* arr, int l, int r)
{
    if (l < r) // there is more than one element to sort
    {
        int m = l + ((r - l) / 2); // find the mid
        merge(arr, l, m); // merge the left
        merge(arr, m + 1, r); // merge the right
        sort(arr, l, m, r); // way after sort the arr

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
    int dam[10] = {6, 4, 8, 5, 3, 7, 1, 2, 9, 0};
    print(dam, 10);
    merge(dam, 0, 9);
    print(dam, 10);
    return 0;
}
