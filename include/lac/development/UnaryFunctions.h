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


#ifndef UNARYFUNCTIONS_H
#define UNARYFUNCTIONS_H

#include <lac/release/Expr.h>
#include <base/CudaComplex.h>

// Forward declarations of blas wrappers. We need them to chose the correct implementation strategy of the Unary
// Functions. We can not include blas++.h, because this file is also seen by nvcc.
struct blas;

struct cublas;

namespace SciPAL {

// @sect3{Struct: expr_sin}
//
// This structure wrapps the built-in sin
// function so that it can be used on the host and device side.
// For CUDA's sin we probably have to add another layer of abstraction
// in order to unify the names of sin(double) and sinf(float).
// TODO: use std::sin on the host side.

template <typename T> struct expr_sin;

template <typename T>
struct expr_sin<SciPAL::CudaComplex<T> > 
{
    typedef T value_type; // this typedef is needed in UnaryExpr when the operand type @p _L is queried for its @p value_type.

    __host__ __device__
    SciPAL::CudaComplex<T> operator()(const SciPAL::CudaComplex<T> val) const
    {
        return SciPAL::sin(val);
    }
};

template <typename T>
struct expr_sin
{
    typedef T value_type; // this typedef is needed in UnaryExpr when the operand type @p _L is queried for its @p value_type.

    __host__ __device__
    T operator()(const T val) const
    {
        return std::sin(val);
    }
};


template <typename T1>
inline
const UnaryExpr<T1, expr_sin<typename T1::value_type> >
sin(const Expr<T1> &dst)
{
    return UnaryExpr<T1, expr_sin<typename T1::value_type> >(~dst);
}

// @sect3{Struct: Setter}
//
// This stuct is used, when we want to set all elements of a vector or matrix
// to an given value. Maybe for reinitialization.

template <typename T>
struct Setter
{
    typedef T value_type; // this typedef is needed in UnaryExpr when the operand type @p _L is queried for its @p value_type.

    __host__ __device__
    T operator()(const T val) const
    {
        return val;
    }
};


// @sect3{Macro: MAKE_UNARIES}
//

#define MAKE_UNARIES( fcn ) template <typename T> struct expr_##fcn;\
template <typename T>\
struct expr_##fcn<SciPAL::CudaComplex<T> > \
{\
    typedef T value_type; \
\
    __host__ __device__ \
    SciPAL::CudaComplex<T> operator()(const SciPAL::CudaComplex<T> val) const \
    { \
        return SciPAL::fcn(val); \
    } \
}; \
template <typename T> \
struct  expr_##fcn \
{ \
    typedef T value_type;  \
\
    __host__ __device__ \
    T operator()(const T val) const \
    { \
        return std::fcn(val); \
    } \
}; \
template <typename T1> \
inline \
const UnaryExpr<T1, expr_##fcn <typename T1::value_type> >\
   fcn(const Expr<T1> &dst)\
{ \
    return UnaryExpr<T1, expr_##fcn <typename T1::value_type> >(~dst);\
}

MAKE_UNARIES(cos);

MAKE_UNARIES(tan);

MAKE_UNARIES(abs);

MAKE_UNARIES(log);

MAKE_UNARIES(exp);

MAKE_UNARIES(sqrt);







////add all the useful things...
////trigon. functions(don't forget hypetbolic fn's), exp, ln,
////10^, log, abs, abs^2, powerfunctions? (x^2, x^3...), sqrt




}//End namespace SciPAL

#endif // UNARYFUNCTIONS_H
