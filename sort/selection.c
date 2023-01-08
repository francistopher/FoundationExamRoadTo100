#include <stdio.h>

void swap(int* v1, int* v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void selection(int* arr, int n)
{
    int i, j, mini;
    for (i = 0; i < n - 1; i++) // iterate without reaching last
    {
        mini = i; // save slot for min i
        for (j = i + 1; j < n; j++) // iterate to last
        {
            if (arr[j] < arr[mini]) // find min index
            {
                mini = j;
            }
        }
        if (mini != i) // swap new min index into place
        {
            swap(&arr[i], &arr[mini]);
        }
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
    int mum[10] = {3, 5, 2, 6, 1, 7, 4, 9, 0, 8};
    print(mum, 10);
    selection(mum, 10);
    print(mum, 10);
    
}
