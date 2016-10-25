#include "stdio.h"
#include "stdlib.h"

#define MAXLEN 999999
#define K 100000

void HeapAdjust(int array[], int i, int Length)
{
    int child, temp;
    for(temp = array[i]; 2*i+1 < Length; i = child){
        child = 2*i+1;
        if(child < Length-1 && array[child+1] < array[child]){
            child++;
        }

        if(temp > array[child]){
            array[i] = array[child];
        } else{
            break;
        }

        array[child] = temp;
    }
}

void Swap(int *a, int *b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

int GetMin(int array[], int Length, int k)
{
    int min = array[0];
    Swap(&array[0], &array[Length-1]);

    int child, temp;
    int i = 0, j = k-1;
    for(temp = array[0]; j > 0 && 2*i+1 < Length; --j,i=child){
        child = 2*i+1;
        if(child < Length-1 && array[child+1]<array[child]){
            child++;
        }

        if(temp > array[child]){
            array[i] = array[child];
        } else{
            break;
        }

        array[child] = temp;
    }

    return min;
}

/*
 * array:数据
 * Length:节点数
 * k:前TOP数据
 * */
void Kmin(int array[], int Length, int k)
{
    int i = 0;
    for(i = Length/2-1; i >= 0; --i){
        HeapAdjust(array, i, Length);
    }

    int j = Length;
    for(i = k; i > 0; --i,--j){
        int min = GetMin(array, j ,i);
        printf("%d,", min);
    }
}

int main() {
    int array[MAXLEN];
    for(int i = MAXLEN; i > 0; --i){
        array[MAXLEN-i] = i;
    }
    Kmin(array, MAXLEN, K);
    return 0;
}