#ifndef RIEMFUNC_NORM_H
#define RIEMFUNC_NORM_H

#include <RcppArmadillo.h>
#include "../include/riemfactory.h"

using namespace arma;

///////////////////////////////////////////////////////////////
double riemfunc_norm(arma::mat x, arma::mat d, std::string name){
  if (name=="euclidean"){
    return(euclidean_norm(x,d));
  } else if (name=="sphere"){
    return(sphere_norm(x,d));
  } else if (name=="spd"){
    return(spd_norm(x,d));
  }else {
    Rcpp::Rcout << "RiemBase::riemfunc_norm : " << name <<" is not yet implemented." << std::endl;
    Rcpp::stop("");
  }
}
  
#endif
