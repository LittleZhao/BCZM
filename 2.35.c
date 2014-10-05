#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void right_shift(int *, int, int);
    int len, shift, *arr=NULL;
    int i;
    printf("The length of the array: ");
    scanf("%d", &len);
    arr = (int *)malloc(len * sizeof(int));

    printf("The length you want to right shift: ");
    scanf("%d", &shift);

    printf("Array:");
    for (i=0; i<len; i++)
    {
        scanf("%d", arr+i);
    }

    right_shift(arr, len, shift);

    for (i=0; i<len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}

void right_shift(int *arr, int len, int shift)
{
    void reverse(int *, int, int);

    if (shift < 0) //shift is less than zero, mean to left shift;
    {
        shift *= -1;
        shift %= len;
        shift = len - shift;
    }

    shift %= len;
    if (0 != shift)
    {
        reverse(arr, 0, len-shift-1);
        reverse(arr, len-shift, len-1);
        reverse(arr, 0, len-1);
    }
    return;
}

void reverse(int *arr, int f, int t)
{
    for (; f<t; f++, t--)
    {
        arr[f] ^= arr[t];
        arr[t] ^= arr[f];
        arr[f] ^= arr[t];
    }
    return;
}