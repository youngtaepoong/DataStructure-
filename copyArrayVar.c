#include <stdio.h>

int main(void)
{
    int A[5] = {10, 20, 30};
    int B[5], i, x = 2018, y = 0;

    y = x;
    for (i= 0; i <5; i++)
        B[i] = A[i];
    
    printf("���� ���� ���: x = %d, y = %d\n", x, y);
    printf("�迭 ���� ���: \n");

    for (i = 0; i < 5; i++)
    {
        printf("A[%d] = %d\t", i, A[i]);
        printf("B[%d] = %d\t", i, B[i]);
    }
}