#include <stdio.h>

int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
    int x, y, z;
    printf("Enter two number: ");
    scanf("%d%d", &x, &y);
    z = add(x, y);
    printf("\nAddtiton is %d", z);
    return 0;
}