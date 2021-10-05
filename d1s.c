#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int triFusion(int *t, int len)
{
    if (len < 10)
    {
        triInsertion(t, len);
    }
    else
    {
        int lenU = len / 2;
        int U[lenU];
        for (int i = 0; i < lenU; i++)
        {
            U[i] = t[i];
        }
        triFusion(U, lenU);

        int lenV = len - lenU;
        int V[lenV];
        for (int i = lenU; i < len; i++)
        {
            V[i - lenU] = t[i];
        }

        triFusion(V, lenV);

        fusion(U, lenU, V, lenV, t);
    }
}

int fusion(int *u, int lenU, int *v, int lenV, int *w)
{
    int i = 0;
    int j = 0;

    for (int k = 0; k < lenU + lenV; k++)
    {
        if (j < lenV && (i >= lenU || u[i] >= v[j]))
        {
            w[k] = v[j];
            j++;
        }
        else if (i < lenU && (j >= lenV || v[j] >= u[i]))
        {
            w[k] = u[i];
            i++;
        }
    }
    return 0;
}

int triInsertion(int *t, int lenT)
{
    int i = 1;
    while (i < lenT)
    {
        int j = i;
        while (j > 0 && t[j - 1] > t[j])
        {
            int swap = t[j];
            t[j] = t[j - 1];
            t[j - 1] = swap;
            j--;
        }
        i++;
    }
    return 0;
}

int printArray(int t[], int len)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", t[i]);
    }
    printf("... ");
    for (int i = len - 10; i < len; i++)
    {
        printf("%i ", t[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    int lenT;
    scanf("%i", &lenT);

    int t[lenT];

    for (int i = 0; i < lenT; i++)
    {
        t[i] = rand();
    }

    clock_t start = clock();
    triFusion(t, lenT);
    clock_t end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;

    printArray(t, lenT);
    printf("Executed in %f sec\n", total);

    return 0;
}
