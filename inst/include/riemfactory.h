#ifndef RIEMFACTORY_H
#define RIEMFACTORY_H

#include <RcppArmadillo.h>

/* For Each Manifold, We have individual headers.*/
#include "manifolds/riem_01euclidean.h"
#include "manifolds/riem_02sphere.h"
#include "manifolds/riem_03spd.h"
#include "manifolds/riem_04stiefel.h"
#include "manifolds/riem_05grassmann.h"


/* Methods/Procedures under the names */
#include "procedures/rfunc_dist.h"

#endif
