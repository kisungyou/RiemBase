#ifndef RIEM_01EUCLIDEAN_H
#define RIEM_01EUCLIDEAN_H

#include <RcppArmadillo.h>

using namespace arma;

/*
 * functions
 */

double norm_euclidean(arma::mat X){
  return(arma::norm(X));
}

#endif