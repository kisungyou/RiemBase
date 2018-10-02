#' Prepare a S3 Class Object 'riemdata'
#' 
#' @export
riemfactory <- function(data, name=c("Euclidean","Grassman","SPD","Sphere","Stiefel")){
  ############################################################
  ## MANIFOLD TYPE MATCHING
  allnames = tolower(c("Euclidean","Grassman","SPD","Sphere","Stiefel"))
  name     = match.arg(tolower(name), allnames)
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