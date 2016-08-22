#define some_macro(P,E) int (i) = (E) - (P);

#define ASSERT(truth) truth

ASSERT(asd)
ASSERT(some_macro(a, _e))
ASSERT(!some_macro(a, _e))
ASSERT(asd)

