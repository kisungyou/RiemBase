#' Pairwise Distances
#' 
#' @examples
#' \dontrun{
#' ### grassmann / stiefel
#' ndata = 100
#' data = array(0,c(4,2,ndata))
#' for (i in 1:ndata){
#'   tgt = matrix(rnorm(4*4),nrow=4)
#'   data[,,i] = qr.Q(qr(tgt))[,1:2]
#' }
#' 
#' TT = riemfactory(data,name="grassmann")
#' ## run pdist
#' A = pdist(riemfactory(data,name="grassmann"))
#' B = pdist(riemfactory(data,name="grassmann"))
#' microbenchmark(A = pdist(riemfactory(data,name="grassmann")), B = pdist_parallel(riemfactory(data,name="grassmann")))
#' 
#' }
#' 
#' @export
pdist <- function(input, parallel=FALSE){
  #-------------------------------------------------------
  # must be of 'riemdata' class
  if ((class(input))!="riemdata"){
    stop("* pdist : the input must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  # acquire manifold name
  mfdname = tolower(input$name)
  # stack data as 3d matrices
  newdata = aux_stack3d(input)
  
  #-------------------------------------------------------
  # support of parallel computation using OpenMP and run
  # must be of 'riemdata' class
  nCores = parallel::detectCores()
  
  if (parallel==FALSE){
    output = engine_pdist(newdata, mfdname)
  } else {
    if ((nCores==1)||(is.na(nCores))){
      output = engine_pdist(newdata, mfdname)
    } else {
      output = engine_pdist_openmp(newdata, mfdname, nCores)
    }  
  }

  #-------------------------------------------------------
  # return the matrix
  return(output)
}