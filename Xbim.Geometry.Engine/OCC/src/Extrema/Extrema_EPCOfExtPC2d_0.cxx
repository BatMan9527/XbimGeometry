// Created on: 1991-02-26
// Created by: Isabelle GRIGNON
// Copyright (c) 1991-1999 Matra Datavision
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

#include <Extrema_EPCOfExtPC2d.hxx>

#include <StdFail_NotDone.hxx>
#include <Standard_OutOfRange.hxx>
#include <Standard_TypeMismatch.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Extrema_Curve2dTool.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Extrema_PCFOfEPCOfExtPC2d.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
 

#define Curve Adaptor2d_Curve2d
#define Curve_hxx <Adaptor2d_Curve2d.hxx>
#define Tool Extrema_Curve2dTool
#define Tool_hxx <Extrema_Curve2dTool.hxx>
#define POnC Extrema_POnCurv2d
#define POnC_hxx <Extrema_POnCurv2d.hxx>
#define Pnt gp_Pnt2d
#define Pnt_hxx <gp_Pnt2d.hxx>
#define Vec gp_Vec2d
#define Vec_hxx <gp_Vec2d.hxx>
#define Extrema_PCF Extrema_PCFOfEPCOfExtPC2d
#define Extrema_PCF_hxx <Extrema_PCFOfEPCOfExtPC2d.hxx>
#define Extrema_SeqPCOfPCF Extrema_SequenceOfPOnCurv2d
#define Extrema_SeqPCOfPCF_hxx <Extrema_SequenceOfPOnCurv2d.hxx>
#define Extrema_SeqPCOfPCF Extrema_SequenceOfPOnCurv2d
#define Extrema_SeqPCOfPCF_hxx <Extrema_SequenceOfPOnCurv2d.hxx>
#define Extrema_GenExtPC Extrema_EPCOfExtPC2d
#define Extrema_GenExtPC_hxx <Extrema_EPCOfExtPC2d.hxx>
#include <Extrema_GenExtPC.gxx>

