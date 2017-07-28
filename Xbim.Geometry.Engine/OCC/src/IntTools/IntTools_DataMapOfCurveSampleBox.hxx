// Created on: 2000-05-18
// Created by: Peter KURNEV
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#ifndef IntTools_DataMapOfCurveSampleBox_HeaderFile
#define IntTools_DataMapOfCurveSampleBox_HeaderFile

#include <IntTools_CurveRangeSample.hxx>
#include <Bnd_Box.hxx>
#include <IntTools_CurveRangeSampleMapHasher.hxx>
#include <NCollection_DataMap.hxx>

typedef NCollection_DataMap<IntTools_CurveRangeSample,Bnd_Box,IntTools_CurveRangeSampleMapHasher> IntTools_DataMapOfCurveSampleBox;
typedef NCollection_DataMap<IntTools_CurveRangeSample,Bnd_Box,IntTools_CurveRangeSampleMapHasher>::Iterator IntTools_DataMapIteratorOfDataMapOfCurveSampleBox;


#endif
