
    tmp<volVectorField> tHbyA = constrainHbyA(trTU()&UEqn.H(), U, p);

   volVectorField& HbyA = tHbyA.ref();

   tUEqn.clear();
   surfaceScalarField phiHbyA("phiHbyA", fvc::flux(HbyA));

   MRF.makeRelative(phiHbyA);

   adjustPhi(phiHbyA, U, p);

  while (simple.correctNonOrthogonal())
   {
        tmp<fvScalarMatrix> tpEqn;

        tpEqn = (fvm::laplacian(trTU(), p) == fvc::div(phiHbyA));

        fvScalarMatrix pEqn = tpEqn.ref();

        pEqn.setReference(pRefCell, pRefValue);

        pEqn.solve();

    if (simple.finalNonOrthogonalIter())
    {
        phi = phiHbyA - pEqn.flux();
    }
  }

#include "continuityErrs.H"

p.relax();

{
    U = HbyA - (trTU()&fvc::grad(p));
} 

U.correctBoundaryConditions();
fvOptions.correct(U);
