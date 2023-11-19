#include "../base.h"

bool is_prime(int n)
{
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0) return false;
	long i = 3;
	while (i * i <= n) {
		if (n % i == 0) return false;
		i += 2;
	}
	return true;
}

int next_prime(int n)
{
	if (n < 2) return 2;
	if (n == 2) return 3;
	if (n % 2 == 0) n++;
	while (!is_prime(n)) n += 2;
	return n;
}
