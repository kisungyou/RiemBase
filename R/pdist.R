#' Pairwise Distances
#' 
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