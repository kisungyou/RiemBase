#ifndef RIEMFUNC_EXP_H
#define RIEMFUNC_EXP_H

#include <RcppArmadillo.h>
#include "../include/riemfactory.h"

using namespace arma;

///////////////////////////////////////////////////////////////
arma::mat riemfunc_exp(arma::mat x, arma::mat d, double t, std::string name){
  if (name=="euclidean"){
    return(euclidean_exp(x,d,t));
  } else if (name=="sphere"){
    return(sphere_exp(x,d,t));
  } else if (name=="spd"){
    return(spd_exp(x,d,t));
  } else {
    Rcpp::Rcout << "RiemBase::riemfunc_exp : " << name <<" is not yet implemented." << std::endl;
    Rcpp::stop("");
  }
}

#endif
