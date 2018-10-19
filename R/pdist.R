#' Pairwise Distances
#' 
#' @examples
#' \dontrun{
#' ### grassmann / stiefel
#' ndata = 1000
#' data = array(0,c(4,2,ndata))
#' for (i in 1:ndata){
#'   tgt = matrix(rnorm(4*4),nrow=4)
#'   data[,,i] = qr.Q(qr(tgt))[,1:2]
#' }
#' 
#' ## run pdist
#' A = pdist(riemfactory(data,name="grassmann"))
#' B = pdist(riemfactory(data,name="grassmann"))
#' microbenchmark(A = pdist(riemfactory(data,name="grassmann")), B = pdist_parallel(riemfactory(data,name="grassmann")))
#' 
#' }
#' 
#' @export
pdist <- function(input){
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
  # must be of 'riemdata' class
  output = engine_pdist(newdata, mfdname)

  #-------------------------------------------------------
  # return the matrix
  return(output)
}