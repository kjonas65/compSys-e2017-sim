//
// Nis Wegmann, 2017
//
// sim_step.h
//

#ifndef __SIM_STEP_H__
#define __SIM_STEP_H__

#include "ano.h"
#include "isa.h"

// ---------------------------------------------------------------------------------------------- //

//
// .
//
isa_Status sim_step
    (
        isa_State * restrict,                   // State. (nonnull)
        FILE *,                                 // Trace-file. (nullable)
        Annotation *                            // Annotation. (nullable)
    );

// ---------------------------------------------------------------------------------------------- //

#endif // __SIM_STEP_H__
