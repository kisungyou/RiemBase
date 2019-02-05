#' Distance between Two Curves with Finite Difference Approximation
#' 
#' 
#' @export
rbase.curvedist <- function(curve1, curve2, t=NULL, type=c("intrinsic","extrinsic")){
  #-------------------------------------------------------
  # must be of 'riemdata' class
  if ((class(curve1))!="riemdata"){
    stop("* rbase.curvedist : the curve1 must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  if ((class(curve2))!="riemdata"){
    stop("* rbase.curvedist : the curve2 must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  # acquire manifold name
  mfdname = tolower(curve1$name)
  # other conditions : size and name should match
  if (tolower(curve1$name)!=(curve2$name)){
    stop("* rbase.curvedist : two inputs should be of same manifold type.")
  }
  if (any(curve1$size!=curve2$size)){
    stop("* rbase.curvedist : two inputs should be of same size and dimension.")
  }
  # t : length of controlling
  if (is.null(t)&&(length(t)==0)){
    t = 1:length(curve1$data)
  } else {
    if (length(t)!=length(curve1$data)){
      stop("* rbase.curvedist : length of the domain vector 't' should be same as that of input data.")
    }
  }
  # t : should be no NAs or Infs
  if (any(is.infinite(t))||any(is.na(t))){
    stop("* rbase.curvedist : vector 't' should contain finite real values, only.")
  }
  # type checking
  type = match.arg(type)
  

  # -------------------------------------------------------
  # Main Computation
  # setting : p = 2.0 for L2, change later if needed. ******************** CHANGE IF NEEDED.
  p.order = 2.0
  # stack data as 3d matrices
  data1 = aux_stack3d(curve1)
  data2 = aux_stack3d(curve2)
  
  # is 't' sorted ? : if not, change accordingly
  order_t = order(t)
  if (any(t!=sort(t))){
    t = t[order_t]
    data1 = data1[,,order_t]
    data2 = data2[,,order_t]
  }
  
  # compute !
  result = engine_curvedist(data1, data2, t, mfdname, p.order)
  return(result)
}