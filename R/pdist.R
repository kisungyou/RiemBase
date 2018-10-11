#' Pairwise Distances
#' 
#' @examples
#' \dontrun{
#' ### grassmann / stiefel
#' data = array(0,c(4,2,5))
#' for (i in 1:5){
#'   tgt = matrix(rnorm(4*4),nrow=4)
#'   data[,,i] = qr.Q(qr(tgt))[,1:2]
#' }
#' 
#' ## run pdist
#' pdist(riemfactory(data,name="grassmann"))
#' 
#' 
#' }
#' 
#' @export
pdist <- function(input, as.dist=FALSE){
  #-------------------------------------------------------
  # must be of 'riemdata' class
  if ((class(input))!="riemdata"){
    stop("* pdist : the input must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  # acquire manifold name
  mfdname = tolower(input$name)

  #-------------------------------------------------------
  # stack data as 3d matrices
  newdata = aux_stack3d(input)
  
  #-------------------------------------------------------
  # must be of 'riemdata' class
  output = engine_pdist(newdata, mfdname)

  #-------------------------------------------------------
  # return the matrix
  if (as.dist){
    return(stats::as.dist(output))
  } else {
    return(output)
  }
}