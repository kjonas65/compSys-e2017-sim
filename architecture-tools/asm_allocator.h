//
// Nis Wegmann, 2017
//
// asm_allocator.h
//

#ifndef __ALLOCATOR_H__
#define __ALLOCATOR_H__

#include <stddef.h>

// ---------------------------------------------------------------------------------------------- //

//
// Allocation failure callback.
//
typedef void Allocator_AllocFailureCallback
    (
        void
    );

// ---------------------------------------------------------------------------------------------- //

//
// Opaque allocator type.
//
typedef struct Allocator Allocator;

// ---------------------------------------------------------------------------------------------- //

//
// Creates an allocator.
//
Allocator * Allocator_create
    (
        size_t,                                 // Capacity.
        Allocator_AllocFailureCallback          // Allocation failure callback.
    );

// ---------------------------------------------------------------------------------------------- //

//
// Destroys an allocator.
//
void Allocator_destroy
    (
        Allocator *                             // Allocator.
    );

// ---------------------------------------------------------------------------------------------- //

//
// Allocates a memory block.
//
void * Allocator_alloc
    (
        Allocator *,                            // Allocator.
        size_t,                                 // Amount of bytes to allocate.
        size_t                                  // Alignment.
    );

// ---------------------------------------------------------------------------------------------- //

#endif // __ALLOCATOR_H__
