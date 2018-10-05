#include "RcppArmadillo.h"
#include "distutil.h"

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

// TypeMatching by XPtr *******************************************
typedef double (*distPtr)(arma::mat x, arma::mat y);
XPtr<distPtr> SetDistPtr(std::string name){
  if (name=="euclidean"){
    return(XPtr<distPtr>)(new distPtr(&dist_01euclidean));
  } else if (name=="sphere"){
    return(XPtr<distPtr>)(new distPtr(&dist_02sphere));
  } else if (name=="spd"){
    return(XPtr<distPtr>)(new distPtr(&dist_03spd));
  } else if (name=="grassmann"){
    return(XPtr<distPtr>)(new distPtr(&dist_05grassmann));
  } else {
    return XPtr<distPtr>(R_NilValue);
  }
}

// [[Rcpp::export]]
arma::mat engine_pdist(arma::cube data, std::string name){
  XPtr<distPtr> xpfun = SetDistPtr(name);
  distPtr fun = *xpfun;
  
  const int N = data.n_slices;
  arma::mat output(N,N,fill::zeros);
  arma::mat x,y;
  double distval;
  for (int i=0;i<(N-1);i++){
    x = data.slice(i);
    for (int j=(i+1);j<N;j++){
      y = data.slice(j);
      distval = fun(x,y);
      output(i,j) = distval;
      output(j,i) = distval;
    }
  }
  return(output);
}

// [[Rcpp::export]]
arma::mat engine_pdist2(arma::cube data1, arma::cube data2, std::string name){
  XPtr<distPtr> xpfun = SetDistPtr(name);
  distPtr fun = *xpfun;
  
  const int M = data1.n_slices;
  const int N = data2.n_slices;
  arma::mat output(M,N,fill::zeros);
  arma::mat x,y;
  double distval;
  
  for (int i=0;i<M;i++){
    x = data1.slice(i);
    for (int j=0;j<N;j++){
      y = data2.slice(j);
      distval = fun(x,y);
      output(i,j) = distval;
    }
  }
  return(output);
}
