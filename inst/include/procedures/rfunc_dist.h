#ifndef RFUNC_DIST_H
#define RFUNC_DIST_H

#include <RcppArmadillo.h>
#include "../include/riemfactory.h"

using namespace arma;

///////////////////////////////////////////////////////////////
double rfunc_dist(arma::mat x, arma::mat y, std::string name){
  if (name=="euclidean"){
    return(euclidean_dist(x,y));
  } else if (name=="sphere"){
    return(sphere_dist(x,y));
  } else if (name=="spd"){
    return(spd_dist(x,y));
  } else if (name=="grassmann"){
    return(grassmann_dist(x,y));
  } else {
    Rcpp::Rcout << "RiemBase::rfunc_dist : " << name << " is not yet implemented." << std::endl;
    return(NA_REAL);
  }
}
#endif