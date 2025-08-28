#include <stdio.h>
#include <math.h>
int main()
{
    float Ta = 0, Tb = 0, Tc = 0;
    int N = 0, M = 0, K = 0;
    scanf("%d %d %d %f %f %f", &N, &M, &K, &Ta, &Tb, &Tc);
    float stairs = abs(N-M)*(Tc);
    //printf("%g\n", stairs);
    float elevator = Ta*(abs(K-N)+abs(N-M)) + 3*Tb;
    //printf("%g\n", elevator);
    if (stairs < elevator)
    {
        printf("stairs");
    }
    else
    {
        printf("elevator");
    }
    return 0;
    
}