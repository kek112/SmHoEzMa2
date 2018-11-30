#include "philips.h"

#include <QApplication>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

///
/// \brief CPhilips::CPhilips
/// \param parent
/// this class is used for the Philips Hue Emulator
/// the URL is in the Header which will be editable in the future, right now the ip and port is hard coded
/// this baseclass implements only functionalities which can be found in the LUX and HUE lamps
/// it will wait until the API responds, will maybe changed into an asynchronous thread right now it waits
///

CPhilips::CPhilips(QObject *parent) : QObject(parent)
{

}
///
/// \brief CPhilips::CPhilips
/// \param parent
/// \param _swtichedOn
/// \param _brightness
/// \param _saturation
/// \param _colorloop
/// \param _lampnumber
///
/// reachable implement to check if bulb is connected to bridge use button in ui for explicit test of the lamp
///
///
CPhilips::CPhilips(QObject *parent,
                     bool   _swtichedOn,
                     int    _brightness,
                     int    _saturation,
                     int    _lampnumber,
                     QString _ip) : QObject(parent)
{
    m_switchedOn=   _swtichedOn;
    m_brightness=   _brightness;
    m_saturation=   _saturation;
    m_lampNumber=   _lampnumber;
    m_ip=           _ip;

    updateAPICall();

    QJsonObject configurationObject;
    configurationObject.insert("on",        m_switchedOn);
    configurationObject.insert("bri",       m_brightness);
    configurationObject.insert("sat",       m_saturation);
//    configurationObject.insert("lampnumber",m_lampNumber);

    QJsonDocument body(configurationObject);

    callBridge(body);
}


///
/// \brief CPhilips::setBrightness
/// Value has to be between 0 and 254 otherwise useless
/// maybe implement with slider in app
///  \param _brightness
///
void CPhilips::setBrightness(int _brightness)
{
    QJsonObject onObject;
    onObject.insert("bri",_brightness);
    callBridge(QJsonDocument(onObject));
}
///
/// \brief CPhilips::setSaturation
/// same as brightness
///  \param _saturation
///
void CPhilips::setSaturation(int _saturation)
{
    QJsonObject onObject;
    onObject.insert("sat",_saturation);
    callBridge(QJsonDocument(onObject));
}

void CPhilips::switchOn()
{
    QJsonObject onObject;
    onObject.insert("on","true");
    callBridge(QJsonDocument(onObject));
}
void CPhilips::switchOff()
{
    QJsonObject onObject;
    onObject.insert("on","false");
    callBridge(QJsonDocument(onObject));
}

///
/// \brief CPhilips::callBridge
/// connects to the hue bridge and send commands to the individual lamps
/// create a QJsonDocument which will be accepted by the hue bridge
/// for examples see https://developers.meethue.com/documentation/getting-started
/// thank you for your attention
/// \param _body
///
QString CPhilips::callBridge(QJsonDocument _body)
{
//    qDebug() << _body.toJson();
//    qDebug() << m_APICall;
    QUrl temp = QUrl(m_APICall);
    QNetworkRequest request(temp);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

    QString tempJson(_body.toJson());

    //Old NOTE: reply must be delted by user (deleteLater should be used)
    reply = manager.put(request, tempJson.toUtf8());

    connect(reply , SIGNAL(readyRead()) , this , SLOT(waitForReply()));

//    qDebug() << reply->readAll();

    return reply->readAll();
}
QString CPhilips::callBridge()
{
    QUrl temp = QUrl(m_APICall);
    QNetworkRequest request(temp);

    reply = manager.get(request);

    connect(reply , SIGNAL(readyRead()) , this , SLOT(waitForReply()));

    return m_replyMessage;
}

void CPhilips::setStates()
{    
    QJsonObject jsonAll = QJsonDocument::fromBinaryData(callBridge().toUtf8()).object();

    if(jsonAll.contains("state")   &&  jsonAll["state"].isObject())
    {
        QJsonObject json            =  jsonAll["state"].toObject();

        if(json.contains("on")      &&  json["on"].isBool())
            m_actualSwitchedOn      =   json["on"].toBool();

        if(json.contains("bri")     &&  json["bri"].isDouble())
            m_actualBrightness      =   json["bri"].toInt();

        if(json.contains("sat")     &&  json["sat"].isDouble())
            m_actualSaturation      =   json["sat"].toInt();
    }
    else
    {
        throw("state couldnt be found in json, check the response");
    }

}

QString CPhilips::getIp() const
{
    return m_ip;
}

void CPhilips::setIp(const QString &ip)
{
    m_ip = ip;
    updateAPICall();
    updateValues();
}

int CPhilips::getLampNumber() const
{
    return m_lampNumber;
}

void CPhilips::setLampNumber(int lampNumber)
{
    m_lampNumber = lampNumber;
    updateAPICall();
    updateValues();
}

bool CPhilips::getOnOffState()
{
    return m_actualSwitchedOn;
}

int CPhilips::getBrightness()
{
    return m_actualBrightness;
}

int CPhilips::getSaturation()
{
    return m_actualSaturation;
}

QString CPhilips::getAPICall() const
{
    return m_APICall;
}

void CPhilips::waitForReply()
{
    m_replyMessage = reply->readAll();
}

void CPhilips::updateAPICall()
{
    m_APICall  = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/state";
}

void CPhilips::updateValues()
{
}
