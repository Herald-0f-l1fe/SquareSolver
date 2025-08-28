#include <stdio.h>
int main()
{
    int ch;
    scanf("%d", &ch);
    int ch2 = 0;
    while(ch > 9)
    {    
        int ch1 = ch;
        while(ch1 != 0)
        {
            ch2 += ch1 % 10;
            ch1 /= 10;
        }
        ch = ch2;
        ch2 = 0;
    }
    printf("%d\n", ch);
}