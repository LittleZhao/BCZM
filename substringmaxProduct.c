#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int solution(int *, int);
    int n, *arr=NULL, index;

    int i;
    printf("The number of the array:");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++)
    {
        scanf("%d", arr+i);
    }
    index = solution(arr, n);

    printf("Discard position %d\n", index);
    free(arr);
    arr = NULL;
    return 0;
}

int solution(int *arr, int n)
{
    int zero_num=0, negative_num=0, zero_index = -1,max_negative_index=-1, min_positive_index=-1, min_negative_index = -1;
    int i;
    if (2 > n)
    {
        return -1;
    }

    for (i=0; i<n; i++)
    {
        if (0 == arr[i])
        {
            zero_index = i;
            zero_num++;
            if (1 < zero_num)
            {
                return i;
            }
        }
        else if (0 > arr[i])
        {
            negative_num++;
            if (max_negative_index >= 0)
            {
                if (arr[max_negative_index] < arr[i])
                {
                    max_negative_index = i;
                }
            }
            else
            {
                max_negative_index = i;
            }

            if (min_negative_index >= 0)
            {
                if (arr[min_negative_index] > arr[i])
                {
                    min_negative_index = i;
                }
            }
            else
            {
                min_negative_index = i;
            }
        }
        else
        {
            if (min_positive_index >= 0)
            {
                if (arr[min_positive_index] > arr[i])
                {
                    min_positive_index = i;
                }
            }
            else
            {
                min_positive_index = i;
            }
        }
    }

    if (1 == zero_num)
    {
        return zero_index;
    }

    if (negative_num > 0)
    {
        if (negative_num == n)
        {
            if (0 == negative_num % 2)
            {
                return min_negative_index;
            }
            else
            {
                return max_negative_index;
            }
        }
        else if (0 != negative_num % 2)
        {
            return max_negative_index;
        }
    }
    return min_positive_index;
}