//I do not think I can find this method in the interview if I do not read this book
#include <stdio.h>
int main(void)
{
    void sum1(int);
    int n;
    scanf("%d", &n);

    sum1(n);
    return 0;
}

void sum1(int n)
{
    int count=0, factor, lower_num, num, higher_num;
    factor = 1;

    while (0 != n / factor)
    {
        lower_num = n - (n / factor) * factor;
        num = (n / factor) % 10;
        higher_num = n / (factor * 10);

        switch(num)
        {
            case 0:
            count += higher_num * factor;
            break;

            case 1:
            count += higher_num * factor + lower_num + 1;
            break;

            default:
            count += (higher_num + 1) * factor;
        }

        factor *= 10;
    }

    printf("%d\n", count);
    return;
}

