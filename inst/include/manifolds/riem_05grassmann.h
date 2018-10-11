#ifndef RIEM_05GRASSMANN_H
#define RIEM_05GRASSMANN_H

#define ARMA_NO_DEBUG

#include <RcppArmadillo.h>

using namespace arma;

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