#' Prepare a S3 Class Object 'riemdata'
#' 
#' @param data data to be wrapped as \code{riemdata} class. Following input formats are considered,
#' \describe{
#' \item{2D array}{an \eqn{(m\times p)} matrix where data are stacked in columns over 2nd dimension. Appropriate for vector-valued \code{Euclidean} or \code{Sphere} manifold case.}
#' \item{3D array}{an \eqn{(m\times n\times p)} matrix where data are stacked in slices over 3rd dimension.}
#' \item{list}{unnamed list where each element of the list is a single data point. Sizes of all elements must match.}
#' }
#' @param name the name of Riemmanian manifold for data to which data belong.
#' 
#' @export
riemfactory <- function(data, name=c("Euclidean","Grassmann","SPD","Sphere","Stiefel")){
  ############################################################
  ## MANIFOLD TYPE MATCHING
  allnames = tolower(c("Euclidean","Grassmann","SPD","Sphere","Stiefel"))
  name     = match.arg(tolower(name), allnames)
  ## I Believe Inputs should also be an array of length 2 or 3
  if (is.array(data)){
    datasize = dim(data)
    if (length(datasize)==2){
      newdata = list()
      for (i in 1:datasize[2]){
        newdata[[i]] = data[,i]
      }
      data = newdata
    } else if (length(datasize)==3){
      newdata = list()
      for (i in 1:datasize[3]){
        newdata[[i]] = datasize[,,i]
      }
      data = newdata
    } else {
      stop("* riemfactory : once 'data' is given as an array, it should be either 2D matrix or 3D array.")
    }
  }
  if (length(names(data))>1){
    names(data)=NULL
  }
  switch(name,
         euclidean = stopifnot(islist_euclidean(data)),
         spd       = stopifnot(islist_spd(data)),
         sphere    = stopifnot(islist_sphere(data)),
         stiefel   = stopifnot(islist_stiefel(data)),
         grassman  = stopifnot(islist_stiefel(data))
  )
  
  ############################################################
  ## COMMON INFORMATION
  ## 1. transform vectors into matrices and name it as 'data'
  if (is.vector(data[[1]])){
    data = lapply(data, as.matrix)
  } else {
    data = data
  }
  ## 2. size
  size = c(nrow(data[[1]]), ncol(data[[1]]))
  
  output = list()
  output$data = data
  output$size = size
  output$name = name
  
  ############################################################
  ##  RETURN THE S3 CLASS
  return(structure(output, class="riemdata"))
}