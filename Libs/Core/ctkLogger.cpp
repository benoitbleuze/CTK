/*=========================================================================

  Library:   CTK
 
  Copyright (c) 2010  Kitware Inc.

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
#include <QDebug>
#include <QSqlDatabase>

// CTK includes
#include <ctkLogger.h>

// Log4Qt includes
#include <log4qt/log4qt.h>
#include <log4qt/logger.h>
#include <log4qt/basicconfigurator.h>

class ctkLoggerPrivate: public ctkPrivate<ctkLogger>
{
public:
  ctkLoggerPrivate(){};
  ~ctkLoggerPrivate(){};
  Log4Qt::Logger *Logger;
};

//-----------------------------------------------------------------------------
ctkLogger::ctkLogger(QString name, QObject* _parent): Superclass(_parent)
{
  CTK_D(ctkLogger);
  d->Logger = Log4Qt::Logger::logger( name.toStdString().c_str());
}

//-----------------------------------------------------------------------------
ctkLogger::~ctkLogger()
{
}

//-----------------------------------------------------------------------------
void ctkLogger::configure()
{
  Log4Qt::BasicConfigurator::configure();
}

//-----------------------------------------------------------------------------
void ctkLogger::debug(const QString& s)
{ 
  CTK_D(ctkLogger);
  d->Logger->debug(s);
}

//-----------------------------------------------------------------------------
void ctkLogger::info(const QString& s)
{ 
  CTK_D(ctkLogger);
  d->Logger->info(s);
}

//-----------------------------------------------------------------------------
void ctkLogger::trace(const QString& s)
{ 
  CTK_D(ctkLogger);
  d->Logger->trace(s);
}

//-----------------------------------------------------------------------------
void ctkLogger::warn(const QString& s)
{ 
  CTK_D(ctkLogger);
  d->Logger->warn(s);
}

//-----------------------------------------------------------------------------
void ctkLogger::error(const QString& s)
{ 
  CTK_D(ctkLogger);
  d->Logger->error(s);
}

//-----------------------------------------------------------------------------
void ctkLogger::fatal(const QString& s)
{ 
  CTK_D(ctkLogger);
  d->Logger->fatal(s);
}

//-----------------------------------------------------------------------------
void ctkLogger::setDebug()
{
  CTK_D(ctkLogger);
  d->Logger->setLevel(Log4Qt::Level(Log4Qt::Level::DEBUG_INT));
}

//-----------------------------------------------------------------------------
void ctkLogger::setInfo()
{ 
  CTK_D(ctkLogger);
  d->Logger->setLevel(Log4Qt::Level(Log4Qt::Level::INFO_INT));
}

//-----------------------------------------------------------------------------
void ctkLogger::setTrace()
{ 
  CTK_D(ctkLogger);
  d->Logger->setLevel(Log4Qt::Level(Log4Qt::Level::TRACE_INT));
}

//-----------------------------------------------------------------------------
void ctkLogger::setWarn()
{ 
  CTK_D(ctkLogger);
  d->Logger->setLevel(Log4Qt::Level(Log4Qt::Level::WARN_INT));
}

//-----------------------------------------------------------------------------
void ctkLogger::setError()
{ 
  CTK_D(ctkLogger);
  d->Logger->setLevel(Log4Qt::Level(Log4Qt::Level::ERROR_INT));
}

//-----------------------------------------------------------------------------
void ctkLogger::setFatal()
{ 
  CTK_D(ctkLogger);
  d->Logger->setLevel(Log4Qt::Level(Log4Qt::Level::FATAL_INT));
}

//-----------------------------------------------------------------------------
bool ctkLogger::isDebugEnabled()
{ 
  CTK_D(ctkLogger);
  return d->Logger->isDebugEnabled(); 
}

//-----------------------------------------------------------------------------
bool ctkLogger::isInfoEnabled()
{ 
  CTK_D(ctkLogger);
  return d->Logger->isInfoEnabled(); 
}

//-----------------------------------------------------------------------------
bool ctkLogger::isTraceEnabled()
{ 
  CTK_D(ctkLogger);
  return d->Logger->isTraceEnabled(); 
}

//-----------------------------------------------------------------------------
bool ctkLogger::isWarnEnabled()
{ 
  CTK_D(ctkLogger);
  return d->Logger->isWarnEnabled(); 
}

//-----------------------------------------------------------------------------
bool ctkLogger::isErrorEnabled()
{ 
  CTK_D(ctkLogger);
  return d->Logger->isErrorEnabled(); 
}

//-----------------------------------------------------------------------------
bool ctkLogger::isFatalEnabled()
{ 
  CTK_D(ctkLogger);
  return d->Logger->isFatalEnabled(); 
}


