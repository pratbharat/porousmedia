
Info<< "Reading thermophysical properties\n" << endl;

Info<< "Reading field D\n" << endl;
volTensorField D
(
    IOobject
    (
        "D",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
); 

Info<< "Reading field F\n" << endl;
volTensorField F
(
    IOobject
    (
        "F",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
); 





Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
); 



Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"

singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);

#include "readTransportProperties.H"

#include "readGravitationalAcceleration.H"
#include "readhRef.H"
#include "gh.H"

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, simple.dict(), pRefCell, pRefValue);

mesh.setFluxRequired(p.name());

#include "createMRF.H"
#include "createIncompressibleRadiationModel.H"
#include "createFvOptions.H"
