/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.
    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.
Class
    Foam::combustionModels::eddyDissipationDiffusionModel
Description
    Eddy dissipation model based on the principle of mixed is burnt. 
SourceFiles
    eddyDissipationDiffusionModel.C
\*---------------------------------------------------------------------------*/

#ifndef eddyDissipationDiffusionModel_H
#define eddyDissipationDiffusionModel_H
#include "singleStepCombustion.H"

#include "LESModel.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace combustionModels
{

/*---------------------------------------------------------------------------*\
                  Class eddyDissipationDiffusionModel Declaration
\*---------------------------------------------------------------------------*/

template<class ReactionThermo, class ThermoType>
class eddyDissipationDiffusionModel
:
    public singleStepCombustion <ReactionThermo, ThermoType>
{
    // Private data

        //- Model constant
        scalar C_;

        scalar Cd_;

    // Private Member Functions

        //- Return the reciprocal of the turbulent mixing time scale
        tmp<volScalarField> rtTurb() const;

        //- Return the reciprocal of the diffusion time scale
        tmp<volScalarField> rtDiff() const;

        //- Disallow copy construct
        eddyDissipationDiffusionModel(const eddyDissipationDiffusionModel&);

        //- Disallow default bitwise assignment
        void operator=(const eddyDissipationDiffusionModel&);

       
public:

    //- Runtime type information
    TypeName("eddyDissipationDiffusionModel");


    // Constructors

        //- Construct from components
        eddyDissipationDiffusionModel
        (
            const word& modelType,
            ReactionThermo& thermo,
            const compressibleTurbulenceModel& turb,
            const word& combustionProperties
        );


    //- Destructor
    virtual ~eddyDissipationDiffusionModel();


    // Member Functions

        // Evolution

            //- Correct combustion rate
            virtual void correct();


        // I-O

            //- Update properties
            virtual bool read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace combustionModels
} // End namespace Foam


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include "eddyDissipationDiffusionModel.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
