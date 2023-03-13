#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
//  sap xep mang theo thu tu tang dan
//  liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                              7 xuat hien 2 lan
//                                              8 xuat hien 3 lan

typedef struct
{
    uint8_t size;
    uint8_t *firstAdd;
} typeArray;

int randomA(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}


void randomArray(typeArray *value, uint8_t length)
{
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t) * value->size);
    int r;
    for (int i = 0; i < value->size; ++i)
    {
        value->firstAdd[i] = randomA(0, 10);
    }
}



void SortArr(typeArray *arr)
{
    int tg;
    for (int i = 0; i < (arr->size) - 1; i++)
    {
        for (int j = i + 1; j < (arr->size); j++)
        {
            if (arr->firstAdd[i] > arr->firstAdd[j])
            {
                // Hoan vi 2 so a[i] va a[j]
                tg = arr->firstAdd[i];
                arr->firstAdd[i] = arr->firstAdd[j];
                arr->firstAdd[j] = tg;
            }
        }
    }
}


// arr[] = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 7, 8, 8, 10}
//  Index   0  1  2  3  4  5 ...   
void countArr_c1(typeArray *arr)
{
    for (int i = 0; i < (arr->size) ; i++)
    {
        int dem = 1;
    loop:
        if (arr->firstAdd[i] == arr->firstAdd[i + 1])
        {
            dem++;
            i++;
            goto loop;
        }
        printf("\nphan tu [%d] xuat hien so lan %d", arr->firstAdd[i], dem);
    }
}


// arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// Index    0  1  2  3  4  5 .....
void countArr_c2(typeArray *arr)
{
    for (int i = 0; i < (arr->size); i++)
    {
        int dem = 1;
        if (arr->firstAdd[i] == 11)
            continue;
        for (int j = i + 1; j < (arr->size); j++)
        {
            if (arr->firstAdd[i] == arr->firstAdd[j])
            {
                dem++;
                arr->firstAdd[j] = 11;
            }
        }
        printf("\nphan tu [%d] xuat hien so lan %d", arr->firstAdd[i], dem);
    }
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 20);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n", i, arr.firstAdd[i]);
    }

    SortArr(&arr);
    printf("sap xep thu tu tang dan \n");
    for (int i = 0; i < arr.size; i++)
    {
        printf(" %d  ", arr.firstAdd[i]);
    }

    // countArr_c1(&arr);

    countArr_c2(&arr);
    return 0;
}
