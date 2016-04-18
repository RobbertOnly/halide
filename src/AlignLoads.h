#ifndef HALIDE_ALIGN_LOADS_H
#define HALIDE_ALIGN_LOADS_H

/** \file
 * Defines a lowering pass the breaks unaligned loads into two aligned
 * loads.
 */
#include "IR.h"
#include "Target.h"
namespace Halide {
namespace Internal {

Stmt align_loads(Stmt s, const Target &t);

}
}

#endif
