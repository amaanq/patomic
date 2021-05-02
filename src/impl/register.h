#ifndef PATOMIC_REGISTER_H
#define PATOMIC_REGISTER_H

#include <stddef.h>

#include <patomic/impl/ids.h>
#include <patomic/types/ops.h>
#include <patomic/types/memory_order.h>

#include "null/null.h"

/*
 * REGISTER STRUCT
 *
 * - id: implementation id from ids.h
 * - fp_create_ops: (byte_width, order)
 * - fp_create_explicit_ops: (order)
 *
 * NOTE: - id doesn't HAVE to be provided from ids.h, but if it
 *         isn't, it won't be explicitly selectable by a user
 *       - the behaviour is UNDEFINED if two ids have the same value
 */
typedef struct {
    int id;
    patomic_ops_t (* fp_create_ops) (size_t, patomic_memory_order_t);
    patomic_ops_explicit_t (* fp_create_ops_explicit) (size_t);
} patomic_impl_register_t;

/*
 * REGISTER ARRAY
 *
 * - there is NO REQUIREMENT that id matches index
 * - nor that NULL must be the final element
 */
patomic_impl_register_t patomic_impl_register[] = {
    {
        patomic_impl_id_NULL,
        patomic_impl_create_ops_null,
        patomic_impl_create_ops_explicit_null
    }
};

#endif  /* !PATOMIC_REGISTER_H */
