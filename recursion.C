#include <stdio.h>
int sum(int n) // O(n)
{
	int s = 0;
	for (int i =0; i < n + 1; i++)
        s += i;
    return s;
}

int sum2(int a, int b)
{
    int m = 0;

    if (a == b)
        return a;
    if (a > b)
        return 0;
    
    m = (a+b)/2;
    return sum2(a, m) + sum2(m+1, b);
}
/*  sum(2,7) = (sum(2,4) + sum(5,7))
    = ((sum(2,3)+sum(4,4)) + (sum(5,6)+sum(7,7)))
    = (((sum(2,2)+sum(3,3)) + 4) + ((sum(5,5)+sum(6,6))+7))
    = (((2+3)+4) + ((5+6)+7))
    = 27   */

int factorial(int n)
{
    if (n == 1)
        return n;
    else
        return n * factorial(n-1);
}

int find_max(int arr[], int n)
{
    int max;
    if (n == 0)
        return arr[0];
    max = find_max(arr, n - 1);
    arr[n] = (max < arr[n]) ? arr[n] : max;

    return arr[n];
}


int main(void)
{
    printf("%d\n", sum(5));

	printf("%d\n", sum2(2, 7));

    printf("%d\n", factorial(4));

    int numArr[] = {70, 40, 50, 60, 80, 30, 10, 20, 90};
    int arrSize = (sizeof(numArr) / sizeof(int));
    printf("%d", find_max(numArr, arrSize));
}