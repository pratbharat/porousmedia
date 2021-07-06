# OpenFOAM Solver for Heterogeneous Porous Media Simulation 
OF6 version \
swak4Foam library is used for evaluating post-processing results. So, before running the simulation swak4Foam library should be installed, otherwise it will show error. Alternatively, the swak4Foam can be turned off. 

Reference: Dazeo et. al.,HETEROGENEOUS POROUS MEDIA SIMULATION, Mecánica Computacional Vol XXXVI, págs. 1173-1181.

# testCase_porousSimpleFoam
Test case using the solver porousSimpleFoam with constant value of D and F.  D= 1643133150 and F =  894.3699319.

# testCase_myVarPorousSimpleFoam
Test case using the  present solver myVarPorousSimpleFoam with constant value of D and F.  D= 1643133150 and F =  894.3699319. \
\ 
One can get more accurate results with increasing number of cells and reducing time-steps.

# testCase_variablePorosity
Test case using the  present solver myVarPorousSimpleFoam with variable value of D and F along x-axis. \
Here D(x) =  D0. (x-x0) ; \
and  F(x) =  F0. (x-x0) ; \
where D0 = 3283133150 and F =  1800 and x0 is the the position x where
the medium starts. \
