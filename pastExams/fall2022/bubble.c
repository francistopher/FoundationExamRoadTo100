#include <stdio.h>

void swap(int* v1, int* v2) // swaping pointerwise
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void bubble(int* arr, int len) 
{
    for (int i = 0; i < len - 1; i++) // don't need to reach the last element
    {
        for (int j = 0; j < len - i - 1; j++) // the total spots - the sorted elements - that one spot we don't need to reach
        {
            if (arr[j] > arr[j + 1]) // comparing the element and the reached element
            {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}

void printArray(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {6, 8, 3, 9, 4, 7, 5, 1, 2, 0};
    printArray(arr, 10);
    bubble(arr, 10);
    printArray(arr, 10);
    
}
