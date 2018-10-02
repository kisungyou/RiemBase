#include "RcppArmadillo.h"

// [[Rcpp::depends(RcppArmadillo)]]

using namespace arma;

// [[Rcpp::export]]
arma::mat pdist1_euclidean(arma::cube data){
  const int N = data.n_slices;
  arma::mat output(N,N,fill::zeros);
  arma::mat x,y;
  double distval;
  for (int i=0;i<(N-1);i++){
    x = data.slice(i);
    for (int j=(i+1);j<N;j++){
      y = data.slice(j);
      distval = arma::norm(x-y,"fro");
      output(i,j) = distval;
      output(j,i) = distval;
    }
  }
  return(output);
}


// [[Rcpp::export]]
arma::mat pdist2_euclidean(arma::cube data1, arma::cube data2){
  const int M = data1.n_slices;
  const int N = data2.n_slices;
  arma::mat output(M,N,fill::zeros);
  arma::mat x,y;
  double distval;
  
  for (int i=0;i<M;i++){
    x = data1.slice(i);
    for (int j=0;j<N;j++){
      y = data2.slice(j);
      distval = arma::norm(x-y,"fro");
      output(i,j) = distval;
    }
  }
  return(output);
}