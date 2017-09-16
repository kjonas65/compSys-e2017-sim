//
// Nis Wegmann, 2017
//
// asm_allocator.c
//

#include "asm_allocator.h"

#include <stdlib.h>

// ---------------------------------------------------------------------------------------------- //

typedef struct Page
{
    size_t size;                    // Amount of bytes allocated in the page.
    struct Page * previous;         // The previously allocated page.
    unsigned char memory [];        // Memory block.
}
Page;

// ---------------------------------------------------------------------------------------------- //

struct Allocator
{
    size_t capacity;                // Capacity of each page.
    Page * page;                    // Current page.
    Allocator_AllocFailureCallback
        * allocFailureCallback;     // Allocation failure callback.
};

// ---------------------------------------------------------------------------------------------- //

//
// Creates a new page.
//
static Page * Page_create(Page * previous, size_t capacity)
{
    // Allocate the page.
    
    Page * page = malloc(sizeof(Page) + capacity);
    
    // Check that the page was allocated.
    
    if (page == NULL)
    {
        return NULL;
    }
    
    // Initialize the page.
    
    page->previous = previous;
    page->size = 0;
    
    // Return the page.
    
    return page;
}

// ---------------------------------------------------------------------------------------------- //

extern Allocator * Allocator_create(size_t capacity, Allocator_AllocFailureCallback * callback)
{
    // Allocate the allocator.
    
    Allocator * allocator = malloc(sizeof(Allocator));
    
    // Check that the allocator was allocated.
    
    if (allocator == NULL)
    {
        return NULL;
    }
    
    // Create the first page.
    
    Page * page = Page_create(NULL, capacity);
    
    // Check that the page was created.
    
    if (page == NULL)
    {
        // If not, free the allocator.
        
        free(allocator);
        
        return NULL;
    }
    
    // Initialize the allocator.
    
    allocator->capacity = capacity;
    allocator->page = page;
    allocator->allocFailureCallback = callback;
    
    // Return the allocator.
    
    return allocator;
}

// ---------------------------------------------------------------------------------------------- //

extern void Allocator_destroy(Allocator * allocator)
{
    // Release the pages.
    
    while (allocator->page != NULL)
    {
        Page * page = allocator->page;
        
        allocator->page = allocator->page->previous;
        
        free(page);
    }
    
    // Release the allocator.
    
    free(allocator);
}

// ---------------------------------------------------------------------------------------------- //

extern void * Allocator_alloc(Allocator * allocator, size_t size, size_t alignment)
{
    (void) alignment;
    
    // Make sure that the requested amount of bytes fits within a page.
    
    if (size > allocator->capacity)
    {
        // If not, call the allocation failure callback (if set).
        
        if (allocator->allocFailureCallback != NULL)
        {
            allocator->allocFailureCallback();
            
            abort();
        }
        
        return NULL;
    }
    
    // If the page is full then create a new page.
    
    if (size + allocator->page->size > allocator->capacity)
    {
        Page * page = Page_create(allocator->page, allocator->capacity);
        
        // Check that the page was created succesfully.
        
        if (page == NULL)
        {
            // If not, call the allocation failure callback (if set).
            
            if (allocator->allocFailureCallback != NULL)
            {
                allocator->allocFailureCallback();
                
                abort();
            }
            
            return NULL;
        }
        
        // Link to the old page.
        
        allocator->page = page;
    }
    
    // Allocate the requested amount of bytes.
    
    void * block = allocator->page->memory + allocator->page->size;
    
    allocator->page->size += size;
    
    // Return a pointer to the memory block.
    
    return block;
}

// ---------------------------------------------------------------------------------------------- //
