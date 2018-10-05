#' Pairwise Distances Between Two Sets of Data
#' 
#' 
#' @export
pdist2 <- function(input1, input2){
  #-------------------------------------------------------
  # must be of 'riemdata' class
  if ((class(input1))!="riemdata"){
    stop("* pdist2 : the input1 must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  if ((class(input2))!="riemdata"){
    stop("* pdist2 : the input2 must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  # acquire manifold name
  mfdname = tolower(input1$name)
  # other conditions : size and name should match
  if (tolower(input1$name)!=(input2$name)){
    stop("* pdist2 : two inputs should be of same manifold type.")
  }
  if (any(input1$size!=input2$size)){
    stop("* pdist2 : two inputs should be of same size and dimension.")
  }
  
  #-------------------------------------------------------
  # stack data as 3d matrices
  newdata1 = aux_stack3d(input1)
  newdata2 = aux_stack3d(input2)
  
  #-------------------------------------------------------
  # must be of 'riemdata' class
  output = engine_pdist2(newdata1, newdata2, mfdname)
  
  return(output)
}