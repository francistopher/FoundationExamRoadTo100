#include <stdio.h>

void insertion(int *arr, int n)
{
    int i, j, s;
    for (i = 1; i < n; i++) // iterate after beginning
    {
        s = arr[i]; // space saved for after beginning
        j = i - 1; // index before beginning saved
        while (j >= 0 && arr[j] > s) // j is greater than -1 and element at j is greater space saved
        {
            arr[j + 1] = arr[j]; // set the one before to the after
            j -= 1; // decrement j
        }
        arr[j + 1] = s; // for whome occupied saved space slide into j
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
    int arr[10] = {7, 5, 9, 1, 2, 0, 3, 4, 6, 8};
    print(arr, 10);
    insertion(arr, 10);
    print(arr, 10);
    return 0;
}
