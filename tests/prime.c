#include "../prime/prime.h"

#include <stdio.h>
int main()
{
	printf("%d\n", next_prime(-5));
	printf("%d\n", next_prime(0));
	printf("%d\n", next_prime(1));
	printf("%d\n", next_prime(2));
	printf("%d\n", next_prime(3));
	printf("%d\n", next_prime(4));
	printf("%d\n", next_prime(5));
	printf("%d\n", next_prime(6));
	printf("%d\n", next_prime(7));
	printf("%d\n", next_prime(8));
	printf("%d\n", next_prime(9));
	printf("%d\n", next_prime(10));
	printf("%d\n", next_prime(11));
	printf("%d\n", next_prime(12));
	printf("%d\n", next_prime(15));
	printf("%d\n", next_prime(50));
	printf("%d\n", next_prime(100));
	printf("%d\n", next_prime(120));
	printf("%d\n", next_prime(140));
	printf("%d\n", next_prime(300));
	printf("%d\n", next_prime(500));
	printf("%d\n", next_prime(2147483646));
	printf("%d\n", next_prime(2147483647));
	printf("%d\n", next_prime(-2147483648));
}
