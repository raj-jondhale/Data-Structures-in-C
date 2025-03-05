#include <stdio.h>

void toh(int n, char source, char dest, char temp)
{
    if (n > 0)
    {
        toh(n - 1, source, temp, dest);
        printf("\n move %d from tower %c to %c", n, source, dest);
        toh(n - 1, temp, dest, source);
    }
}

int main()
{
    int n;
    printf("Enter no of disk ");
    scanf("%d", &n);
    toh(n, 'A', 'C', 'B');
    return 0;
}