#include <stdio.h>
int minus_of_int(int x);

int main()
{
    int y = 5;
    int x = minus_of_int(y);
    printf("%d",x);
}
int minus_of_int(int x)
{
    return -x;
}