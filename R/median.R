#' Geometric Median
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
#' output = RiemBase::median(riemfactory(data,name="sphere"))
#' }
#' 
#' 
#' @references 
#' \insertRef{fletcher_geometric_2009}{RiemBase}
#' 
#' \insertRef{aftab_generalized_2015}{RiemBase}
#' 
#' @export
median <- function(input, maxiter=1000, eps=1e-6){
  #-------------------------------------------------------
  # must be of 'riemdata' class
  if ((class(input))!="riemdata"){
    stop("* median : the input must be of 'riemdata' class. Use 'riemfactory' first to manage your data.")
  }
  # acquire manifold name
  mfdname = tolower(input$name)
  # stack data as 3d matrices
  newdata = aux_stack3d(input)
  
  #-------------------------------------------------------
  # calculate
  return(engine_median(newdata, mfdname, as.integer(maxiter), as.double(eps)))
}