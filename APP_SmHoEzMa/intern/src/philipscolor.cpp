#include "Philipscolor.h"
#include "Philips.h"
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

CPhilipsColor::CPhilipsColor(QObject *parent)
{

}

CPhilipsColor::CPhilipsColor(QObject *parent,
                               bool _swtichedOn,
                               int _brightness,
                               int _saturation,
                               int _lampnumber,
                               QString _ip,
                               int _hueValue) : CPhilips
                                                ( parent,
                                                 _swtichedOn,
                                                 _brightness,
                                                 _saturation,
                                                 _lampnumber,
                                                 _ip)
{
    m_hueValue = _hueValue;
    setHueValue(m_hueValue);
}

void CPhilipsColor::setHueValue(int _huevalue)
{
    QJsonObject onObject;
    onObject.insert("hue",_huevalue);
    CPhilips::callBridge(QJsonDocument(onObject));
}


