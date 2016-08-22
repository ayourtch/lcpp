#define ASSERT(truth) truth

#define pool_is_free(P,E) uword _pool_var (i) = (E) - (P);


#define pool_elt_at_index(p,i)                  \
({                                              \
  ASSERT (! pool_is_free (p, _e));              \
})


f = pool_elt_at_index (bm->buffer_free_list_pool, free_list_index);

