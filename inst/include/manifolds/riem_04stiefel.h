#ifndef RIEM_04STIEFEL_H
#define RIEM_04STIEFEL_H

#define ARMA_NO_DEBUG

#include <RcppArmadillo.h>

using namespace arma;

// 01. dim(x)
int stiefel_dim(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  int output = ((n*p)-(p*(p+1)/2));
  return(output);
}
// 02. inner(x,d1,d2)
double stiefel_inner(arma::mat x, arma::mat d1, arma::mat d2){
  return(arma::as_scalar(arma::dot(arma::vectorise(d1), arma::vectorise(d2))));
}
// 03. norm(x,d)
double stiefel_norm(arma::mat x, arma::mat d){
  return(arma::norm(d, "fro"));
}
// 04. dist(x,y)
// 05. proj(x,u)
arma::mat stiefel_proj(arma::mat x, arma::mat u){
  arma::mat A = (x.t()*u);
  return(u - x*((A+A.t())/2.0));
}
// 06. tangent(x,u)
arma::mat stiefel_tangent(arma::mat x, arma::mat u){
  return(stiefel_proj(x,u));
}
// 07. tangent2ambient
// 08. rand(x)
arma::mat stiefel_rand(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat A(n,p,fill::randn);
  arma::mat Q,R;
  arma::qr(Q,R,A);

  return(Q);
}
// 09. randvec(x)
arma::mat stiefel_randvec(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat A(n,p,fill::randn);
  arma::mat U;
  U = stiefel_proj(x,A);
  U /= arma::norm(U,"fro");
  return(U);
}
// 10. zerovec(x)
arma::mat stiefel_zerovec(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat out(n,p,fill::zeros);
  return(out);
}
// 11. vec(x,u_mat)
arma::mat stiefel_vec(arma::mat x, arma::mat u_mat){
  int n = x.n_rows;
  int p = x.n_cols;
  arma::mat out = arma::reshape(u_mat,(n*p),1);
  return(out);
}
// 12. mat(x,u_vec)
arma::mat stiefel_mat(arma::mat x, arma::mat u_vec){
  arma::mat out = arma::reshape(u_vec, x.n_rows, x.n_cols);
  return(out);
}
// 13. nearest(x)
// 14. exp(x,d,t)
arma::mat stiefel_exp(arma::mat x, arma::mat u, double t){
  const int n = x.n_rows;
  const int p = x.n_cols;
  
  arma::mat Ip(p,p,fill::eye);
  arma::mat Zp(p,p,fill::zeros);
  
  arma::mat tu = t*u;
  arma::mat term1 = arma::join_horiz(x, tu);
  
  arma::mat term21 = arma::join_horiz((x.t()*tu), -((tu.t())*tu));
  arma::mat term22 = arma::join_horiz(Ip, (x.t()*tu));
  arma::mat term2  = arma::expmat(arma::join_vert(term21, term22));
  
  arma::mat term3  = arma::join_vert(arma::expmat(-(x.t()*tu)), Zp);
  
  arma::mat output = term1*term2*term3;
  return(output);
}
// 15. log(x,y)
// 16. retr(x,d,t)
arma::mat stiefel_retr(arma::mat x, arma::mat u, double t){
  arma::mat y = x + (t*u);
  arma::mat Q,R;
  arma::qr(Q,R,y);
  return(Q);
}
// 17. invretr(x,y)
arma::mat stiefel_invretr(arma::mat x, arma::mat y){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat xty = (x.t()*y);
  arma::mat Ip(p,p,fill::eye);
  
  arma::mat A = xty;
  arma::mat B = xty.t();
  arma::mat C = -2.0*Ip;
  
  arma::mat M = arma::syl(A,B,C);
  arma::mat U = y*M-x;
  return(U);
}

#endif