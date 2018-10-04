/*
 * This is exactly identical to Grassman/Geodesic from Lek-Heng Lim's note
 */
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

double pdist_grassman_two(arma::mat X, arma::mat Y){
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


// [[Rcpp::export]]
arma::mat pdist1_grassman(arma::cube data){
  const int N = data.n_slices;
  arma::mat output(N,N,fill::zeros);
  arma::mat x,y;
  double distval;
  for (int i=0;i<(N-1);i++){
    x = data.slice(i);
    for (int j=(i+1);j<N;j++){
      y = data.slice(j);
      distval = pdist_grassman_two(x,y);
      output(i,j) = distval;
      output(j,i) = distval;
    }
  }
  return(output);
}

// [[Rcpp::export]]
arma::mat pdist2_grassman(arma::cube data1, arma::cube data2){
  const int M = data1.n_slices;
  const int N = data2.n_slices;
  arma::mat output(M,N,fill::zeros);
  arma::mat x,y;
  double distval;
  
  for (int i=0;i<M;i++){
    x = data1.slice(i);
    for (int j=0;j<N;j++){
      y = data2.slice(j);
      distval = pdist_grassman_two(x,y);
      output(i,j) = distval;
    }
  }
  return(output);
}