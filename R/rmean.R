#' Robust Mean Estimation
#' 
#' @examples 
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
#' out1 = RiemBase::rmean(riemfactory(data,name="sphere"))
#' out2 = RiemBase::rmean(riemfactory(data,name="sphere"), parallel=TRUE)
#' out3 = RiemBase::mean(riemfactory(data,name="sphere"))
#' out4 = RiemBase::mean(riemfactory(data,name="sphere"), parallel=TRUE)
#' 
#' @export
rmean <- function(input, k=5, maxiter=1000, eps=1e-6, parallel=FALSE){
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
  # generate cluster index and separate true data
  nCores   = parallel::detectCores()
  clustidx = aux_rndivide(dim(newdata)[3], k)
  partdata = list()
  for (i in 1:length(clustidx)){
    tmpdata = newdata[,,clustidx[[i]]] 
    if (length(dim(tmpdata))==2){
      tmpdata = rmean_2to3(tmpdata)
    }
    if (length(dim(tmpdata))!=3){
      stop("* something is wrong.")
    }
    partdata[[i]] = tmpdata
  }
  
  #-------------------------------------------------------
  # let's run parallel for mean
  tmpout = list()
  for (i in 1:k){
    if ((nCores==1)||is.na(nCores)||(parallel=FALSE)){
      tmpoutput = engine_mean(partdata[[i]], mfdname, as.integer(maxiter), as.double(eps))
    } else {
      tmpoutput = engine_mean_openmp(partdata[[i]], mfdname, as.integer(maxiter), as.double(eps), nCores)
    }
    tmpout[[i]] = tmpoutput$x
  }
  
  #-------------------------------------------------------
  # it's time to run robust median problem
  partmeans = rmean_lto3(tmpout)
  if ((nCores==1)||(is.na(nCores))||(parallel=FALSE)){
    output = engine_median(partmeans, mfdname, as.integer(maxiter), as.double(eps))
  } else {
    output = engine_median_openmp(partmeans, mfdname, as.integer(maxiter), as.double(eps), nCores)
  }

  #-------------------------------------------------------
  # return output
  return(output)
}

#' @keywords internal
#' @noRd
rmean_2to3 <- function(A){
  m = nrow(A)
  p = ncol(A)
  
  output = array(0,c(m,1,p))
  for (i in 1:p){
    output[,,i] = A[,i]
  }
  return(output)
}
#' @keywords internal
#' @noRd
rmean_lto3 <- function(dlist){
  p = length(dlist)
  m = nrow(dlist[[1]])
  n = ncol(dlist[[1]])
  
  output = array(0,c(m,n,p))
  for (i in 1:p){
    output[,,i] = dlist[[i]]
  }
  return(output)
}