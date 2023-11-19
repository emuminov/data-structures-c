#include "../hash_set/hash_set.h"
#include <stdio.h>

int main()
{
	hs_set *set = hs_new();
	hs_insert(0, set);
	hs_insert(1, set);
	hs_insert(2, set);
	hs_insert(3, set);
	hs_insert(4, set);
	hs_insert(5, set);
	hs_insert(6, set);
	hs_insert(7, set);
	hs_insert(8, set);


	hs_remove(2, set);
	hs_remove(2, set);
	hs_remove(3, set);
	hs_remove(4, set);
	hs_remove(5, set);

	hs_insert(9, set);
	hs_insert(10, set);
	hs_insert(11, set);
	hs_insert(12, set);
	hs_insert(13, set);
	hs_insert(14, set);
	hs_insert(15, set);
	hs_insert(144, set);
	hs_insert(1550, set);
	hs_insert(15550, set);
	printf("%d\n", hs_has(0, set));
	printf("%d\n", hs_has(1, set));
	printf("%d\n", hs_has(2, set));
	printf("%d\n", hs_has(3, set));
	printf("%d\n", hs_has(4, set));
	printf("%d\n", hs_has(5, set));
	printf("%d\n", hs_has(6, set));
	printf("%d\n", hs_has(7, set));
	printf("%d\n", hs_has(8, set));
	printf("%d\n", hs_has(9, set));
	printf("%d\n", hs_has(10, set));
	printf("%d\n", hs_has(11, set));
	printf("%d\n", hs_has(12, set));
	printf("%d\n", hs_has(13, set));
	printf("%d\n", hs_has(14, set));
	printf("%d\n", hs_has(15, set));
	printf("%d\n", hs_has(144, set));
	printf("%d\n", hs_has(1550, set));
	printf("%d\n", hs_has(15550, set));
	hs_print(set);
	hs_delete(set);
}
