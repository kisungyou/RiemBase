#' Karcher Mean on Manifolds
#' 
#' @examples
#' \dontrun{
#' ### median around (0,1,1) for Sphere S^2
#' ndata = 100
#' theta = seq(from=-0.99,to=0.99,length.out=ndata)*pi
#' tmpx  = cos(theta)/5 + rnorm(ndata,sd=0.05)
#' tmpy  = sin(theta)/5 + rnorm(ndata,sd=0.05)
#' 
#' data  = list()
#' for (i in 1:ndata){
#'   tgt = c(tmpx[i],tmpy[i],1)
#'   data[[i]] = tgt/sqrt(sum(tgt^2)) # project onto Sphere
#' }
#' 
#' ### run pdist
#' out1 = RiemBase::mean(riemfactory(data,name="sphere"))
#' out2 = RiemBase::mean(riemfactory(data,name="sphere"), parallel=TRUE)
#' norm(matrix(out1$x)-matrix(out2$x),"f")
#' }
#' 
#' @export
mean <- function(input, maxiter=1000, eps=1e-6, parallel=FALSE){
  #-------------------------------------------------------
  # must be of 'riemdata' class
  if ((class(input))!="riemdata"){
    stop("* mean : the input must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  # acquire manifold name
  mfdname = tolower(input$name)
  # stack data as 3d matrices
  newdata = aux_stack3d(input)
  
  #-------------------------------------------------------
  # calculate
  nCores = parallel::detectCores()
  
  # must be of 'riemdata' class
  nCores = parallel::detectCores()
  if (parallel==FALSE){
    output = engine_mean(newdata, mfdname, as.integer(maxiter), as.double(eps))
  } else {
    if ((nCores==1)||(is.na(nCores))){
      output = engine_mean(newdata, mfdname, as.integer(maxiter), as.double(eps))
    } else {
      output = engine_mean_openmp(newdata, mfdname, as.integer(maxiter), as.double(eps), nCores)
    }  
  }
  
  return(output)
}