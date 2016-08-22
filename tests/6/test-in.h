

#define vec_validate_ha(V,I,H,A)                                        \
do {                                                                    \
  word _v(i) = (I);                                                     \
} while (0)



#define vec_validate_aligned(V,I,A) vec_validate_ha(V,I,0,A)

#define clib_bitmap_vec_validate(v,i) vec_validate_aligned((v),(i),sizeof(uword))


clib_bitmap_vec_validate (ai, i0);

