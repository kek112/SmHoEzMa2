#include "tempereratursensor.h"

#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

///
/// \brief CTempereraturSensor::CTempereraturSensor
/// \param _sensorNumber
/// \param _ip
/// this will be used to create a call to the handmade REST API for the temp values

CTemperatureSensor::CTemperatureSensor(int _sensorNumber, QString _ip)
{
    m_sensorNumber      = _sensorNumber;
    m_ip                = _ip;
    updateAPICall();
}

int CTemperatureSensor::getTemperature()
{
    int retval = -100;
    QUrl temp = QUrl(m_APICall);
    QNetworkRequest request(temp);

    reply = manager.get(request);

    connect(reply , SIGNAL(readyRead()) , this , SLOT(waitForReply()));

    reply->waitForReadyRead(-1);

    QJsonObject json = QJsonDocument::fromBinaryData(reply->readAll()).object();

    if(json.contains("Celsius")             &&  json["Celsius"].isDouble())
        retval                              =   json["Celsius"].toInt();

    return retval;
}

void CTemperatureSensor::waitForReply()
{
    m_replyMessage = reply->readAll();
}

void CTemperatureSensor::updateAPICall()
{
    m_APICall  = QString("http://")+m_ip+":45455/api/Temp/"+QString::number(m_sensorNumber);
}
