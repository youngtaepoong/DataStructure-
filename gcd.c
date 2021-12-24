#include <stdio.h>
//Great Common Divisor & Least Common Multiple

int gcd(int a, int b)
{
	while (a*b!= 0)	//Loop 'a', 'b' until: 'a' or 'b' is 0
	{
		if (a > b)	
			a = a -b;	
		else
			b =  b -a;
		return a+b; // if not 0 means gcd ??sum = gcd  섹스
	}
}

int main(void)
{
	int n1, n2;
	
	n1 = 5;
	n2 = 10;
	
	printf("%d", gcd(n1, n2));
	printf("sex섹스");

	return 0;
}
