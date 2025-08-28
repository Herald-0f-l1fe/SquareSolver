#include <stdio.h>
int maxx(int a, int b, int c);
int minn(int a, int b, int c);
int main()
{
    int a = 0, b = 0, c = 0;
    int max = 0, min = 0, ras = 0;
    scanf("%d %d %d", &a, &b, &c);
    max  = maxx(a, b, c);
    min  = minn(a,b,c);
    ras = max-min;
    printf("%d", ras);
    return 0;
    
}
int maxx(int a1, int b1, int c1)
{   
    int d = 0;
    if (a1<b1)
    {
        d = b1;
    }
    else 
    {
        d = a1;
    }

    if (d<c1)
    {
        d = c1;
    }
    return d;
}

int minn(int a1, int b1, int c1)
{   
    int d = 0;
    if (a1>b1)
    {
        d = b1;
    }
    else 
    {
        d = a1;
    }

    if (d>c1)
    {
        d = c1;
    }
    return d;
}