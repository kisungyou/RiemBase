#include <RcppArmadillo.h>
#include "distutil.h"

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

double dist_01euclidean(arma::mat x, arma::mat y){           // 1. euclidean
  return(arma::norm(x-y,"fro"));
}
double dist_02sphere(arma::mat x, arma::mat y){              // 2. sphere
  return(acos(arma::as_scalar(x.t()*y)));
}
double dist_03spd(arma::mat X, arma::mat Y){                 // 3. spd
  arma::mat cxXY = arma::solve(X,Y);
  arma::mat XY = arma::real(arma::logmat(cxXY));
  return(std::sqrt(arma::as_scalar(arma::trace(XY*XY))));
}
double dist_05grassmann(arma::mat X, arma::mat Y){           // 5. grassmann
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
