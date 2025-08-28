#include <stdio.h>
void sorting(int arr_s[], int n, int z);
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n] = {};
    int po = 0;
    int ot = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] >= 0)
        {
            po++;
        }
        else
        {
            ot++;
        }
    }

    int arr_p[po] = {};
    int arr_o[ot] = {};
    po = ot = 0;

    for (int i = 0; i <n; i++)
    {
        if (arr[i] >= 0)
        {
            arr_p[po] = arr[i];
            po++;
        }
        else 
        {
            arr_o[ot] = -arr[i];
            ot++;
        }
    }
    sorting(arr_p, po, 1);
    sorting(arr_o, ot, 0);
    return 0;
}
void sorting(int arr_s[], int n, int z)
{
    for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j>i; j--)
            {
                int prom = 0;
                if (arr_s[i] > arr_s[j])
                {
                    prom = arr_s[i];
                    arr_s[i] = arr_s[j];
                    arr_s[j] = prom;
                }
            }
        }
    if (z)
    {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr_s[i]);
    }
    }
    else
    {
        for (int i = 0; i<n; i++)
        {
            printf("%d ", -arr_s[i]);
        }
    }
}