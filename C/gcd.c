

#include "gcd.h"

/*
 * swap - swap value of @a and @b
 */
#define swap(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

/* Greatest common divisor */
//最大的公约数
unsigned long gcd(unsigned long a, unsigned long b)
{
	unsigned long r;

	// if (a < b)
	// 	swap(a, b);

	if (!b)
		return a;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}