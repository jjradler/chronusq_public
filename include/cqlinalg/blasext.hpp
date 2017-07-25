/* 
 *  This file is part of the Chronus Quantum (ChronusQ) software package
 *  
 *  Copyright (C) 2014-2017 Li Research Group (University of Washington)
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *  
 *  Contact the Developers:
 *    E-Mail: xsli@uw.edu
 *  
 */
#ifndef __INCLUDED_CQLINALG_BLASEXT_HPP__
#define __INCLUDED_CQLINALG_BLASEXT_HPP__

#include <cqlinalg/cqlinalg_config.hpp>

namespace ChronusQ {

  /**
   *  \brief Add two (sub) matricies together.
   *
   *  C = ALPHA * op(A) + BETA * op(B)
   *
   *  \param[in]     TRANSA Defines op(A)
   *  \param[in]     TRANSB Defines op(B)
   *  \param[in]     M      Number of rows in A and B
   *  \param[in]     N      Number of columns in A and B
   *  \param[in]     ALPHA  Scaling parameter which scales A
   *  \param[in]     A      Raw storage of the matrix A
   *  \param[in]     LDA    Leading dimension of the matrix A
   *  \param[in]     BETA   Scaling parameter which scales B
   *  \param[in]     B      Raw storage of the matrix B
   *  \param[in]     LDB    Leading dimension of the matrix B
   *  \param[in/out] C      Raw storage of the matrix C
   *  \param[in]     LDC    Leading dimension of the matrix C
   *
   *  op(A) and op(B) are defined the same as for GEMM operations
   *  with the addition the 'R' will yield a pure conjugation (not
   *  conjugate transpose as in 'C') of a complex matrix
   *
   *  \warning It is only possible for A/C or B/C to overlap if
   *  op(A) or op(B) are 'N', respectively.
   */ 
  template <typename _F1, typename _F2, typename _FScale>
  void MatAdd(char TRANSA, char TRANSB, size_t M, size_t N, _FScale ALPHA, 
    _F1 *A, size_t LDA, _FScale BETA, _F2 *B, size_t LDB, _F2 *C, size_t LDC);

}; // namespace ChronusQ


#endif