##  01. aux_stack3d : from 'riemdata' instance, create a 3d slice of data



# 01. aux_stack3d : from 'riemdata' instance, create a 3d slice of --------
#' @keywords internal
#' @noRd
aux_stack3d <- function(riemdata){
  msize = riemdata$size
  ndata = length(riemdata$data)
  
  matdata = array(0,c(msize[1], msize[2], ndata))
  for (i in 1:ndata){
    matdata[,,i] = (riemdata$data[[i]])
  }
  return(matdata)
}