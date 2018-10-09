#ifndef RIEM_05GRASSMANN_H
#define RIEM_05GRASSMANN_H

#define ARMA_NO_DEBUG

#include <RcppArmadillo.h>

using namespace arma;

/*
  * Functions for Grassmann Data
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
double grassmann_dist(arma::mat X, arma::mat Y){
  arma::mat XY = X.t()*Y;
  arma::vec s  = arma::svd(XY);
  const int N  = s.n_elem;
  
  arma::vec theta(N,fill::zeros);
  for (int i=0;i<s.n_elem;i++){
    if (s(i) > 1){
      s(i) = 1.0;
    }
    theta(i) = std::pow(std::acos(arma::as_scalar(s(i))),2);
  }
  
  return(std::sqrt(arma::as_scalar(theta.t()*theta)));  
}

#endif