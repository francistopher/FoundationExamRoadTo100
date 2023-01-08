#include <stdio.h>

void sort(int* arr, int l, int m, int r)
{

}

void merge(int* arr, int l, int r)
{
    if (l < r) // there is more than one element to sort
    {
        int m = l + ((r - l) / 2); // find the mid
        merge(arr, l, m);
        merge(arr, m + 1, r);
        sort(arr, l, m, r);

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
    return 0;
}
