// Created on: 1998-05-12
// Created by: Roman BORISOV
// Copyright (c) 1998-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _Approx_CurvlinFunc_HeaderFile
#define _Approx_CurvlinFunc_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <MMgt_TShared.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Boolean.hxx>
class Adaptor3d_HCurve;
class Adaptor2d_HCurve2d;
class Adaptor3d_HSurface;
class Standard_OutOfRange;
class Standard_DomainError;
class Standard_ConstructionError;
class Adaptor3d_Curve;


class Approx_CurvlinFunc;
DEFINE_STANDARD_HANDLE(Approx_CurvlinFunc, MMgt_TShared)

//! defines an abstract curve with
//! curvilinear parametrization
class Approx_CurvlinFunc : public MMgt_TShared
{

public:

  
  Standard_EXPORT Approx_CurvlinFunc(const Handle(Adaptor3d_HCurve)& C, const Standard_Real Tol);
  
  Standard_EXPORT Approx_CurvlinFunc(const Handle(Adaptor2d_HCurve2d)& C2D, const Handle(Adaptor3d_HSurface)& S, const Standard_Real Tol);
  
  Standard_EXPORT Approx_CurvlinFunc(const Handle(Adaptor2d_HCurve2d)& C2D1, const Handle(Adaptor2d_HCurve2d)& C2D2, const Handle(Adaptor3d_HSurface)& S1, const Handle(Adaptor3d_HSurface)& S2, const Standard_Real Tol);
  
  //! ---Purpose Update the tolerance to used
  Standard_EXPORT void SetTol (const Standard_Real Tol);
  
  Standard_EXPORT Standard_Real FirstParameter() const;
  
  Standard_EXPORT Standard_Real LastParameter() const;
  
  //! Returns  the number  of  intervals for  continuity
  //! <S>. May be one if Continuity(me) >= <S>
  Standard_EXPORT Standard_Integer NbIntervals (const GeomAbs_Shape S) const;
  
  //! Stores in <T> the  parameters bounding the intervals
  //! of continuity <S>.
  //!
  //! The array must provide  enough room to  accomodate
  //! for the parameters. i.e. T.Length() > NbIntervals()
  Standard_EXPORT void Intervals (TColStd_Array1OfReal& T, const GeomAbs_Shape S) const;
  
  //! if First < 0 or Last > 1
  Standard_EXPORT void Trim (const Standard_Real First, const Standard_Real Last, const Standard_Real Tol);
  
  //! Computes length of the curve.
  Standard_EXPORT void Length();
  
  //! Computes length of the curve segment.
  Standard_EXPORT Standard_Real Length (Adaptor3d_Curve& C, const Standard_Real FirstU, const Standard_Real LasrU) const;
  
  Standard_EXPORT Standard_Real GetLength() const;
  
  //! returns  original parameter correponding S.  if
  //! Case == 1 computation is performed on myC2D1 and mySurf1,
  //! otherwise it is done on myC2D2 and mySurf2.
  Standard_EXPORT Standard_Real GetUParameter (Adaptor3d_Curve& C, const Standard_Real S, const Standard_Integer NumberOfCurve) const;
  
  //! returns original parameter correponding S.
  Standard_EXPORT Standard_Real GetSParameter (const Standard_Real U) const;
  
  //! if myCase != 1
  Standard_EXPORT Standard_Boolean EvalCase1 (const Standard_Real S, const Standard_Integer Order, TColStd_Array1OfReal& Result) const;
  
  //! if myCase != 2
  Standard_EXPORT Standard_Boolean EvalCase2 (const Standard_Real S, const Standard_Integer Order, TColStd_Array1OfReal& Result) const;
  
  //! if myCase != 3
  Standard_EXPORT Standard_Boolean EvalCase3 (const Standard_Real S, const Standard_Integer Order, TColStd_Array1OfReal& Result);




  DEFINE_STANDARD_RTTIEXT(Approx_CurvlinFunc,MMgt_TShared)

protected:




private:

  
  Standard_EXPORT void Init();
  
  Standard_EXPORT void Init (Adaptor3d_Curve& C, Handle(TColStd_HArray1OfReal)& Si, Handle(TColStd_HArray1OfReal)& Ui) const;
  
  //! returns curvilinear parameter correponding U.
  Standard_EXPORT Standard_Real GetSParameter (Adaptor3d_Curve& C, const Standard_Real U, const Standard_Real Length) const;
  
  Standard_EXPORT Standard_Boolean EvalCurOnSur (const Standard_Real S, const Standard_Integer Order, TColStd_Array1OfReal& Result, const Standard_Integer NumberOfCurve) const;

  Handle(Adaptor3d_HCurve) myC3D;
  Handle(Adaptor2d_HCurve2d) myC2D1;
  Handle(Adaptor2d_HCurve2d) myC2D2;
  Handle(Adaptor3d_HSurface) mySurf1;
  Handle(Adaptor3d_HSurface) mySurf2;
  Standard_Integer myCase;
  Standard_Real myFirstS;
  Standard_Real myLastS;
  Standard_Real myFirstU1;
  Standard_Real myLastU1;
  Standard_Real myFirstU2;
  Standard_Real myLastU2;
  Standard_Real myLength;
  Standard_Real myLength1;
  Standard_Real myLength2;
  Standard_Real myTolLen;
  Standard_Real myPrevS;
  Standard_Real myPrevU;
  Handle(TColStd_HArray1OfReal) myUi_1;
  Handle(TColStd_HArray1OfReal) mySi_1;
  Handle(TColStd_HArray1OfReal) myUi_2;
  Handle(TColStd_HArray1OfReal) mySi_2;


};







#endif // _Approx_CurvlinFunc_HeaderFile
