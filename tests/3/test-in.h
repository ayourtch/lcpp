#define BINARY -0b1001 /* -9 */
#define __P(x) x
assert __P((BINARY == -9, "parse, binary literal fails"))




#define some_macro(P,E) int (i) = (E) - (P);

#define ASSERT(truth) truth

ASSERT(asd)
ASSERT(some_macro(a, _e))
ASSERT(!some_macro(a, _e))
ASSERT(asd)

