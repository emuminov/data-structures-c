#include "../hash_set/hash_set.h"
#include <stdio.h>

int main()
{
	printf("%d\n", hash(0) % 53);
	printf("%d\n", hash(1) % 53);
	printf("%d\n", hash(2) % 53);
	printf("%d\n", hash(3) % 53);
	printf("%d\n", hash(4) % 53);
	printf("%d\n", hash(5) % 53);
	printf("%d\n", hash(6) % 53);
	printf("%d\n", hash(7) % 53);
	printf("%d\n", hash(8) % 53);
	printf("%d\n", hash(9) % 53);
	printf("%d\n", hash(10) % 53);
	printf("%d\n", hash(11) % 53);
	printf("%d\n", hash(12) % 53);
	printf("%d\n", hash(13) % 53);
	printf("%d\n", hash(54) % 53);
	printf("%d\n", hash(64) % 53);
	printf("%d\n", hash(84) % 53);
	printf("%d\n", hash(144) % 53);
}
