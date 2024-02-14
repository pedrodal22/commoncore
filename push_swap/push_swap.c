#include <stdio.h>

int push_swap(int array[], int tamanho)
{
    int i;
    int arrayB[tamanho];

    i = 0;
    if(array[0] > array[1])
    {
        arrayB[0] = array[0];
        while (i < tamanho - 1)
        {
            array[i] = array[i + 1];
            printf("output da array[%i] = %i\n", i, array[i]);
            i++;
        }
    }
}

int main(void)
{
    int array[] = {5, 1, 3, 2, 4};
    int tamanho = sizeof(array) / sizeof(array[0]);
    printf("%i\n", tamanho);
    push_swap(array, tamanho);
    
}