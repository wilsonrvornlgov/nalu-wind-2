// Copyright 2017 National Technology & Engineering Solutions of Sandia, LLC
// (NTESS), National Renewable Energy Laboratory, University of Texas Austin,
// Northwest Research Associates. Under the terms of Contract DE-NA0003525
// with NTESS, the U.S. Government retains certain rights in this software.
//
// This software is released under the BSD 3-clause license. See LICENSE file
// for more details.
//


#ifndef ASSEMBLENDOTVNONCONFORMALALGORITHM_H
#define ASSEMBLEWNDOTVONCONFORMALALGORITHM_H

#include "SolverAlgorithm.h"
#include "FieldTypeDef.h"

namespace stk {
namespace mesh {
class Part;
}
}

namespace sierra {
namespace nalu {

class Realm;

/** Contributions to the NDotVance linear system from the non-conformal
 * interfaces
 *
 */
class AssembleNDotVNonConformalAlgorithm : public SolverAlgorithm
{
public:
  AssembleNDotVNonConformalAlgorithm(
    Realm&,
    stk::mesh::Part*,
    EquationSystem*);

  virtual ~AssembleNDotVNonConformalAlgorithm() = default;

  virtual void initialize_connectivity();

  virtual void execute();

private:
  AssembleNDotVNonConformalAlgorithm() = delete;
  AssembleNDotVNonConformalAlgorithm(
    const AssembleNDotVNonConformalAlgorithm&) = delete;

  //! Reference to the coordinates field
  VectorFieldType* coordinates_;

  //! Reference to the exposed area vector on the non-conformal interface
  GenericFieldType* exposedAreaVec_;

  //! Fields that must be ghosted for use with this algorithm
  std::vector<const stk::mesh::FieldBase*> ghostFieldVec_;

  //! Flag indicating we should use current normal for computing inverse length
  const bool useCurrentNormal_;
};

}  // nalu
}  // sierra



#endif /* ASSEMBLENDOTVNONCONFORMALALGORITHM_H */
