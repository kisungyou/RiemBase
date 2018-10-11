#ifndef RIEM_02SPHERE_H
#define RIEM_02SPHERE_H

#include <RcppArmadillo.h>

using namespace arma;

/*
  * Functions for Sphere Data
* 01.dim
* 02.inner
* 03.norm
* 04.dist
* 05.proj
* 06.tangent
* 07.tangent2ambient
*    exp, log, retr, invretr
* 08. rand
* 09. randvec
* 10. zerovec
* 11. vec
* 12. mat
*/

// 04. dist(x,y)
double sphere_dist(arma::mat x, arma::mat y){
  return(acos(arma::as_scalar(x.t()*y)));
}

#endif