#include "RcppArmadillo.h"
#include "riemfactory.h"

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

//////////////////////////////////////////////////////////////
// 1. pdist : pairwise distance
//////////////////////////////////////////////////////////////
// [[Rcpp::export]]
arma::mat engine_pdist(arma::cube data, std::string name){
  // XPtr<distPtr> xpfun = SetDistPtr(name);
  // distPtr fun = *xpfun;
  
  const int N = data.n_slices;
  arma::mat output(N,N,fill::zeros);
  arma::mat x,y;
  double distval;
  for (int i=0;i<(N-1);i++){
    x = data.slice(i);
    for (int j=(i+1);j<N;j++){
      y = data.slice(j);
      distval = riemfunc_dist(x,y,name);
      output(i,j) = distval;
      output(j,i) = distval;
    }
  }
  return(output);
}

//////////////////////////////////////////////////////////////
// 2. pdist2 : pairwise data between two sets of data
//////////////////////////////////////////////////////////////
// [[Rcpp::export]]
arma::mat engine_pdist2(arma::cube data1, arma::cube data2, std::string name){
  // XPtr<distPtr> xpfun = SetDistPtr(name);
  // distPtr fun = *xpfun;
  
  const int M = data1.n_slices;
  const int N = data2.n_slices;
  arma::mat output(M,N,fill::zeros);
  arma::mat x,y;
  double distval;
  
  for (int i=0;i<M;i++){
    x = data1.slice(i);
    for (int j=0;j<N;j++){
      y = data2.slice(j);
      distval = riemfunc_dist(x,y,name);
      output(i,j) = distval;
    }
  }
  return(output);
}


//////////////////////////////////////////////////////////////
// 3. median : geometric median using Weiszfeld algorithm
//////////////////////////////////////////////////////////////
// [[Rcpp::export]]
Rcpp::List engine_median(arma::cube data, std::string name, int maxiter, double eps){
  // get parameters
  const int N = data.n_slices;
  int iter = 0;
  
  // initialize
  arma::mat mold = riemfunc_nearest(arma::mean(data,2), name);
  arma::mat mnew;   mnew.copy_size(mold);  mnew.fill(0); 
  arma::mat dtmp;   dtmp.copy_size(mold);  dtmp.fill(0); // on TpM
  arma::cube tvecs; tvecs.copy_size(data); tvecs.fill(0);
  arma::vec normvec(N,fill::zeros);
  
  // let's iterate !
  arma::uvec nonsingular;
  double increment = 10000.00;
  while (increment > eps){
    Rcout << "Iteration : " << iter << std::endl;
    // 1. compute log-pulled vectors and norm
    for (int i=0;i<N;i++){
      tvecs.slice(i) = riemfunc_log(mold, data.slice(i), name);
      normvec(i) = riemfunc_norm(mold, tvecs.slice(i), name);
    }
    // 2. find the one with non-singular distance
    nonsingular = arma::find(normvec>1e-10);  
    int M = nonsingular.n_elem;
    if (M==0){
      break;
    }
    // 3. update numerator
    dtmp.reset();
    dtmp.copy_size(mold); dtmp.fill(0);
    for (int j=0;j<M;j++){
      dtmp += tvecs.slice(nonsingular(j))/normvec(nonsingular(j));
    }
    // 4. update denominator
    double denom = 0.0;
    for (int j=0;j<M;j++){
      denom += 1/normvec(nonsingular(j));
    }
    dtmp /= denom;
    // 5. update using exponential map
    mnew = riemfunc_exp(mold, dtmp, 1.0, name);
    // 6. iterate condition
    increment = riemfunc_dist(mold, mnew, name);
    iter += 1;
    // 8. update
    mold = mnew;
    if (iter >= maxiter){
      break;
    }
  }
  
  return(Rcpp::List::create(Rcpp::Named("median")=mold,
                            Rcpp::Named("iteration")=iter));
}
