#define CLIB_PACKED(x)  x __attribute__ ((packed))


#define clib_mem_unaligned(pointer,type) \
  (((struct { CLIB_PACKED (type _data); } *) (pointer))->_data)

clib_mem_unaligned(_data, u16)


