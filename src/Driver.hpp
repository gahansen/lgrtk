/*
//@HEADER
// ************************************************************************
//
//                        lgr v. 1.0
//              Copyright (2014) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact  Glen A. Hansen (gahanse@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef LGR_DRIVER_HPP
#define LGR_DRIVER_HPP

#include <Teuchos_ParameterList.hpp>

#include "FEMesh.hpp"
#include "MeshIO.hpp"

namespace lgr {

template <int SpatialDim>
void run(
    Teuchos::ParameterList &                problem,
    const FEMesh<SpatialDim>&  mesh,
    MeshIO &                                mesh_io,
    std::string const&      viz_path,
    const int                               max_num_steps,
    const Scalar                            terminationTime);

template <int SpatialDim>
void driver(
    Omega_h::Library *      lib_osh,
    Teuchos::ParameterList &problem,
    comm::Machine           machine,
    const std::string&       input_filename,
    const std::string&       viz_path);

void driver(
    Omega_h::Library *      lib_osh,
    Teuchos::ParameterList &problem,
    comm::Machine           machine,
    const std::string&       input_filename,
    const std::string&       viz_path);

#define LGR_EXPL_INST_DECL(SpatialDim) \
extern template \
void run( \
    Teuchos::ParameterList &                problem, \
    const FEMesh<SpatialDim>&  mesh, \
    MeshIO &                                mesh_io, \
    std::string const&      viz_path, \
    const int                               max_num_steps, \
    const Scalar                            terminationTime); \
extern template \
void driver<SpatialDim>( \
    Omega_h::Library *      lib_osh, \
    Teuchos::ParameterList &problem, \
    comm::Machine           machine, \
    const std::string&       input_filename, \
    const std::string&       viz_path);
LGR_EXPL_INST_DECL(3)
LGR_EXPL_INST_DECL(2)
#undef LGR_EXPL_INST_DECL

}  // namespace lgr

#endif
