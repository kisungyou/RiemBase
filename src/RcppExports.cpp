// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// engine_pdist
arma::mat engine_pdist(arma::cube data, std::string name);
RcppExport SEXP _RiemBase_engine_pdist(SEXP dataSEXP, SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_pdist(data, name));
    return rcpp_result_gen;
END_RCPP
}
// engine_pdist_openmp
arma::mat engine_pdist_openmp(arma::cube data, std::string name, int nCores);
RcppExport SEXP _RiemBase_engine_pdist_openmp(SEXP dataSEXP, SEXP nameSEXP, SEXP nCoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type nCores(nCoresSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_pdist_openmp(data, name, nCores));
    return rcpp_result_gen;
END_RCPP
}
// engine_pdist2
arma::mat engine_pdist2(arma::cube data1, arma::cube data2, std::string name);
RcppExport SEXP _RiemBase_engine_pdist2(SEXP data1SEXP, SEXP data2SEXP, SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data1(data1SEXP);
    Rcpp::traits::input_parameter< arma::cube >::type data2(data2SEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_pdist2(data1, data2, name));
    return rcpp_result_gen;
END_RCPP
}
// engine_pdist2_openmp
arma::mat engine_pdist2_openmp(arma::cube data1, arma::cube data2, std::string name, int nCores);
RcppExport SEXP _RiemBase_engine_pdist2_openmp(SEXP data1SEXP, SEXP data2SEXP, SEXP nameSEXP, SEXP nCoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data1(data1SEXP);
    Rcpp::traits::input_parameter< arma::cube >::type data2(data2SEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type nCores(nCoresSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_pdist2_openmp(data1, data2, name, nCores));
    return rcpp_result_gen;
END_RCPP
}
// engine_median
Rcpp::List engine_median(arma::cube data, std::string name, int maxiter, double eps, arma::mat init);
RcppExport SEXP _RiemBase_engine_median(SEXP dataSEXP, SEXP nameSEXP, SEXP maxiterSEXP, SEXP epsSEXP, SEXP initSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type init(initSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_median(data, name, maxiter, eps, init));
    return rcpp_result_gen;
END_RCPP
}
// engine_median_openmp
Rcpp::List engine_median_openmp(arma::cube data, std::string name, int maxiter, double eps, int nCores, arma::mat init);
RcppExport SEXP _RiemBase_engine_median_openmp(SEXP dataSEXP, SEXP nameSEXP, SEXP maxiterSEXP, SEXP epsSEXP, SEXP nCoresSEXP, SEXP initSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< int >::type nCores(nCoresSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type init(initSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_median_openmp(data, name, maxiter, eps, nCores, init));
    return rcpp_result_gen;
END_RCPP
}
// engine_mean
Rcpp::List engine_mean(arma::cube data, std::string name, int maxiter, double eps);
RcppExport SEXP _RiemBase_engine_mean(SEXP dataSEXP, SEXP nameSEXP, SEXP maxiterSEXP, SEXP epsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_mean(data, name, maxiter, eps));
    return rcpp_result_gen;
END_RCPP
}
// engine_mean_openmp
Rcpp::List engine_mean_openmp(arma::cube data, std::string name, int maxiter, double eps, int nCores);
RcppExport SEXP _RiemBase_engine_mean_openmp(SEXP dataSEXP, SEXP nameSEXP, SEXP maxiterSEXP, SEXP epsSEXP, SEXP nCoresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    Rcpp::traits::input_parameter< double >::type eps(epsSEXP);
    Rcpp::traits::input_parameter< int >::type nCores(nCoresSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_mean_openmp(data, name, maxiter, eps, nCores));
    return rcpp_result_gen;
END_RCPP
}
// engine_curvedist
double engine_curvedist(arma::cube data1, arma::cube data2, arma::vec vect, std::string name, double p);
RcppExport SEXP _RiemBase_engine_curvedist(SEXP data1SEXP, SEXP data2SEXP, SEXP vectSEXP, SEXP nameSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::cube >::type data1(data1SEXP);
    Rcpp::traits::input_parameter< arma::cube >::type data2(data2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type vect(vectSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(engine_curvedist(data1, data2, vect, name, p));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RiemBase_engine_pdist", (DL_FUNC) &_RiemBase_engine_pdist, 2},
    {"_RiemBase_engine_pdist_openmp", (DL_FUNC) &_RiemBase_engine_pdist_openmp, 3},
    {"_RiemBase_engine_pdist2", (DL_FUNC) &_RiemBase_engine_pdist2, 3},
    {"_RiemBase_engine_pdist2_openmp", (DL_FUNC) &_RiemBase_engine_pdist2_openmp, 4},
    {"_RiemBase_engine_median", (DL_FUNC) &_RiemBase_engine_median, 5},
    {"_RiemBase_engine_median_openmp", (DL_FUNC) &_RiemBase_engine_median_openmp, 6},
    {"_RiemBase_engine_mean", (DL_FUNC) &_RiemBase_engine_mean, 4},
    {"_RiemBase_engine_mean_openmp", (DL_FUNC) &_RiemBase_engine_mean_openmp, 5},
    {"_RiemBase_engine_curvedist", (DL_FUNC) &_RiemBase_engine_curvedist, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_RiemBase(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
