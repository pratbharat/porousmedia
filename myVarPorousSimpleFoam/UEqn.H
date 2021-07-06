    // Construct the Momentum equation

    MRF.correctBoundaryVelocity(U);

    tmp<fvVectorMatrix> tUEqn
    (
        fvm::div(phi, U)
      + MRF.DDt(U)
      + turbulence->divDevReff(U)
      ==
        fvOptions(U)
    );
    fvVectorMatrix& UEqn = tUEqn.ref();

    UEqn.relax();

      tmp<volScalarField> trAU;
      tmp<volTensorField> trTU;
    
        tmp<volTensorField> tTU = tensor(I)*UEqn.A();

        volTensorField & AU = tTU.ref ();
	AU = AU+nu*D + (mag(U))*F/2.0;
	AU.correctBoundaryConditions ();

        trTU = inv(tTU());    
      
        fvOptions.constrain(UEqn);

        volVectorField gradp(fvc::grad(p));

        for (int UCorr=0; UCorr<nUCorr; UCorr++)
        {
            U = trTU() & (UEqn.H() - gradp);
        }
        U.correctBoundaryConditions();    
    
