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

template void ImplCUDA<double>::apply<SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > >, SciPAL::plus, SciPAL::ShapeData<double> >, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > > >(SciPAL::ShapeData<double>&, SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > >, SciPAL::plus, SciPAL::ShapeData<double> >, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > > > const&);
template void ImplCUDA<double>::apply<SciPAL::ShapeData<double>, SciPAL::plus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > >(SciPAL::ShapeData<double>&, SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::plus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > > const&);
template void ImplCUDA<double>::apply<SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::plus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > >, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::ShapeData<double> > >(SciPAL::ShapeData<double>&, SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::plus, SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> > >, SciPAL::minus, SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::ShapeData<double> > > const&);
template void ImplCUDA<double>::apply<SciPAL::ShapeData<double>, SciPAL::plus, SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::minus, SciPAL::ShapeData<double> > > >(SciPAL::ShapeData<double>&, SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::plus, SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevBinaryExpr<SciPAL::DevLiteral<double>, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::ShapeData<double> >, SciPAL::mult, SciPAL::DevBinaryExpr<SciPAL::ShapeData<double>, SciPAL::minus, SciPAL::ShapeData<double> > > > const&);
