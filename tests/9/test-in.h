#define ASSERT(truth)                                   \
do { \
  _clib_error (CLIB_ERROR_ABORT, 0, 0, \
             "%s:%d (%s) assertion `%s' fails",   \
                 # truth); \
} while (0)



ASSERT (mheap_offset_is_valid (v, uo));

#define macro(a) : "=a" (a)
macro(blah)


