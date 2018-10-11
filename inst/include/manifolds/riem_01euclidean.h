#ifndef RIEM_01EUCLIDEAN_H
#define RIEM_01EUCLIDEAN_H

#include <RcppArmadillo.h>

using namespace arma;

/*
 * Functions for Euclidean Data
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
double euclidean_dist(arma::mat x, arma::mat y){
	return(arma::norm(x-y,"fro"));
}
double norm_euclidean(arma::mat X){
  return(arma::norm(X));
}

#endif
