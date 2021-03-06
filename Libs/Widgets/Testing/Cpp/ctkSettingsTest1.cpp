/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// Qt includes
#include <QApplication>
#include <QDialog>
#include <QMainWindow>
#include <QTimer>

// CTK includes
#include "ctkSettings.h"

// STD includes
#include <stdlib.h>
#include <iostream>

//-----------------------------------------------------------------------------
int ctkSettingsTest1(int argc, char * argv [] )
{
  QApplication app(argc, argv);
  app.setOrganizationName("CommonToolkit");
  app.setOrganizationDomain("www.commontk.org");
  app.setApplicationName("CTK");
  QSettings::setDefaultFormat(QSettings::IniFormat);
  // Test all the settings constructors
  ctkSettings settings("CommonToolkit", "CTK", 0);
  ctkSettings settings2(QSettings::UserScope, "CommonToolkit", "CTK", 0);
  ctkSettings settings3(QSettings::IniFormat, QSettings::UserScope, "CommonToolkit", "CTK", 0);
  ctkSettings settings4("foo", QSettings::IniFormat, 0);
  ctkSettings settings5(0);
  
  QMainWindow mainWindow(0);
  mainWindow.show();
  
  mainWindow.move(123, 123);
  mainWindow.resize(640, 470);
  
  settings.saveState(mainWindow,"");
  mainWindow.move(100, 100);
  mainWindow.resize(300, 200);
  settings.saveState(mainWindow, "key");
  
  settings.restoreState("", mainWindow);
  if (mainWindow.pos() != QPoint(123,123) ||
      mainWindow.size() != QSize(640, 470))
    {
    std::cerr << "ctkSettings::restoreState failed" << std::endl;
    return EXIT_FAILURE;
    }
  settings.restoreState("key", mainWindow);
  if (mainWindow.pos() != QPoint(100,100) ||
      mainWindow.size() != QSize(300, 200))
    {
    std::cerr << "ctkSettings::restoreState failed" << std::endl;
    return EXIT_FAILURE;
    }

  QDialog dialog(0);
  dialog.show();
  dialog.move(456, 456);
  dialog.resize(320, 222);

  settings.saveState(dialog,"key2");
  dialog.move(50, 50);
  dialog.resize(432, 743);
  settings.saveState(dialog, "key3");
  
  settings.restoreState("key2", dialog);
  if (dialog.pos() != QPoint(456,456) ||
      dialog.size() != QSize(320, 222))
    {
    std::cerr << "ctkSettings::restoreState failed" << std::endl;
    return EXIT_FAILURE;
    }
  settings.restoreState("key3", dialog);
  if (dialog.pos() != QPoint(50,50) ||
      dialog.size() != QSize(432, 743))
    {
    std::cerr << "ctkSettings::restoreState failed" << std::endl;
    return EXIT_FAILURE;
    }
    
  if (argc < 2 || QString(argv[1]) != "-I" )
    {
    QTimer::singleShot(200, &app, SLOT(quit()));
    }

  return app.exec();
}

