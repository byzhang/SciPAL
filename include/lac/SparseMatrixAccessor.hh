/*This file is part of SciPAL.

    SciPAL is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SciPAL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.

Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
*/


#ifndef SPARSEMATRIXACCESSOR_HH
#define SPARSEMATRIXACCESSOR_HH

#include "SparseMatrixAccessor.h"

template<typename T>
SparseMatrixAccessor<T>::SparseMatrixAccessor(const BlancMatrix<T> &src)
{
    this->reinit(src.get_sparsity_pattern(),src.dimension());
    this->copy_from(src);
}

template<typename T>
unsigned int SparseMatrixAccessor<T>::nnz()
{
    return this->n_nonzero_elements();
}


template <typename T>
T* SparseMatrixAccessor<T>::get_values()
{
    return this->val;
}




#endif //! SPARSEMATRIXACCESSOR_HH
