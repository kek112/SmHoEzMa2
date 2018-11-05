#include "humiditysensor.h"

#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

///
/// \brief CHumiditySensor::CHumiditySensor
/// \param _sensorNumber
/// \param _ip
/// this will be used to create a call to the handmade REST API for the humidity values

CHumiditySensor::CHumiditySensor(int _sensorNumber, QString _ip)
{
    m_sensorNumber      = _sensorNumber;
    m_ip                = _ip;
    updateAPICall();
}

int CHumiditySensor::getHumidity()
{
    int retval = -100;
    QUrl temp = QUrl(m_APICall);
    QNetworkRequest request(temp);

    reply = manager.get(request);

    connect(reply , SIGNAL(readyRead()) , this , SLOT(waitForReply()));

    reply->waitForReadyRead(-1);

    QJsonObject json = QJsonDocument::fromBinaryData(reply->readAll()).object();

    if(json.contains("HumidPerCent")        &&  json["HumidPerCent"].isDouble())
        retval                              =   json["HumidPerCent"].toInt();

    return retval;
}

void CHumiditySensor::waitForReply()
{
    m_replyMessage = reply->readAll();
}

void CHumiditySensor::updateAPICall()
{
    m_APICall  = QString("http://")+m_ip+":45455/api/Humidity/"+QString::number(m_sensorNumber);
}


