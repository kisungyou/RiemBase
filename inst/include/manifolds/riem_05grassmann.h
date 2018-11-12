#ifndef RIEM_05GRASSMANN_H
#define RIEM_05GRASSMANN_H

#define ARMA_NO_DEBUG

#include <RcppArmadillo.h>

using namespace arma;

// 01. dim(x)
int grassmann_dim(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  int output = p*(n-p);
  return(output);
}
// 02. inner(x,d1,d2)
double grassmann_inner(arma::mat x, arma::mat d1, arma::mat d2){
  return(arma::as_scalar(arma::dot(arma::vectorise(d1), arma::vectorise(d2))));
}
// 03. norm(x,d)
double grassmann_norm(arma::mat x, arma::mat d){
  return(arma::norm(d, "fro"));
}
// 04. dist(x,y)
double grassmann_dist(arma::mat X, arma::mat Y){
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

// 05. proj(x,u)
arma::mat grassmann_proj(arma::mat x, arma::mat u){
  return(u-x*((x.t()*u)));
}
// 06. tangent(x,u)
arma::mat grassmann_tangent(arma::mat x, arma::mat u){
  return(grassmann_proj(x,u));
}
// 07. tangent2ambient
// 08. rand(x)
arma::mat grassmann_rand(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat A(n,p,fill::randn);
  arma::mat Q,R;
  arma::qr(Q,R,A);
  
  return(Q);
}
// 09. randvec(x)
arma::mat grassmann_randvec(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat A(n,p,fill::randn);
  arma::mat U;
  U = grassmann_proj(x,A);
  U /= arma::norm(U,"fro");
  return(U);
}
// 10. zerovec(x)
arma::mat grassmann_zerovec(arma::mat x){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat out(n,p,fill::zeros);
  return(out);
}
// 11. vec(x,u_mat)
arma::mat grassmann_vec(arma::mat x, arma::mat u_mat){
  int n = x.n_rows;
  int p = x.n_cols;
  arma::mat out = arma::reshape(u_mat,(n*p),1);
  return(out);
}
// 12. mat(x,u_vec)
arma::mat grassmann_mat(arma::mat x, arma::mat u_vec){
  arma::mat out = arma::reshape(u_vec, x.n_rows, x.n_cols);
  return(out);
}
// 13. nearest(x)
// 14. exp(x,d,t)
arma::mat grassmann_exp(arma::mat x, arma::mat d, double t){
  const int n = x.n_rows;
  const int p = x.n_cols;

  arma::mat u, v, sin_s, cos_s;
  arma::vec s;
  
  arma::mat tu = t*d;
  arma::svd_econ(u,s,v,tu);
  cos_s = arma::diagmat(arma::cos(s));
  sin_s = arma::diagmat(arma::sin(s));
  
  arma::mat Y = x*v*cos_s*v.t() + u*sin_s*v.t();
  arma::mat Q,R;
  arma::qr(Q,R,Y);
  return(Q);
}
// 15. log(x,y)
arma::mat grassmann_log(arma::mat x, arma::mat y){
  int n = x.n_rows;
  int p = x.n_cols;
  
  arma::mat ytx = y.t()*x;             // (p,p)
  arma::mat At = (y.t())-(ytx*x.t());  // (p,n)
  arma::mat Bt = arma::solve(ytx, At); // (p,n)
  
  arma::mat u,v;
  arma::vec s;
  
  arma::svd_econ(u,s,v,(Bt.t())); // (n,p) svd : (n,n) (n,p) (p,p) for [u,s,v]
  
  arma::mat U = u.cols(0,(p-1));
  arma::mat S = arma::diagmat(arma::atan(s));
  arma::mat V = v.cols(0,(p-1));
  
  arma::mat output = U*S*V.t();
  return(output);
}
// 16. retr(x,d,t)
arma::mat grassmann_retr(arma::mat x, arma::mat d, double t){
  arma::mat y = x + (t*d);
  
  arma::mat u, v;
  arma::vec s;
  
  arma::svd_econ(u,s,v,y);
  arma::mat output = (u.t()*v);
  return(output);
}
// 17. invretr(x,y)
arma::mat grassmann_invretr(arma::mat x, arma::mat y){
  arma::mat U = (y*arma::pinv((x.t()*y)))-x;
  return(U);
}

// 18. equiv(x,m,n)
arma::vec grassmann_equiv(arma::mat x, int n, int p){
  arma::vec output = arma::vectorise((x*x.t()),0);
  return(output);
}

// 19. invequiv(x,m,n)
arma::mat grassmann_invequiv(arma::vec x, int n, int p){
  arma::mat tmpx = arma::reshape(x,n,n);  // (n x n) in equivariants
  arma::mat symx = (tmpx + tmpx.t())/2.0; // symmetrization for sake
  
  arma::vec eigval;
  arma::mat eigvec;
  eig_sym(eigval, eigvec, symx); // in an ascending order
  
  arma::mat output = arma::fliplr(eigvec.tail_cols(p)); // does it ?
  return(output);
}


#endif