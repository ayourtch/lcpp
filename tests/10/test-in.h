
#define clib_error_return_code(e,code,flags,args...) _clib_error_return((e),(code),(flags),(char *)clib_error_function,args)


#define clib_error_return(e,args...) clib_error_return_code(e,0,0,args)


clib_error_return (0, "failed to allocate %wd bytes of I/O memory", n_bytes);


