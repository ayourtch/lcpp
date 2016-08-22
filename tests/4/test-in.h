#define CLIB_DEBUG 0

#ifndef CLIB_ASSERT_ENABLE
#define CLIB_ASSERT_ENABLE (CLIB_DEBUG > 0)
#endif

#define ASSERT(truth)                                   \
do {                                                    \
  if (CLIB_ASSERT_ENABLE && ! (truth))                  \
    {                                                   \
      _clib_error (CLIB_ERROR_ABORT, 0, 0,              \
                   "%s:%d (%s) assertion `%s' fails",   \
                   __FILE__,                            \
                   (uword) __LINE__,                    \
                   clib_error_function,                 \
                   # truth);                            \
    }                                                   \
} while (0)


#define VALGRIND_DO_CLIENT_REQUEST(                               \
        _zzq_rlval, _zzq_default, _zzq_request,                   \
        _zzq_arg1, _zzq_arg2, _zzq_arg3, _zzq_arg4, _zzq_arg5)    \
  { volatile unsigned long long int _zzq_args[6];                 \
    volatile unsigned long long int _zzq_result;                  \
    _zzq_args[0] = (unsigned long long int)(_zzq_request);        \
    _zzq_args[1] = (unsigned long long int)(_zzq_arg1);           \
    _zzq_args[2] = (unsigned long long int)(_zzq_arg2);           \
    _zzq_args[3] = (unsigned long long int)(_zzq_arg3);           \
    _zzq_args[4] = (unsigned long long int)(_zzq_arg4);           \
    _zzq_args[5] = (unsigned long long int)(_zzq_arg5);           \
    __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
                     /* %RDX = client_request ( %RAX ) */         \
                     "xchgq %%rbx,%%rbx"                          \
                     : "=d" (_zzq_result)                         \
                     : "a" (&_zzq_args[0]), "0" (_zzq_default)    \
                     : "cc", "memory"                             \
                    );                                            \
    _zzq_rlval = _zzq_result;                                     \
  }





/* Modern GCC will optimize the static routine out if unused,
   and unused attribute will shut down warnings about it.  */
static int VALGRIND_PRINTF(const char *format, ...)
   __attribute__((format(__printf__, 1, 2), __unused__));
static int
VALGRIND_PRINTF(const char *format, ...)
{
   unsigned long _qzz_res;
   va_list vargs;
   va_start(vargs, format);
   VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0, VG_USERREQ__PRINTF,
                              (unsigned long)format, (unsigned long)vargs,
                              0, 0, 0);
   va_end(vargs);
   return (int)_qzz_res;
}




