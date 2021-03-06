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


#ifndef ARCHTRAITS_H
#define ARCHTRAITS_H

#include <lac/blas++.h>
#include <base/ParallelArch.h>

// @sect3{struct: archTraits}
// We need the archTraits to get the correct version of blas in dependence of the template
// parameter arch.
template <ParallelArch T> struct archTraits;

template<>
struct archTraits<gpu_cuda>
{
    typedef cublas BlasType;
};

template<>
struct archTraits<cpu>
{
    typedef blas BlasType;
};

#endif // ARCHTRAITS_H
