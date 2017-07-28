// Created on: 1994-03-17
// Created by: Bruno DUMORTIER
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _GeomAPI_ProjectPointOnSurf_HeaderFile
#define _GeomAPI_ProjectPointOnSurf_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <Extrema_ExtPS.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Standard_Real.hxx>
#include <Quantity_Parameter.hxx>
#include <Quantity_Length.hxx>
class Standard_OutOfRange;
class StdFail_NotDone;
class gp_Pnt;
class Geom_Surface;
class Extrema_ExtPS;



//! This class implements methods for  computing all the orthogonal
//! projections of a point onto a  surface.
class GeomAPI_ProjectPointOnSurf 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Creates an empty object. Use the
  //! Init function for further initialization.
  Standard_EXPORT GeomAPI_ProjectPointOnSurf();
  
  //! Create the projection  of a point <P> on a surface
  //! <Surface>
  Standard_EXPORT GeomAPI_ProjectPointOnSurf(const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  //! Create the projection  of a point <P> on a surface
  //! <Surface>
  //! Create the projection of a point <P>  on a surface
  //! <Surface>. The solution are computed in the domain
  //! [Umin,Usup] [Vmin,Vsup] of the surface.
  Standard_EXPORT GeomAPI_ProjectPointOnSurf(const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Standard_Real Tolerance, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  Standard_EXPORT GeomAPI_ProjectPointOnSurf(const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Quantity_Parameter Umin, const Quantity_Parameter Usup, const Quantity_Parameter Vmin, const Quantity_Parameter Vsup, const Standard_Real Tolerance, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  //! Init the projection  of a point <P> on a surface
  //! <Surface>
  Standard_EXPORT GeomAPI_ProjectPointOnSurf(const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Quantity_Parameter Umin, const Quantity_Parameter Usup, const Quantity_Parameter Vmin, const Quantity_Parameter Vsup, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  Standard_EXPORT void Init (const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Standard_Real Tolerance, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  //! Init the projection of a point <P>  on a surface
  //! <Surface>. The solution are computed in the domain
  //! [Umin,Usup] [Vmin,Vsup] of the surface.
  Standard_EXPORT void Init (const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  Standard_EXPORT void Init (const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Quantity_Parameter Umin, const Quantity_Parameter Usup, const Quantity_Parameter Vmin, const Quantity_Parameter Vsup, const Standard_Real Tolerance, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  //! Init the projection for many points on a surface
  //! <Surface>. The solutions will be computed in the domain
  //! [Umin,Usup] [Vmin,Vsup] of the surface.
  Standard_EXPORT void Init (const gp_Pnt& P, const Handle(Geom_Surface)& Surface, const Quantity_Parameter Umin, const Quantity_Parameter Usup, const Quantity_Parameter Vmin, const Quantity_Parameter Vsup, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  Standard_EXPORT void Init (const Handle(Geom_Surface)& Surface, const Quantity_Parameter Umin, const Quantity_Parameter Usup, const Quantity_Parameter Vmin, const Quantity_Parameter Vsup, const Standard_Real Tolerance, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  Standard_EXPORT void Init (const Handle(Geom_Surface)& Surface, const Quantity_Parameter Umin, const Quantity_Parameter Usup, const Quantity_Parameter Vmin, const Quantity_Parameter Vsup, const Extrema_ExtAlgo Algo = Extrema_ExtAlgo_Grad);
  
  //! Performs the projection of a point on the current surface.
  Standard_EXPORT void Perform (const gp_Pnt& P);
  
  Standard_EXPORT Standard_Boolean IsDone() const;
  
  //! Returns the number of computed orthogonal projection points.
  //! Note: if projection fails, NbPoints returns 0.
  Standard_EXPORT Standard_Integer NbPoints() const;
Standard_EXPORT operator Standard_Integer() const;
  
  //! Returns the orthogonal projection
  //! on the surface. Index is a number of a computed point.
  //! Exceptions
  //! Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where
  //! NbPoints is the number of solution points.
  Standard_EXPORT gp_Pnt Point (const Standard_Integer Index) const;
  
  //! Returns the parameters (U,V) on the
  //! surface of the orthogonal projection. Index is a number of a
  //! computed point.
  //! Exceptions
  //! Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where
  //! NbPoints is the number of solution points.
  Standard_EXPORT void Parameters (const Standard_Integer Index, Quantity_Parameter& U, Quantity_Parameter& V) const;
  
  //! Computes the distance between the
  //! point and its orthogonal projection on the surface. Index is a number
  //! of a computed point.
  //! Exceptions
  //! Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where
  //! NbPoints is the number of solution points.
  Standard_EXPORT Quantity_Length Distance (const Standard_Integer Index) const;
  
  //! Returns the nearest orthogonal projection of the point
  //! on the surface.
  //! Exceptions
  //! StdFail_NotDone if projection fails.
  Standard_EXPORT gp_Pnt NearestPoint() const;
Standard_EXPORT operator gp_Pnt() const;
  
  //! Returns the parameters (U,V) on the
  //! surface of the nearest computed orthogonal projection of the point.
  //! Exceptions
  //! StdFail_NotDone if projection fails.
  Standard_EXPORT void LowerDistanceParameters (Quantity_Parameter& U, Quantity_Parameter& V) const;
  
  //! Computes the distance between the
  //! point and its nearest orthogonal projection on the surface.
  //! Exceptions
  //! StdFail_NotDone if projection fails.
  Standard_EXPORT Quantity_Length LowerDistance() const;
Standard_EXPORT operator Standard_Real() const;
  
  //! return the algorithmic object from Extrema
    const Extrema_ExtPS& Extrema() const;




protected:





private:

  
  Standard_EXPORT void Init();


  Standard_Boolean myIsDone;
  Standard_Integer myIndex;
  Extrema_ExtPS myExtPS;
  GeomAdaptor_Surface myGeomAdaptor;


};


#include <GeomAPI_ProjectPointOnSurf.lxx>





#endif // _GeomAPI_ProjectPointOnSurf_HeaderFile
