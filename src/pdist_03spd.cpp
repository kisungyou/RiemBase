/*
 * This is exactly identical to AIRM in CovTools package
 */
#include "RcppArmadillo.h"

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

double pdist_spd_two(arma::mat X, arma::mat Y){
  arma::mat cxXY = arma::solve(X,Y);
  arma::mat XY = arma::real(arma::logmat(cxXY));
  return(std::sqrt(arma::as_scalar(arma::trace(XY*XY))));
}

// [[Rcpp::export]]
arma::mat pdist1_spd(arma::cube data){
  const int N = data.n_slices;
  arma::mat output(N,N,fill::zeros);
  arma::mat x,y;
  double distval;
  for (int i=0;i<(N-1);i++){
    x = data.slice(i);
    for (int j=(i+1);j<N;j++){
      y = data.slice(j);
      distval = pdist_spd_two(x,y);
      output(i,j) = distval;
      output(j,i) = distval;
    }
  }
  return(output);
}

// [[Rcpp::export]]
arma::mat pdist2_spd(arma::cube data1, arma::cube data2){
  const int M = data1.n_slices;
  const int N = data2.n_slices;
  arma::mat output(M,N,fill::zeros);
  arma::mat x,y;
  double distval;
  
  for (int i=0;i<M;i++){
    x = data1.slice(i);
    for (int j=0;j<N;j++){
      y = data2.slice(j);
      distval = pdist_spd_two(x,y);
      output(i,j) = distval;
    }
  }
  return(output);
}