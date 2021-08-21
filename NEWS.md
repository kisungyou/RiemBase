# RiemBase 0.2.5

* Change of maintainer's contact.
* Fixed CRAN errors.

# RiemBase 0.2.4

* Fixed OpenMP support.
* Fixed C++ for computing distances on Grassmannian.
* Use `qr_econ` for consistent computations on Grassmann and Stiefel manifolds.

# RiemBase 0.2.3

* Fixed checker for sphere case.
  
# RiemBase 0.2.2

* Function `rbase.curvedist` is added to compute L2 distance. between two curves on manifolds.
* Vector-valued data handling is fixed. Bug reports are welcome.

# RiemBase 0.2.1

* `NEWS` initialized. Updates will be recorded here.
* Computation of (intrinsic) Frechet means are improved:
  - parallel option provided using OpenMP support.
  - Wolfe condition becomes obsolete. Faster convergence is still achieved from fixed step size.