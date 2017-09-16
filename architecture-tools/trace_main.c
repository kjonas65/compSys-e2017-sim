//
// trace_main.c
//

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#include "isa.h"
#include "trace_read.h"

// ---------------------------------------------------------------------------------------------- //

static size_t kCount = 30;

extern int main(int argc, const char * argv[])
{
    (void) argc;
    (void) argv;
    
    FILE * file = fopen("trace.txt", "r");
    
    if (file == NULL)
    {
        fprintf(stderr, "Couldn't open trace file");
        
        exit(EXIT_FAILURE);
    }
    
    Trace_Entry entries [kCount];
    
    if (Trace_read(file, entries, kCount) != kCount)
    {
        fprintf(stderr, "Couldn't read entries\n");
        
        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout, "%6s %8s  %16s  %16s\n", "Cycle:", "Type:", "Destination:", "Value:");
    fprintf(stdout, "---------------------------------------------------\n");
    
    for (size_t index = 0; index < kCount; index++)
    {
        switch (entries[index].type)
        {
            case Trace_Type_reg:
                
                fprintf(stdout, "%6" PRIu64 " %8s  %16s  %016" PRIX64 "\n",
                    entries[index].cycle,
                    "reg",
                    isa_registerAsString((isa_Register) entries[index].destination),
                    entries[index].value
                );
                
                break;
                
            case Trace_Type_mem:
                
                fprintf(stdout, "%6" PRIu64 " %8s  %016" PRIX64 "  %016" PRIX64 "\n",
                    entries[index].cycle,
                    "mem",
                    entries[index].destination,
                    entries[index].value
                );
                
                break;

            case Trace_Type_pc:
                
                fprintf(stdout, "%6" PRIu64 " %8s  %16s  %016" PRIX64 "\n",
                    entries[index].cycle,
                    "pc",
                    "",
                    entries[index].value
                );
                
                break;
        }
    }
    
    fclose(file);
    
    return EXIT_SUCCESS;
}

// ---------------------------------------------------------------------------------------------- //
