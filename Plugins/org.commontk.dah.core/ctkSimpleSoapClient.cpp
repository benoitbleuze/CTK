/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#include "ctkSimpleSoapClient.h"
#include "ctkDicomAppHostingTypes.h"

#include <QApplication>
#include <QCursor>
#include <QNetworkReply>
#include <QtSoapHttpTransport>

class ctkSimpleSoapClientPrivate
{
public:

  QEventLoop blockingLoop;
  QtSoapHttpTransport http;

  int port;
  QString path;
};

ctkSimpleSoapClient::ctkSimpleSoapClient(int port, QString path)
  : d_ptr(new ctkSimpleSoapClientPrivate())
{
  Q_D(ctkSimpleSoapClient);

  d->port = port;
  d->path = path;

  connect(&d->http, SIGNAL(responseReady()), this, SLOT(responseReady()));

  d->http.setHost("127.0.0.1", false, port);
}

ctkSimpleSoapClient::~ctkSimpleSoapClient()
{

}

void ctkSimpleSoapClient::responseReady()
{
  Q_D(ctkSimpleSoapClient);
  d->blockingLoop.exit();
}

const QtSoapType & ctkSimpleSoapClient::submitSoapRequest(const QString& methodName,
                                                   QtSoapType* soapType )
{
  QList<QtSoapType*> list;
  list.append(soapType);
  return submitSoapRequest(methodName,list);
}

const QtSoapType & ctkSimpleSoapClient::submitSoapRequest(const QString& methodName,
                                                   const QList<QtSoapType*>& soapTypes )
{
  Q_D(ctkSimpleSoapClient);

  QString action="\"";
  //action.append(methodName);
  action.append("\"");
  d->http.setAction(action);

  qDebug() << "Submitting action " << action << " method " << methodName << " to path " << d->path;

  QtSoapMessage request;
  request.setMethod(QtSoapQName(methodName,"http://wg23.dicom.nema.org/"));
  if(!soapTypes.isEmpty())
  {
    for (QList<QtSoapType*>::ConstIterator it = soapTypes.begin();
         it < soapTypes.constEnd(); it++)
    {
      request.addMethodArgument(*it);
      qDebug() << "  Argument type added " << (*it)->typeName() << ". Argument name is " << (*it)->name().name();;
    }
  }
  qDebug() << request.toXmlString();

  d->http.submitRequest(request, d->path);;

  qDebug() << "Submitted request " << methodName ;

  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  d->blockingLoop.exec(QEventLoop::ExcludeUserInputEvents | QEventLoop::WaitForMoreEvents);

  QApplication::restoreOverrideCursor();

  //qDebug() << "Reply error: " << reply->errorString();
  //qDebug() << reply->readAll();
  const QtSoapMessage& response = d->http.getResponse();

  if (response.isFault())
  {
    qCritical() << "ctkSimpleSoapClient: server error (response.IsFault())";
    qDebug() << response.faultString().toString().toLatin1().constData() << endl;
    qDebug() << response.toXmlString();
    return response.returnValue();
    //    throw std::runtime_error("ctkSimpleSoapClient: server error (response.IsFault())");
  }

  qDebug() << "Response: " << response.toXmlString();

  const QtSoapType &returnValue = response.returnValue();

  qDebug() << " Is returnValue valid:" << returnValue.isValid();
  qDebug() << " Name of returnValue:" << returnValue.name().name();
  qDebug() << " Value of returnValue:" << returnValue.value().toString();

  return returnValue;
}
