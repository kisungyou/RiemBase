#ifndef RIEM_01EUCLIDEAN_H
#define RIEM_01EUCLIDEAN_H

#define ARMA_NO_DEBUG

#include <RcppArmadillo.h>

using namespace arma;


// 01. dim(x)
int euclidean_dim(arma::mat x){
  int m = x.n_rows;
  int n = x.n_cols;
  return(m*n);
}
// 02. inner(x,d1,d2)
double euclidean_inner(arma::mat x, arma::mat d1, arma::mat d2){
  return(arma::dot(arma::vectorise(d1), arma::vectorise(d2)));
}
// 03. norm(x,d)
double euclidean_norm(arma::mat x, arma::mat d){
    return(arma::norm(d,"fro"));
}
// 04. dist(x,y)
double euclidean_dist(arma::mat x, arma::mat y){
  return(arma::norm(x-y,"fro"));
}
// 05. proj(x,u)
arma::mat euclidean_proj(arma::mat x, arma::mat u){
  return(u);
}
// 06. tangent(x,u)
arma::mat euclidean_tangent(arma::mat x, arma::mat u){
  return(euclidean_proj(x,u));
}
// 07. tangent2ambient
// 08. rand(x)
arma::mat euclidean_rand(arma::mat x){
  int m = x.n_rows;
  int n = x.n_cols;
  arma::mat out = arma::randn(m,n);
  return(out);
}
// 09. randvec(x)
arma::mat euclidean_randvec(arma::mat x){
  int m = x.n_rows;
  int n = x.n_cols;
  arma::mat out = arma::randn(m,n);
  out /= arma::norm(out,"fro");
  return(out);
}
// 10. zerovec(x)
arma::mat euclidean_zerovec(arma::mat x){
  int m = x.n_rows;
  int n = x.n_cols;
  arma::mat out(m,n,fill::zeros);
  return(out);
}
// 11. vec(x,u_mat)
arma::mat euclidean_vec(arma::mat x, arma::mat u_mat){
  int m = x.n_rows;
  int n = x.n_cols;
  arma::mat out = arma::reshape(u_mat,m*n,1);
  return(out);
}
// 12. mat(x,u_vec)
arma::mat euclidean_mat(arma::mat x, arma::mat u_vec){
  arma::mat out = arma::reshape(u_vec, x.n_rows, x.n_cols);
  return(out);
}
// 13. nearest(x)
arma::mat euclidean_nearest(arma::mat x){
  return(x);
}
// 14. exp(x,d,t=1.0)
arma::mat euclidean_exp(arma::mat x, arma::mat d, double t){
  arma::mat y = x + t*d;
  return(y);
}
// 15. log(x,y)
arma::mat euclidean_log(arma::mat x, arma::mat y){
  return(y-x);
}
// 16. retr(x,d,t)
arma::mat euclidean_retr(arma::mat x, arma::mat d, double t){
  arma::mat y = x + t*d;
  return(y);
}
// 17. invretr(x,y)
arma::mat euclidean_invretr(arma::mat x, arma::mat y){
  return(y-x);
}

double norm_euclidean(arma::mat X){
  return(arma::norm(X));
}

#endif
