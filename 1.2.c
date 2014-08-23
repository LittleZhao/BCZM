//but here I think I use two variables
#include <stdio.h>
struct
{
    /* data */
    int a;
    int b;
} p;

int main(void)
{
    for (p.a=1; p.a<=9; p.a++)
        for (p.b=1; p.b<=9; p.b++)
        {
            if (p.a%3 != p.b%3)
            {
                printf("A=%d, B=%d\n", p.a, p.b);
            }
        }

    return 0;
}