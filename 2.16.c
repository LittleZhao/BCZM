//gcd
#include <stdio.h>

int main(void)
{
    int gcd(int, int);
    int i, j, r;

    printf("Two integer: \n");
    scanf("%d %d", &i, &j);
    r = gcd(i, j);
    printf("Their gcd is %d\n", r);
    return 0;
}

int gcd(int x, int y)
{
    if (y > x)
    {
        return gcd(y, x);
    }

    if (0 == y)
    {
        return x;
    }

    if (0 == x%2 && 0 == y%2)
    {
        return (gcd(x>>1, y>>1) << 1);
    }

    if (0 == x%2)
    {
        return gcd(x>>1, y);
    }
    if (0 == y%2)
    {
        return gcd(x, y>>1);
    }

    return gcd(y, x - y);
}