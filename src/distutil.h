#ifndef _RiemBase_DISTUTIL_H
#define _RiemBase_DISTUTIL_H

#define ARMA_NO_DEBUG

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


// Supported Manifolds
double dist_01euclidean(arma::mat x, arma::mat y);
double dist_02sphere(arma::mat x, arma::mat y);
double dist_03spd(arma::mat X, arma::mat Y);
double dist_05grassmann(arma::mat X, arma::mat Y);


#endif