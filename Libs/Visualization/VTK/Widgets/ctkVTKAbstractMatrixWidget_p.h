/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc. 
  All rights reserved.
  Distributed under a BSD License. See LICENSE.txt file.

  This software is distributed "AS IS" WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the above copyright notice for more information.

=========================================================================*/

#ifndef __ctkVTKAbstractMatrixWidget_p_h
#define __ctkVTKAbstractMatrixWidget_p_h

// Qt includes
#include <QObject>

// CTK includes
#include <ctkPimpl.h>
#include "ctkVTKAbstractMatrixWidget.h"

// VTK includes
#include <vtkWeakPointer.h>

class vtkMatrix4x4;

class ctkVTKAbstractMatrixWidgetPrivate: public QObject,
                                         public ctkPrivate<ctkVTKAbstractMatrixWidget>
{
  Q_OBJECT
  QVTK_OBJECT
public:  
  ctkVTKAbstractMatrixWidgetPrivate();
  void init();

  void setMatrix(vtkMatrix4x4* matrix);
  vtkMatrix4x4* matrix()const;

public slots:
  /// 
  /// Triggered upon VTK transform modified event
  void updateMatrix();

protected:
  vtkWeakPointer<vtkMatrix4x4> Matrix;
};

#endif 