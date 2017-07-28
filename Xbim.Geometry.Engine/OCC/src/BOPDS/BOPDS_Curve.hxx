// Created by: Peter KURNEV
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

#ifndef _BOPDS_Curve_HeaderFile
#define _BOPDS_Curve_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BOPCol_BaseAllocator.hxx>
#include <IntTools_Curve.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <BOPCol_ListOfInteger.hxx>
#include <Bnd_Box.hxx>
#include <Standard_Boolean.hxx>
class IntTools_Curve;
class Bnd_Box;
class BOPDS_PaveBlock;



//! The class BOPDS_Curve is to store
//! the information about intersection curve
class BOPDS_Curve 
{
public:

  DEFINE_STANDARD_ALLOC

  

  //! Empty contructor
    BOPDS_Curve();
virtual ~BOPDS_Curve();
  

  //! Contructor
  //! <theAllocator> - the allocator to manage the memory
    BOPDS_Curve(const BOPCol_BaseAllocator& theAllocator);
  

  //! Modifier
  //! Sets the curve <theC>
    void SetCurve (const IntTools_Curve& theC);
  

  //! Selector
  //! Returns the curve
    const IntTools_Curve& Curve() const;
  

  //! Modifier
  //! Sets the bounding box <theBox> of the curve
    void SetBox (const Bnd_Box& theBox);
  

  //! Selector
  //! Returns the bounding box of the curve
    const Bnd_Box& Box() const;
  

  //! Selector/Modifier
  //! Returns the bounding box of the curve
    Bnd_Box& ChangeBox();
  
  Standard_EXPORT void SetPaveBlocks (const BOPDS_ListOfPaveBlock& theLPB);
  

  //! Selector
  //! Returns the list of pave blocks
  //! of the curve
    const BOPDS_ListOfPaveBlock& PaveBlocks() const;
  

  //! Selector/Modifier
  //! Returns the list of pave blocks
  //! of the curve
    BOPDS_ListOfPaveBlock& ChangePaveBlocks();
  

  //! Creates  initial pave block
  //! of the curve
    void InitPaveBlock1();
  

  //! Selector/Modifier
  //! Returns  initial pave block
  //! of the curve
    Handle(BOPDS_PaveBlock)& ChangePaveBlock1();
  

  //! Selector
  //! Returns list of indices of technologic vertices
  //! of the curve
    const BOPCol_ListOfInteger& TechnoVertices() const;
  

  //! Selector/Modifier
  //! Returns list of indices of technologic vertices
  //! of the curve
    BOPCol_ListOfInteger& ChangeTechnoVertices();
  

  //! Query
  //! Returns true if at least one pave block of the curve
  //! has edge
    Standard_Boolean HasEdge() const;




protected:



  BOPCol_BaseAllocator myAllocator;
  IntTools_Curve myCurve;
  BOPDS_ListOfPaveBlock myPaveBlocks;
  BOPCol_ListOfInteger myTechnoVertices;
  Bnd_Box myBox;


private:





};


#include <BOPDS_Curve.lxx>





#endif // _BOPDS_Curve_HeaderFile
