% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/rbase.median.R
\name{rbase.median}
\alias{rbase.median}
\title{Geometric Median of Manifold-valued Data}
\usage{
rbase.median(input, maxiter = 496, eps = 1e-06, parallel = FALSE)
}
\arguments{
\item{input}{a S3 object of \code{riemdata} class. See \code{\link{riemfactory}} for more details.}

\item{maxiter}{maximum number of iterations for gradient descent algorithm.}

\item{eps}{stopping criterion for the norm of gradient.}

\item{parallel}{a flag for enabling parallel computation.}
}
\value{
a named list containing
\describe{
\item{x}{an estimate geometric median.}
\item{iteration}{number of iterations until convergence.}
}
}
\description{
For manifold-valued data, geometric median is the solution of following cost function,
\deqn{\textrm{min}_x \sum_{i=1}^n \rho (x, x_i) = \sum_{i=1}^n \| \log_x (x_i) \|,\quad x\in\mathcal{M}}
for a given data \eqn{\{x_i\}_{i=1}^n}, \eqn{\rho(x,y)} the geodesic distance 
between two points on manifold \eqn{\mathcal{M}}, and \eqn{\| \log_x (y) \|} a logarithmic mapping onto the 
tangent space \eqn{T_x \mathcal{M}}. Weiszfeld's algorithms is employed.
}
\examples{
\donttest{
### Generate 100 data points on Sphere S^2 near (0,0,1).
ndata = 100
theta = seq(from=-0.99,to=0.99,length.out=ndata)*pi
tmpx  = cos(theta) + rnorm(ndata,sd=0.1)
tmpy  = sin(theta) + rnorm(ndata,sd=0.1)

### Wrap it as 'riemdata' class
data  = list()
for (i in 1:ndata){
  tgt = c(tmpx[i],tmpy[i],1)
  data[[i]] = tgt/sqrt(sum(tgt^2)) # project onto Sphere
}
data = riemfactory(data, name="sphere")

### Compute Geodesic Median
out1 = rbase.median(data)
out2 = rbase.median(data,parallel=TRUE) # test parallel implementation
}


}
\references{
\insertRef{fletcher_geometric_2009}{RiemBase}

\insertRef{aftab_generalized_2015}{RiemBase}
}
\author{
Kisung You
}
