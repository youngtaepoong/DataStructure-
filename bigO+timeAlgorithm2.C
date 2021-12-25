#include <stdio.h>

int increment_one(int a) //O(1) 시간 알고리즘: constant time algorithm: 값을 1 증가시킨 후 리턴
{
    return a + 1;
}

int number_of_bits(int n) 
/* O(log n) 시간 알고리즘: l ogarithmic time algorithm: l og의 밑은 2라고 가정:
n을 이진수로 표현했을 때의 비트수 계산 알고리즘 */
{
    int count = 0;
    while (n > 0)
    {
        n = n / 2;
        count += 1;
    }
    return count;
}

int number_of_factors(int n) // O(sqrt(n)) 시간 알고리즘: n의 약수의 개수를 세는 알고리즘
{
    int count = 0, k = 1;
    while (k*k < n)
    {
        if (n%k==0)
        {
            count +=1;
            k += 1;
        }
    }
    return count;
}

int array_sum(int arr1[], int arr2[], int n) // O (n2 ) 시간 알고리즘: quadratic time algorithm: 두 배열 A , B의 모든 정수 쌍의곱의 합을 계산하는 알고리즘
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            sum += arr1[i]*arr2[j];
    return sum;
}

int fibonacci(int n)
/*O(2n ) 이상의 시간이 필요한 알고리즘: exponential time algorithm: k 번 째
피보나치 수 계산하는 재귀 알고리즘 */
{
    if (n <= 1) 
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(void)
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {6, 7, 8, 9, 10};
    int num = 6;

    printf("%d\n", array_sum(array1, array2, num));

    printf("%d", fibonacci(9));
    return 0;
}