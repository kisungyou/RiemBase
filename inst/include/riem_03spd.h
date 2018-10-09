#ifndef RIEM_03SPD_H
#define RIEM_03SPD_H

#include <RcppArmadillo.h>

using namespace arma;

/*
  * Functions for SPD(Symmetric and Positive Definite) Data
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
double spd_dist(arma::mat x, arma::mat y){
  arma::mat cxXY = arma::solve(x,y);
  arma::mat XY = arma::real(arma::logmat(cxXY));
  return(std::sqrt(arma::as_scalar(arma::trace(XY*XY))));  
}

#endif