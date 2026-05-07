#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 500


void insertionSort(int dizi[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = dizi[i];
        j = i - 1;

        while (j >= 0 && dizi[j] > key)
        {
            dizi[j + 1] = dizi[j];
            j--;
        }

        dizi[j + 1] = key;
    }
}


void selectionSort(int dizi[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (dizi[j] < dizi[minIndex])
            {
                minIndex = j;
            }
        }

        temp = dizi[i];
        dizi[i] = dizi[minIndex];
        dizi[minIndex] = temp;
    }
}

int main()
{
    int X[BOYUT];
    int dizi1[BOYUT], dizi2[BOYUT];
    int i;

    clock_t basla, bitir;
    double sure1, sure2;

    srand(time(NULL));

    
    for (i = 0; i < BOYUT; i++)
    {
        X[i] = rand() % 1001;
        dizi1[i] = X[i];
        dizi2[i] = X[i];
    }

    
    basla = clock();
    insertionSort(dizi1, BOYUT);
    bitir = clock();

    sure1 = (double)(bitir - basla) / CLOCKS_PER_SEC;

    
    basla = clock();
    selectionSort(dizi2, BOYUT);
    bitir = clock();

    sure2 = (double)(bitir - basla) / CLOCKS_PER_SEC;

    
    printf("Insertion Sort Siralama Suresi: %f saniye\n", sure1);
    printf("Selection Sort Siralama Suresi: %f saniye\n", sure2);

    if (sure1 < sure2)
        printf("Daha hizli algoritma: Insertion Sort\n");
    else if (sure2 < sure1)
        printf("Daha hizli algoritma: Selection Sort\n");
    else
        printf("Iki algoritmanin suresi esittir.\n");

    return 0;
}