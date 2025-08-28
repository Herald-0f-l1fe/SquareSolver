#include<TXLib.h>
#include <stdio.h>
int minn(int kor[][2], int n);
int main()
{
    int n = 0;
    int s = 0;
    int korobok = 0;
    float konf = 0;
    scanf("%d", &n);
    int mag[n][2] = {{}};
    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &mag[i][0], &mag[i][1]);
    }
    scanf("%d", &s);
    int uk = minn(mag, n);
    while ((s >= mag[uk][0]) && (s != 0))
    {
        int uk = minn(mag, n);
        if (s>=mag[uk][0])
        {
            s -= mag[uk][0];
            konf += mag[uk][1];
            korobok ++;
            mag[uk][0] =0;
        }
        uk = minn(mag, n);
    }
}

int minn(int kor[][2], int n)
{   
    int mi = kor[0][0];
    int ukaz = 0;
    for (int i = 0; i<n; i++)
    {
        if ((mi>kor[i][0]) &&  (kor[i][0] != 0))
        {
            mi = kor[i][0];
            ukaz = i;
        }
    }
    return ukaz;
}   