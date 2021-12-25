#include <stdio.h>

int arrayMax(int arr[], int cnt)
{
    int currentMax = arr[0];
    for(int i = 1; i < cnt; i++)
    {
        if (currentMax < arr[i])
            currentMax = arr[i];
    }
    return currentMax;
}


int main(void)
{
    int numArr[5] = {5, -1, 6, -7, 9};
    int arrCnt = 5;

    printf("%d", arrayMax(numArr, arrCnt));
}