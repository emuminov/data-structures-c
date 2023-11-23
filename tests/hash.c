#include "../hash_set/hash_set.h"
#include <stdio.h>

int main()
{
	printf("%d\n", (int) (hash(0) % 53));
	printf("%d\n", (int) (hash(1) % 53));
	printf("%d\n", (int) (hash(2) % 53));
	printf("%d\n", (int) (hash(3) % 53));
	printf("%d\n", (int) (hash(4) % 53));
	printf("%d\n", (int) (hash(5) % 53));
	printf("%d\n", (int) (hash(6) % 53));
	printf("%d\n", (int) (hash(7) % 53));
	printf("%d\n", (int) (hash(8) % 53));
	printf("%d\n", (int) (hash(9) % 53));
	printf("%d\n", (int) (hash(10) % 53));
	printf("%d\n", (int) (hash(11) % 53));
	printf("%d\n", (int) (hash(12) % 53));
	printf("%d\n", (int) (hash(13) % 53));
	printf("%d\n", (int) (hash(54) % 53));
	printf("%d\n", (int) (hash(64) % 53));
	printf("%d\n", (int) (hash(84) % 53));
	printf("%d\n", (int) (hash(144) % 53));
}
